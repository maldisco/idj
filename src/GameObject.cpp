#include "GameObject.h"
#include "algorithm"
#include "Component.h"
#include "iostream"

GameObject::GameObject() : isDead(false){}

GameObject::~GameObject(){
    components.clear();
}

void GameObject::Update(float dt){
    for(int i=0; i<components.size(); i++){
        components.at(i)->Update(dt);
    }
}

void GameObject::Render(){
    for(int i=0; i<components.size(); i++){
        components.at(i)->Render();
    }
}

bool GameObject::IsDead(){
    return isDead;
}

void GameObject::RequestDelete(){
    isDead = true;
}

void GameObject::AddComponent(Component* cpt){
    components.emplace_back(cpt);
}

void GameObject::RemoveComponent(Component* cpt){
    // iterate through components
    for(int i=0; i<components.size(); i++){
        // find the one thats equal to argument
        if(components[i].get() == cpt){
            // erase it
            components.erase(components.begin()+i);
        }
    }
}

Component* GameObject::GetComponent(std::string type){
    // iterate through components
    for(int i=0; i<components.size(); i++){
        // if type (string like 'Sound' or 'Face') equals argument
        if(components.at(i)->Is(type)){
            // return it
            return components.at(i).get();
        }
    }

    return nullptr;
}