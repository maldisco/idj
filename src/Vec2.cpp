#include "Vec2.h"
#include "Rect.h"
#include "math.h"

Vec2::Vec2() : x(0), y(0){}
Vec2::Vec2(float x, float y) : x(x), y(y) {}

Vec2 Vec2::operator+(Vec2 v2){
    return Vec2(x + v2.x, y + v2.y);
}

Vec2 Vec2::operator-(Vec2 v2){
    return Vec2(x - v2.x, y - v2.y);
}

Vec2 Vec2::operator=(Vec2 v2){
    return Vec2(v2.x, v2.y);
}

float Vec2::Magnitude(){
    return sqrt(x*x + y*y);
}

Vec2 Vec2::Normalized(){
    float mag = Magnitude();
    return Vec2(x/mag, y/mag);
}

float Vec2::Distance(Vec2 v1, Vec2 v2){
    return (v1 - v2).Magnitude();
}

bool Vec2::IsInside(Rect rect){
    if(x > rect.x && x < (rect.x + rect.w)){
        if(y > rect.y && y < (rect.y + rect.h)){
            return true;
        }
    }

    return false;
}