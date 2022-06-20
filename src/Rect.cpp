#include "Rect.h"
#include "stdlib.h"
#include "math.h"

Rect::Rect() : x(0), y(0), w(0), h(0){}
Rect::Rect(float x, float y, float w, float h) : x(x), y(y), w(w), h(h){}

Vec2 Rect::Center(){
    return Vec2(this->x + this->w/2, this->y + this->h/2);
}

float Rect::Distance(Rect r2){
    Vec2 centerR1 = this->Center();
    Vec2 centerR2 = r2.Center();

    float dx = abs(centerR1.x - centerR2.x);
    float dy = abs(centerR1.y - centerR2.y);

    return sqrt(dx*dx + dy*dy);
}

bool Rect::IsInside(Vec2 v2){
    if(v2.x > this->x && v2.x < (this->x + this->w)){
        if(v2.y > this->y && v2.y < (this->y + this->h)){
            return true;
        }
    }

    return false;
}