#include "Vec2.h"

class Rect{
    public:
        float x, y, w, h;

        Rect();

        Rect(float x, float y, float w, float h);

        Rect operator+(Vec2 v2);

        Rect operator=(Rect rect);

        Vec2 Center();

        static float Distance(Rect r1, Rect r2);
};