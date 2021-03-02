/*
    g++ ex13_7.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ex13_7 `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"


int main()
{
    using namespace Graph_lib;
    constexpr int win_w = 600, win_h = 600;

    Simple_window win{Point{100,100}, win_w, win_h, "rgb color chart"};

    Vector_ref<Rectangle> cols;

    int box_w = 5, box_h = 5;
    for(int j = 0; j < win_h / box_h; ++j)
    {
    	for(int i = 0; i < win_w / box_w; ++i)
    	{
    		cols.push_back(new Rectangle{Point{i * box_w, j * box_h}, box_w, box_h});
    		cols[cols.size()-1].set_fill_color(i + j);
    		cols[cols.size()-1].set_color(i + j);

    		win.attach(cols[cols.size()-1]);
    	}
    }

    win.wait_for_button();
}
