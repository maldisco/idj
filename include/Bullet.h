#ifndef BULLET_H
#define BULLET_H
#include "Component.h"

/**
 * @brief Object alien shoots
 * 
 */
class Bullet : public Component{
    public:
        Bullet(GameObject& associated, float angle, float speed, int damage, float maxDistance, std::string sprite, float frameTime, int frameCount, bool targetsPlayer);
        void Update(float dt);
        void Render();
        bool Is(std::string type);
        int GetDamage();
        void NotifyCollision(GameObject& other);

        bool targetsPlayer;
    private:
        Vec2 speed;
        float distanceLeft;
        int damage;
};
#endif