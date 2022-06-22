#ifndef VEC2_H
#define VEC2_H

#define PI 3.14159265

/**
 * @brief Class that represents both a point and a vector
 * 
 */
class Vec2{
    public:
        float x, y;

        Vec2();
        Vec2(float x, float y);

        Vec2 operator+(Vec2 v2);
        Vec2 operator-(Vec2 v2);
        Vec2 operator=(Vec2 v2);

        /**
         * @brief Returns the magnitude or length of the vector
         * 
         * @return float 
         */
        float Magnitude();

        /**
         * @brief Returns a normalized vector (magnitude=1)
         * 
         * @return Vec2 
         */
        Vec2 Normalized();

        /**
         * @brief Returns the distance between two vectors
         * 
         * @param v1 
         * @param v2 
         * @return float 
         */
        static float Distance(Vec2 v1, Vec2 v2);

        /**
         * @brief Returns inclination of the vector in relation to X
         * 
         * @return float 
         */
        float SlopeX();

        /**
         * @brief Returns inclination of the vector in relation to another vector
         * 
         * @return float 
         */
        float Slope(Vec2 v2);

        /**
         * @brief Rotate the vector
         * 
         * @param angle 
         */
        Vec2 Rotate(float angle);
};
#endif