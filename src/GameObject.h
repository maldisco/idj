#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "string"
#include "vector"
#include "memory"

#include "Rect.h"

// forward declaration to dodge circular dependency
class Component;

class GameObject{
    public:
        Rect box;

        GameObject();

        ~GameObject();

        void Update(float dt);

        void Render();

        bool IsDead();

        void RequestDelete();

        void AddComponent(Component* cpt);

        void RemoveComponent(Component* cpt);

        Component* GetComponent(std::string type);

    private:
        std::vector<std::unique_ptr<Component>> components;
        bool isDead;
};
#endif