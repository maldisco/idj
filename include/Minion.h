#ifndef MINION_H
#define MINION_H

#include "Component.h"
#include "Sprite.h"

#define ARC PI/64

class Minion : public Component {
    public:
        Minion(GameObject& associated, std::weak_ptr<GameObject> alienCenter, float arcOffsetDeg = 0);

        void Update(float dt);

        void Render();

        bool Is(std::string type);

        void Shoot(Vec2 target);
    
    private:
        std::weak_ptr<GameObject> alienCenter;
        float arc;
};
#endif