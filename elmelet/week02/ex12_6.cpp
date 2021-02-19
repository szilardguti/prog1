/*
    g++ ex12_6.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ex12_6 `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;

	Simple_window win{Point{100,100}, x_max()+600, y_max()+600, "Too big window"};

	Rectangle bug_rec {Point{100,100},win.x_max()+500, win.y_max()+500};

	win.attach(bug_rec);
	win.wait_for_button();
}