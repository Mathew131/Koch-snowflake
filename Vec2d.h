#pragma once
#include <cmath>

class Vec2D
{
public:
    Vec2D(double x_, double y_) : x{x_}, y{y_} {}

    Vec2D() = default;
    double x = 0, y = 0;

    Vec2D& operator+= (const Vec2D& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    Vec2D& operator-= (const Vec2D& rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }

    Vec2D& operator*=(double x0) {
        x *= x0;
        y *= x0;
        return *this;
    }
};

Vec2D operator+ (const Vec2D& rhs0, const Vec2D& rhs);

Vec2D operator- (const Vec2D& rhs0, const Vec2D& rhs);

Vec2D operator* (double x, const Vec2D& rhs);

Vec2D operator* (const Vec2D& rhs, double x0);

double length (const Vec2D& rhs);