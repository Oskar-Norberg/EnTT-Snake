//
// Created by Oskar.Norberg on 2025-03-25.
//

#ifndef VECTOR2_H
#define VECTOR2_H

namespace Core_Utils
{
    struct Vector2Int
    {
        int x, y;

        Vector2Int operator+(const Vector2Int& other) const { return {x + other.x, y + other.y}; }
        Vector2Int operator-(const Vector2Int& other) const { return {x - other.x, y - other.y}; }
        Vector2Int operator*(const Vector2Int& other) const { return {x * other.x, y * other.y}; }
        Vector2Int operator/(const Vector2Int& other) const { return {x / other.x, y / other.y}; }
    };

    struct Vector2
    {
        float x, y;
        Vector2() : x(0), y(0) {}
        Vector2(float x, float y) : x(x), y(y) {}
        
        Vector2 operator+(const Vector2& other) const { return {x + other.x, y + other.y}; }
        Vector2 operator-(const Vector2& other) const { return {x - other.x, y - other.y}; }
        Vector2 operator*(const Vector2& other) const { return {x * other.x, y * other.y}; }
        Vector2 operator/(const Vector2& other) const { return {x / other.x, y / other.y}; }
    };
}

#endif //VECTOR2_H
