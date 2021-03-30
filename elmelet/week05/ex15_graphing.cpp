/*
    g++ ex15_graphing.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ex15_graphing `fltk-config --ldflags --use-images`
*/
#include "Window.h"
#include "Graph.h"

using namespace Graph_lib;

struct Distribution 
{
	int year, tea, coffee, chocolate_milk; 
};

istream& operator>> (istream& is, Distribution& d)
{
	is >> d.year >> d.tea >> d.coffee >> d.chocolate_milk;

	if(d.year < 2000 || d.year > 2040) error("Year out of bound");
	else if(d.tea + d.coffee + d.chocolate_milk > 100) error("Percentages are wrong!");
	
	return is;
}

class Scale {
	
	int cbase;	// data value to coordinate conversion
	int vbase;	// coordinate base
	double scale;	// base of values
public:
	Scale(int b, int vb, double s) :cbase{b}, vbase{vb}, scale{s} { }
	int operator()(int v) const { return cbase + (v-vbase)*scale; }
};

int main()
{
	//setting up the window
	constexpr int xmax = 1280;
	constexpr int ymax = 720;

	constexpr int xoffset = 100; // distance from left-hand side of window to y axis
	constexpr int yoffset = 60; // distance from bottom of window to x axis
	constexpr int xspace = 40; // space beyond axis
	constexpr int yspace = 40;

	constexpr int xlength = xmax-xoffset-xspace;
	constexpr int ylength = ymax-yoffset-yspace;

	//scaling
	constexpr int base_year = 2000;
	constexpr int end_year = 2040;
	constexpr double xscale = double(xlength)/(end_year-base_year);
	constexpr double yscale = double(ylength)/100;

	Scale xs {xoffset,base_year,xscale};
	Scale ys {ymax-yoffset,0,-yscale};

	//Adding elements
	Window win {Point{100,100}, xmax, ymax, "Products sold"};

	Axis x {Axis::x, Point{xoffset, ymax-yoffset}, xlength, 8, 
		"year        2000                       2005                          2010                           2015                           2020                          "
		"2025                           2030                           2035                           2040"};
	x.label.move(-350,0);

	Axis y {Axis::y, Point{xoffset,ymax-yoffset}, ylength, 10,"% of sold items"};
	win.attach(x);	win.attach(y);

	Open_polyline cof; cof.set_color(Color::red);
	Open_polyline tee; tee.set_color(Color::dark_green);
	Open_polyline choc; choc.set_color(Color::dark_magenta);

	Line current_year {Point{xs(2021), ys(0)}, Point{xs(2021), ys(100)}};
	current_year.set_style(Line_style::dash);

	//input sequence
	string file_name = "graphing_data.txt";

	ifstream input{file_name};
	if (!input) error("can't open ",file_name);

	while(!input.eof())
	{
		Distribution d;
		input >> d;

		const int x = xs(d.year);
		cof.add(Point{x,ys(d.coffee)});
		tee.add(Point{x,ys(d.tea)});
		choc.add(Point{x,ys(d.chocolate_milk)});
	}

	//labeling

	Text cof_label {Point{20, cof.point(0).y}, "coffee"};
	cof_label.set_color(Color::red);

	Text tee_label {Point{20, tee.point(0).y}, "tea"};
	tee_label.set_color(Color::dark_green);

	Text choc_label {Point{0, choc.point(0).y}, "chocolate milk"};
	choc_label.set_color(Color::dark_magenta);


	win.attach(cof);
	win.attach(tee);
	win.attach(choc);

	win.attach(cof_label);
	win.attach(tee_label);
	win.attach(choc_label);
	win.attach(current_year);

	return gui_main();
}