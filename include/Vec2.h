#ifndef VEC2_H
#define VEC2_H

#include <string>
#define PI 3.14159265

/**
 * @brief represents both a point and a vector
 * 
 */
class Vec2{
    public:
        float x, y;

        Vec2();
        Vec2(float x, float y);

        Vec2 operator+(Vec2 v2);
        Vec2 operator-(Vec2 v2);
        Vec2 operator*(float n);

        /**
         * @brief magnitude or length of the vector
         * 
         * @return float 
         */
        float Magnitude();

        /**
         * @brief normalize the vector (magnitude=1)
         * 
         * @return Vec2 
         */
        Vec2 Normalize();

        /**
         * @brief the distance between two vectors
         * 
         * @param v1 
         * @param v2 
         * @return float 
         */
        static float Distance(Vec2 v1, Vec2 v2);

        /**
         * @brief dot product of 2 vectors
         * 
         * @param v1 
         * @param v2 
         * @return float 
         */
        static float Dot(Vec2 v1, Vec2 v2);

        /**
         * @brief slope of a line from 2 points
         * 
         * @return float 
         */
        static float Slope(Vec2 v1, Vec2 v2);

        /**
         * @brief slope of the vector on x (in radians)
         * 
         * @return float 
         */
        float SlopeX();

        /**
         * @brief Rotate the vector
         * 
         * @param angle 
         */
        Vec2 Rotate(float angle);
};
#endif