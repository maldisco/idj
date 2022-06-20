#include "Vec2.h"

class Rect{
    public:
        float x, y, w, h;

        Rect();

        Rect(float x, float y, float w, float h);

        Rect AddVec(Vec2 v2);

        Vec2 Center();

        float Distance(Rect r2);

        bool IsInside(Vec2 v2);

};