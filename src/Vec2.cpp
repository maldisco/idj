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

Vec2 Vec2::operator*(float n){
    return Vec2(x*n, y*n);
}

Vec2 Vec2::operator=(Vec2 v2){
    return Vec2(v2.x, v2.y);
}

float Vec2::Magnitude(){
    return sqrt(x*x + y*y);
}

Vec2 Vec2::Normalize(){
    float mag = Magnitude();
    return Vec2(x/mag, y/mag);
}

float Vec2::Distance(Vec2 v1, Vec2 v2){
    return (v1 - v2).Magnitude();
}

float Vec2::Dot(Vec2 v1, Vec2 v2){
    return v1.x*v2.x + v1.y*v2.y; 
}

float Vec2::SlopeX(){
    float m = Dot(this->Normalize(), Vec2(1, 0));
    return atan(m);
}

float Vec2::Slope(Vec2 v1, Vec2 v2){
    return (v2 - v1).SlopeX();
}

Vec2 Vec2::Rotate(float angle){
    return Vec2(x*cos(angle) - y*sin(angle), y*cos(angle) + x*sin(angle));
}