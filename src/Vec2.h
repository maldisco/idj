class Vec2{
    public:
        float x, y;

        Vec2();

        Vec2(float x, float y);

        Vec2 operator+(Vec2 v2);

        Vec2 operator-(Vec2 v2);

        Vec2 operator=(Vec2 v2);

        float Magnitude();

        Vec2 Normalized();

        static float Distance(Vec2 v1, Vec2 v2);

        bool IsInside(Rect rect);

        float SlopeX();

        float Slope(Vec2 v2);

        void Rotate(float angle);
};