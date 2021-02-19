/*
    g++ ex12_3.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ex12_3 `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;
	int bfs_x = 300, bfs_y = 300;

	Simple_window win {Point{100,100}, 1280, 720, "My Window"};

	Axis y {Axis::y, Point{25,720}, 150, 0, "150 pixel"};

	Text G {Point{100,720}, "G."};
	G.set_font(Font::times_bold);
	G.set_font_size(200);
	G.set_color(Color::red);

	Text S {Point{400,720}, "Sz."};
	S.set_font(Font::times_bold);
	S.set_font_size(200);
	S.set_color(Color::yellow);

	win.attach(y);
	win.attach(G);
	win.attach(S);

	/////poly rajzolós verzió//////

	Open_polyline g;
	g.add(Point{200,300});
	g.add(Point{100,300});
	g.add(Point{100,450});
	g.add(Point{200,450});
	g.add(Point{200,400});
	g.add(Point{150,400});
	g.set_color(Color::red);
	g.set_style(Line_style(Line_style::solid,4));

	Open_polyline s;
	s.add(Point{325,300});
	s.add(Point{250,300});
	s.add(Point{250,375});
	s.add(Point{325,375});
	s.add(Point{325,450});
	s.add(Point{250,450});
	s.set_color(Color::blue);
	s.set_style(Line_style(Line_style::solid,4));

	Open_polyline z;
	z.add(Point{350,300});
	z.add(Point{450,300});
	z.add(Point{350,450});
	z.add(Point{450,450});
	z.set_color(Color::green);
	z.set_style(Line_style(Line_style::solid,4));

	win.attach(g);
	win.attach(s);
	win.attach(z);
	win.wait_for_button();
}