#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "string"
#include "vector"
#include "memory"

#include "Rect.h"

// forward declaration to dodge circular dependency
class Component;

/**
 * @brief represents an entity
 * 
 */
class GameObject{
    public:
        Rect box;

        GameObject();

        ~GameObject();

        void Update(float dt);

        void Render();

        bool IsDead();

        // object died/destroyed
        void RequestDelete();
        
        void AddComponent(Component* cpt);

        void RemoveComponent(Component* cpt);

        Component* GetComponent(std::string type);

    private:
        // every component is a part of the entity e.g sprite, sound...
        std::vector<std::unique_ptr<Component>> components;
        bool isDead;
};
#endif