/*
    g++ ex12_2.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ex12_2 `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;
	int bfs_x = 300, bfs_y = 300;

	Simple_window win {Point{100,100}, 1280, 720, "My Window"};

	Rectangle tegla {Point{bfs_x,bfs_y}, 100, 30};

	Text tx {Point{bfs_x + 25, bfs_y + 15},"Howdy!"};
	//tx.set_font_size(10);

	win.attach(tegla);
	win.attach(tx);
	win.wait_for_button();
}