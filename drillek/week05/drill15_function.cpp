/*
    g++ drill15_function.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill15_function `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x * x; }
double sloping_cos(double x) { return cos(x) + slope(x); }

int main()
{
	using namespace Graph_lib;
	constexpr int win_x_max = 600;
	constexpr int win_y_max = 600;

	Simple_window win{Point{100,100}, win_x_max, win_y_max, "Function graphs"};

	//axis
	int orig_x = 300, orig_y = 300;
	Point orig {orig_x, orig_y};

	double xlength = 400, ylength = 400;
	double xscale = 20, yscale = 20;
	Axis x {Axis::x, Point{orig_x - xlength / 2, orig_y}, xlength, xlength / xscale, "1 == 20 pixels"};
	Axis y {Axis::y, Point{orig_x , orig_y + ylength / 2}, ylength, ylength / yscale, "1 == 20 pixels"};
	x.set_color(Color::red);
	y.set_color(Color::red);


	/*Mark o {Point{300,300}, 'o'};
	win.attach(o);*/

	//graphing
	double rmin = -10, rmax = 11;
	int points = 400;

		//one
	Function vline {one, rmin, rmax, orig, points, xscale, yscale};
		//slope
	Function incline {slope, rmin, rmax, orig, points, xscale, yscale};
	Text incl_label {Point{incline.point(0).x, incline.point(0).y - 10}, "x/2"};
		//square
	Function sqr {square, rmin, rmax, orig, points, xscale, yscale};
		//cosine
	Function cosin {cos, rmin, rmax, orig, points, xscale, yscale};
	cosin.set_color(Color::blue);
		//sloping_cos
	Function slop_cos {sloping_cos, rmin, rmax, orig, points, xscale, yscale};


	win.attach(x);
	win.attach(y);
	win.attach(vline);
	win.attach(incline);
	win.attach(incl_label);
	win.attach(sqr);
	win.attach(cosin);
	win.attach(slop_cos);
	win.wait_for_button();
}