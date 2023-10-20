#include <vec/Vec2d.h>

Vec2D operator+ (const Vec2D& rhs0, const Vec2D& rhs)
{
    return Vec2D{rhs0.x + rhs.x, rhs0.y + rhs.y};
}

Vec2D operator- (const Vec2D& rhs0, const Vec2D& rhs)
{
    return Vec2D{rhs0.x - rhs.x, rhs0.y - rhs.y};
}

Vec2D operator* (double x, const Vec2D& rhs)
{
    return Vec2D{rhs.x * x, rhs.y * x};
}

Vec2D operator* (const Vec2D& rhs, double x0)
{
    return Vec2D{rhs.x * x0, rhs.y * x0};
}

double length (const Vec2D& rhs)
{
    return sqrt(rhs.x * rhs.x + rhs.y * rhs.y);
}
