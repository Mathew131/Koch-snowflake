#include <Graph_lib/Graph.h>
#include <Vec/Vec2d.h>
#include <cassert>
#include <cmath>
#include <list>

#include "poly.h"

using namespace Graph_lib;

Vec2D rotated (double angle, Vec2D point, Vec2D center)
{
    Vec2D r{point - center};
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    return center + Vec2D{cos_a * r.x - sin_a * r.y, sin_a * r.x + cos_a * r.y};
}

std::list<Vec2D> regular_polygon (int n, Vec2D center, double radius, double angle)
{
    assert(n > 2 && radius > 0);

    Vec2D p{radius, 0};
    std::list<Vec2D> poly;
    for (int j = 0; j < n; ++j)
    {
        double phi = 2 * pi * j / n;
        Vec2D q = rotated(angle - phi, p);
        poly.push_back(center + q);
    }

    return poly;
}

void append (Closed_polyline& poly, const std::list<Vec2D>& points)
{
    for (const auto& item : points)
        poly.add(as_point(item));
}

void koch_fractal_step (std::list<Vec2D>& curve)
{
    assert(!curve.empty());
    auto prev = --curve.end();
    for (auto curr = curve.begin(); curr != curve.end(); ++curr)
    {
        auto p = lerp(*prev, *curr, 1. / 3.);
        auto q = lerp(*prev, *curr, 2. / 3.);
        auto m = rotated(pi / 3., q, p);
        curve.insert(curr, p);
        curve.insert(curr, m);
        curve.insert(curr, q);
        prev = curr;
    }
}