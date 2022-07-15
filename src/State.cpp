#include "State.h"
#include "Sound.h"
#include "TileMap.h"
#include "Game.h"
#include "Camera.h"
#include "InputManager.h"
#include "CameraFollower.h"
#include "Alien.h"
#include "PenguinBody.h"
#include "Collision.cpp"

State::State() : music("assets/audio/stageState.ogg"), quitRequested(false), started(false){    
	// background
	GameObject* bg = new GameObject();
	bg->AddComponent(new Sprite("assets/img/ocean.jpg", *bg, 1, 1.0));
	bg->AddComponent(new CameraFollower(*bg));
	bg->box.x = 0;
	bg->box.y = 0;
	AddObject(bg);

	// tileset
    GameObject* go = new GameObject();
	TileSet* tileSet = new TileSet(*go, 64, 64, "assets/img/tileset.png");
	go->AddComponent(new TileMap(*go, "assets/map/tileMap.txt", tileSet));
	go->box.x = 0;
	go->box.y = 0;
	AddObject(go);

	// main char
	GameObject* penguin = new GameObject();
	penguin->AddComponent(new PenguinBody(*penguin));
	penguin->box.x = 704;
	penguin->box.y = 640;
	AddObject(penguin);

	// make penguin as camera focus
	Camera::Follow(penguin);
    
	// enemy
	GameObject* alien = new GameObject();
	alien->AddComponent(new Alien(*alien));
	alien->box.x = 512 - alien->box.w/2;
	alien->box.y = 300 - alien->box.h/2;
	AddObject(alien);

    music.Play();
}

State::~State(){
    objectArray.clear();
}

void State::Start(){
	LoadAssets();

	for(unsigned i = 0; i < objectArray.size(); i++){
		objectArray[i]->Start();
	}

	started = true;
}

void State::LoadAssets(){

}

void State::Update(float dt){

	// update camera
	Camera::Update(dt);

	// check if quit was requested
	if(InputManager::GetInstance().KeyPress(ESCAPE_KEY) || InputManager::GetInstance().QuitRequested()){
		quitRequested = true;
	}

	// Update every object
    for(unsigned i=0; i<objectArray.size(); i++){
        objectArray[i]->Update(dt);
    }

	// check collidable objects
	std::vector<std::weak_ptr<GameObject>> collidable = QueryObjectsBy("Collider");
	for(unsigned i=0; i<collidable.size(); i++){
		for(unsigned j=i+1; j<collidable.size(); j++){
			if(Collision::IsColliding(collidable[i].lock()->box, collidable[j].lock()->box, collidable[i].lock()->angleDeg*PI/180, collidable[j].lock()->angleDeg*PI/180)){
				GameObject* g1 = collidable[i].lock().get();
				GameObject* g2 = collidable[j].lock().get();
				g1->NotifyCollision(*g2);
				g2->NotifyCollision(*g1);
			}
		}
	}

	// Check if object is dead
    for(unsigned i=0; i<objectArray.size(); i++){
        if( objectArray[i]->IsDead() ){
            objectArray.erase(objectArray.begin()+i);
        }
    }
}

void State::Render(){
	// Render every object
    for(unsigned i=0; i<objectArray.size(); i++){
        objectArray[i]->Render();
    }
}

std::weak_ptr<GameObject> State::AddObject( GameObject* go ){
	std::shared_ptr<GameObject> sharedGo(go);
	objectArray.push_back( sharedGo );

	if(started){
		go->Start();
	}

	return std::weak_ptr<GameObject>(sharedGo);
}

std::weak_ptr<GameObject> State::GetObjectPtr( GameObject* go ){
	for(unsigned i = 0; i < objectArray.size(); i++){
		if(objectArray[i].get() == go){
			return std::weak_ptr<GameObject>(objectArray[i]);
		}
	}

	return {};
}

std::vector<std::weak_ptr<GameObject>> State::QueryObjectsBy(std::string component){
	std::vector<std::weak_ptr<GameObject>> gameObjects;
	for(unsigned i = 0; i < objectArray.size(); i++){
		if(objectArray[i]->GetComponent(component) != nullptr){
			gameObjects.push_back(objectArray[i]);
		}
	}

	return gameObjects;
}

bool State::QuitRequested()
{
    return quitRequested;
}

