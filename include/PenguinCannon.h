#ifndef PENGUINCANNON_H
#define PENGUINCANNON_H

#include "Component.h"

class PenguinCannon : public Component{
    public:
        PenguinCannon(GameObject& associated, std::weak_ptr<GameObject> penguinBody);
        
        void Update(float dt);
        void Render();
        bool Is(std::string type);
        void NotifyCollision(GameObject& other);

        void Shoot();
    private:
        std::weak_ptr<GameObject> pbody;
        float angle;
};
#endif