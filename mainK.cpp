#include <iostream>
#include <list>
#include <cassert>
#include <sstream>
#include <stdexcept>
#include <vec/Vec2d.h>
#include <poly/poly.h>

#include <Graph_lib/Graph.h>
#include <Graph_lib/Simple_window.h>

using namespace Graph_lib;

double max_edge_length(const std::list <Vec2D>& curve)
{
    assert(!curve.empty());
    double m = 0.;
    auto p = --curve.end();
    for (auto c = curve.begin(); c != curve.end(); ++c) {
        double d = length(*c - *p);
        if (m < d) m = d;
        p = c;
    }
    return m;
}

void draw_koch_snowflake(int w, int n) {
    Simple_window win{Point{100, 100}, w, w, "Koch snowflake"};
    Vec2D c{w/2., w/2.}; // window center
    double r{0.85*w/2.}; // polygon radius
    auto ngon = regular_polygon(n, c, r, -pi/2.);
    for (auto i : ngon) std::cout << i.x << ' ' << i.y << '\n';
    std::cout << "*\n";

    Text n_steps {as_point(c), "0"};
    n_steps.set_color(Color::blue);
    win.attach(n_steps);

    for (bool is_fine = false; !is_fine; ) {
        Closed_polyline curve;
        append(curve, ngon);
        curve.set_color(Color::blue);
        
        koch_fractal_step(ngon);

        is_fine = max_edge_length(ngon) < 1.0;
        if (is_fine) n_steps.set_color(Color::red);

        win.attach(curve);
        win.wait_for_button();
        win.detach(curve);    

        n_steps.set_label(std::to_string(stoi(n_steps.label())+1));                 
    }
}

int main ()
{
    draw_koch_snowflake(400, 3);
}
