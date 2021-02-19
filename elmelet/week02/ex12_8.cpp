/*
    g++ ex12_8.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ex12_8 `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;

	Simple_window win{Point{100,100}, 1200, 600, "Olimpyc five"};

	Circle c1 {Point{300,300},100};
	c1.set_color(Color::blue);
	c1.set_style(Line_style(Line_style::solid,20));

	Circle c2 {Point{400,400},100};
	c2.set_color(Color::yellow);
	c2.set_style(Line_style(Line_style::solid,20));

	Circle c3 {Point{525,300},100};
	c3.set_style(Line_style(Line_style::solid,20));

	Circle c4 {Point{625,400},100};
	c4.set_color(Color::dark_green);
	c4.set_style(Line_style(Line_style::solid,20));

	Circle c5 {Point{750,300},100};
	c5.set_color(Color::red);
	c5.set_style(Line_style(Line_style::solid,20));

	win.attach(c1);
	win.attach(c2);
	win.attach(c3);
	win.attach(c4);
	win.attach(c5);
	win.wait_for_button();
}