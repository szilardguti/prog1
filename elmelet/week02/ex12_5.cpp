/*
    g++ ex12_5.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ex12_5 `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;

	Simple_window win {Point{0,0}, x_max(), y_max(), "BIG Window"};

	Rectangle bigboi {Point{win.x_max()/6,win.y_max()/8},2*(win.x_max()/3),3*(win.y_max()/4)};
	bigboi.set_style(Line_style(Line_style::solid,15));

	win.attach(bigboi);
	win.wait_for_button();
}