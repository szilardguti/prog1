/*
    g++ ex12_9.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ex12_9 `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;

	Simple_window win{Point{50,50}, 900, 600, "-"};

	Image ii {Point{100,0}, "butterdog.gif"};

	win.set_label("Butterdog");

	Text tx{Point{250,550},"Dog with the butter!"};
	tx.set_font_size(50);
	tx.set_color(Color::yellow);


	win.attach(ii);
	win.attach(tx);
	win.wait_for_button();
}