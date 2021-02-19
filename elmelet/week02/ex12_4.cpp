/*
    g++ ex12_4.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ex12_4 `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;
	Simple_window win {Point{100,100}, 900, 900, "tic-tac-toe"};

	Rectangle rec1 {Point{0,0}, 300, 300};
	rec1.set_fill_color(Color::dark_red);

	Rectangle rec2 {Point{300,0}, 300, 300};
	rec2.set_fill_color(Color::white);

	Rectangle rec3 {Point{600,0}, 300, 300};
	rec3.set_fill_color(Color::dark_red);

	Rectangle rec4 {Point{0,300}, 300, 300};
	rec4.set_fill_color(Color::white);

	Rectangle rec5 {Point{300,300}, 300, 300};
	rec5.set_fill_color(Color::dark_red);

	Rectangle rec6 {Point{600,300}, 300, 300};
	rec6.set_fill_color(Color::white);

	Rectangle rec7 {Point{0,600}, 300, 300};
	rec7.set_fill_color(Color::dark_red);

	Rectangle rec8 {Point{300,600}, 300, 300};
	rec8.set_fill_color(Color::white);

	Rectangle rec9 {Point{600,600}, 300, 300};
	rec9.set_fill_color(Color::dark_red);

	win.attach(rec1);
	win.attach(rec2);
	win.attach(rec3);
	win.attach(rec4);
	win.attach(rec5);
	win.attach(rec6);
	win.attach(rec7);
	win.attach(rec8);
	win.attach(rec9);

	win.wait_for_button();
}