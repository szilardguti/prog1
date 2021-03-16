#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
	Lines_window(Point xy, int w, int h, const string& title );

private:
	Open_polyline lines;
	Menu color_menu;
	Menu style_menu;

	bool wait_for_button();

	Button next_button;
	Button quit_button;
	Button color_menu_button;
	Button style_menu_button;

	In_box next_x;
	In_box next_y;

	Out_box xy_out;

	void next();
	void quit();

	void color_hide_menu();
	void color_menu_pressed();
	void red_pressed();
	void blue_pressed();
	void black_pressed();
	void color_change(Color c);

	void style_hide_menu();
	void style_menu_pressed();
	void solid_pressed();
	void slash_pressed();
	void dot_pressed();
	void style_change(Line_style s);
};