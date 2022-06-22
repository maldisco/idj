#ifndef FACE_H
#define FACE_H

#include "Component.h"

class Face : Component{
    public:
        Face(GameObject& associated);

        ~Face();

        void Damage(int damage);

        void Update(float dt);

        void Render();

        bool Is(std::string type);
    
    private:
        int hitpoints;
};
#endif