/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;
    
   	Simple_window win {Point{100,100}, 300, 300, "hurka"};


   	win.wait_for_button();
}
