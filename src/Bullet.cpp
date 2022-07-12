#include "Bullet.h"
#include "sprite.h"

Bullet::Bullet(GameObject& associated, float angle, float speed, int damage, float maxDistance, std::string sprite, float frameTime, int frameCount) : Component(associated),
 distanceLeft(maxDistance), damage(damage){
    associated.AddComponent(new Sprite(sprite, associated, frameCount, frameTime));

    this->speed.x = Vec2(speed, 0).Rotate(angle).x;
    this->speed.y = Vec2(speed, 0).Rotate(angle).y;
} 

void Bullet::Update(float dt){
    associated.box.x += speed.x*dt;
    associated.box.y += speed.y*dt;

    distanceLeft -= (speed*dt).Magnitude();
    if(distanceLeft <= 0){
        associated.RequestDelete();
    }
}

void Bullet::Render(){}

bool Bullet::Is(std::string type){
    if(type.compare("Bullet") == 0){
        return true;
    }

    return false;
}

int Bullet::GetDamage(){ return damage; }
