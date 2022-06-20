

class Vec2{
    public:
        float x, y;

        Vec2();

        Vec2(float x, float y);

        Vec2 Add(Vec2 v2);

        Vec2 Sub(Vec2 v2);

        float Magnitude();

        Vec2 Norm();

        float Distance(Vec2 v2);

        float SlopeX();

        float Slope(Vec2 v2);

        void Rotate(float angle);
};