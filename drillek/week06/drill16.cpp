/*
    g++ drill16.cpp Graph.cpp Window.cpp GUI.cpp Lines_window.cpp -o drill16 `fltk-config --ldflags --use-images`
*/
#include "Lines_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{
	const int xmax = 1200, ymax = 800;
	Lines_window lwin{Point{100,100}, xmax, ymax, "Lines are |\\| | C E "};


	return gui_main();
}