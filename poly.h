#pragma once
#include <Graph_lib/Graph.h>
#include <Vec/Vec2d.h>
#include <list>

using namespace Graph_lib;

Vec2D rotated (double angle, Vec2D point, Vec2D center = Vec2D{});

std::list<Vec2D> regular_polygon (int n, Vec2D center, double radius, double angle = 0);

inline Vec2D lerp (Vec2D a, Vec2D b, double t) { return a + (b - a) * t; }

void append (Closed_polyline& poly, const std::list<Vec2D>& points);

inline Point as_point (Vec2D p) { return {int(round(p.x)), int(round(p.y))}; }

void koch_fractal_step (std::list<Vec2D>& curve);
