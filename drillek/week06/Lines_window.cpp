#include "Lines_window.h"

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window{xy,w,h,title},
    next_button{Point{x_max()-300,0}, 150, 40, "Next point",
        [](Address, Address pw) {reference_to<Lines_window>(pw).next();}},
    quit_button{Point{x_max()-150,0}, 150, 40, "Quit",
        [](Address, Address pw) {reference_to<Lines_window>(pw).quit();}},
    color_menu{Point{x_max()-300,40},150,40,Menu::vertical,"color"},
    color_menu_button{Point{x_max()-300,40}, 150, 40, "color menu",
        [](Address, Address pw) {reference_to<Lines_window>(pw).color_menu_pressed();}},
    style_menu{Point{x_max()-150,40},150,40,Menu::vertical,"style"},
    style_menu_button{Point{x_max()-150,40}, 150, 40, "style menu",
        [](Address, Address pw) {reference_to<Lines_window>(pw).style_menu_pressed();}},
    next_x{Point{300,0}, 50, 40, "next x:"},
    next_y{Point{450,0}, 50, 40, "next y:"},
    xy_out{Point{100,0}, 100, 40, "current (x,y):"}
{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    xy_out.put("no point!");
    //color menu
    color_menu.attach(new Button{Point{0,0},0,0,"red", [](Address, Address pw) {reference_to<Lines_window>(pw).red_pressed();}});
    color_menu.attach(new Button{Point{0,0},0,0,"blue", [](Address, Address pw) {reference_to<Lines_window>(pw).blue_pressed();}});
    color_menu.attach(new Button{Point{0,0},0,0,"black", [](Address, Address pw) {reference_to<Lines_window>(pw).black_pressed();}});
    attach(color_menu);
    color_menu.hide();
    attach(color_menu_button);

    //style menu
    style_menu.attach(new Button{Point{0,0},0,0,"solid", [](Address, Address pw) {reference_to<Lines_window>(pw).solid_pressed();}});
    style_menu.attach(new Button{Point{0,0},0,0,"slash", [](Address, Address pw) {reference_to<Lines_window>(pw).slash_pressed();}});
    style_menu.attach(new Button{Point{0,0},0,0,"dot", [](Address, Address pw) {reference_to<Lines_window>(pw).dot_pressed();}});
    attach(style_menu);
    style_menu.hide();
    attach(style_menu_button);

    attach(lines);
}

void Lines_window::quit()
{
    hide();
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point{x,y});

    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

    redraw();
}

void Lines_window::color_hide_menu()
{
    color_menu.hide();
    color_menu_button.show();
}
void Lines_window::color_menu_pressed()
{
    color_menu_button.hide();
    color_menu.show();
}

void Lines_window::color_change(Color c)
{
    lines.set_color(c);
}

void Lines_window::red_pressed() { color_change(Color::red); color_hide_menu(); }
void Lines_window::blue_pressed() { color_change(Color::blue); color_hide_menu(); }
void Lines_window::black_pressed() { color_change(Color::black); color_hide_menu(); }


void Lines_window::style_hide_menu()
{
    style_menu.hide();
    style_menu_button.show();
}
void Lines_window::style_menu_pressed()
{
    style_menu_button.hide();
    style_menu.show();
}

void Lines_window::style_change(Line_style s)//TODO
{
    lines.set_style(s);
}

void Lines_window::solid_pressed() { style_change(Line_style(Line_style::solid)); style_hide_menu(); }
void Lines_window::slash_pressed() { style_change(Line_style(Line_style::dash)); style_hide_menu(); }
void Lines_window::dot_pressed() { style_change(Line_style(Line_style::dot)); style_hide_menu(); }