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

Vec2 Vec2::Rotate(float angle){
    return Vec2(x*cos(angle) - y*sin(angle), y*cos(angle) + x*sin(angle));
}