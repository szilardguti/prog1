/*
    g++ ex12_7.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ex12_7 `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;

	Simple_window win{Point{100,100}, 1200, 600, "Done by Picasso"};

	Rectangle fold{Point{0,500}, 1200, 100};
	fold.set_fill_color(Color::dark_green);

	Rectangle haz{Point{100,300}, 200, 200};
	haz.set_fill_color(Color::yellow);
	haz.set_style(Line_style(Line_style::solid,4));

	Polygon teto;
	teto.add(Point{100,300});
	teto.add(Point{300,300});
	teto.add(Point{200,200});
	teto.set_fill_color(Color::red);
	teto.set_style(Line_style(Line_style::solid,4));

	Polygon kemeny;
	kemeny.add(Point{300,300});
	kemeny.add(Point{300,250});
	kemeny.add(Point{275,250});
	kemeny.add(Point{275,300});
	kemeny.set_fill_color(Color::dark_red);
	kemeny.set_style(Line_style(Line_style::solid,4));

	Polygon ajto;
	ajto.add(Point{175,500});
	ajto.add(Point{225,500});
	ajto.add(Point{225,425});
	ajto.add(Point{175,425});
	ajto.set_fill_color(Color::green);
	ajto.set_style(Line_style(Line_style::solid,2));

	Rectangle ablak1{Point{110, 375}, 50, 50};
	ablak1.set_fill_color(Color::cyan);

	Rectangle ablak2{Point{240, 375}, 50, 50};
	ablak2.set_fill_color(Color::cyan);

	Image hatter{Point{0,0}, "7hatter.jpg"};

	win.attach(hatter);
	win.attach(fold);
	win.attach(haz);
	win.attach(ajto);
	win.attach(ablak1);
	win.attach(ablak2);
	win.attach(kemeny);
	win.attach(teto);
	win.wait_for_button();
}