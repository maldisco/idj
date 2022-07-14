#include "Rect.h"
#include "stdlib.h"
#include "math.h"

Rect::Rect() : x(0), y(0), w(0), h(0){}
Rect::Rect(float x, float y, float w, float h) : x(x), y(y), w(w), h(h){}

Vec2 Rect::Center(){
    return Vec2(this->x + this->w/2, this->y + this->h/2);
}

void Rect::Centered(Vec2 center){
    this->x = center.x - this->w/2;
    this->y = center.y - this->h/2;
}

Rect Rect::operator+(Vec2 v2){
    return Rect(x + v2.x, y + v2.y, w, h);
}

Rect Rect::operator=(Rect rect){
    return Rect(rect.x, rect.y, rect.w, rect.h);
}

float Rect::Distance(Rect r1, Rect r2){
    return Vec2::Distance(r1.Center(), r2.Center());
}

bool Rect::Contains( Vec2 v2 ){
    if(v2.x > x && v2.x < (x + w)){
        if(v2.y > y && v2.y < (y + h)){
            return true;
        }
    }

    return false;
}