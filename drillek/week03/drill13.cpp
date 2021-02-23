/*
    g++ drill13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill13 `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"
#include <time.h>

int main()
{
	Simple_window win{Point{100,100}, 800, 1000, "WHAT ARE YOU DOING IN MY SWAMP?"};

	/*
	Put an 8-by-8 grid on the leftmost 800-by-800 part of that
	window (so that each square is 100 by 100).
	*/

	Lines grid;
	int x_koz = 100, y_koz = 100;
	for(int x = x_koz; x < 900; x += x_koz)
		grid.add(Point{x, 0}, Point{x, 800});
	for(int y = y_koz; y < 900; y += y_koz)
		grid.add(Point{0,y}, Point{800, y});

	win.attach(grid);

	/*
	Make the eight squares on the diagonal starting from the top
	left corner red (use Rectangle).
	*/

	Vector_ref<Rectangle> negyzetek;

	for(int i = 0; i < 8; ++i)
	{
		negyzetek.push_back(new Rectangle{Point{i*100,i*100}, 100, 100});
		negyzetek[negyzetek.size()-1].set_color(Color::red);
		win.attach(negyzetek[negyzetek.size()-1]);
	}

	/*
	Find a 200-by-200-pixel image (JPEG or GIF) and place three
	copies of it on the grid (each image covering four squares). If
	you can’t find an image that is exactly 200 by 200, use
	set_mask() to pick a 200-by-200 section of a larger image. Don’t
	obscure the red squares.
	*/

	Image img3 {Point{600,0}, "img3.jpeg"};
	Image img2 {Point{0,400}, "img2.jpeg"};
	Image img1 {Point{200,600}, "img1.jpeg"};

	win.attach(img1);
	win.attach(img2);
	win.attach(img3);

	/*
	Add a 100-by-100 image. Have it move around from square to
	square when you click the “Next” button. Just put
	wait_for_button() in a loop with some code that picks a new
	square for your image.
	*/

	srand (time(NULL));//randomizáció előkészítése//


	int shrek_x = 200, shrek_y = 700;
	while(true)
	{
		Image shrek{Point{shrek_x, shrek_y}, "shrek.jpeg"};
		win.attach(shrek);

		bool talalt = false;
		while(talalt == false)
		{
			int irany = rand() % 4 + 1;
			switch(irany)
			{
				case 1:
					if(shrek_y != 0)
					{
						shrek_y -= 100;
						talalt = true;
						break;
					}
					else break;
				case 2:
					if(shrek_x != 700)
					{
						shrek_x += 100;
						talalt = true;
						break;
					}
					else break;
				case 3:
					if(shrek_y != 700)
					{
						shrek_y += 100;
						talalt = true;
						break;
					}
					else break;
				case 4:
					if(shrek_x != 0)
					{
						shrek_x -= 100;
						talalt = true;
						break;
					}
					else break;

			}
		}
		win.wait_for_button();
	}


	win.wait_for_button();
}