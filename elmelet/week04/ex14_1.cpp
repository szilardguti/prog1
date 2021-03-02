/*
    g++ ex14_1.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ex14_1 `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

struct Smiley : Circle
{
	Smiley(Point p, int rr): Circle(p, rr) { }

	void draw_lines() const;

};

struct Frowny : Circle
{
	Frowny(Point p, int rr): Circle(p, rr) { }

	void draw_lines() const;
};

struct HappyHat : Smiley
{
	HappyHat(Point p, int rr): Smiley(p, rr) {}

	void draw_lines() const;
};

struct FrownyHat : Frowny
{
	FrownyHat(Point p, int rr): Frowny(p, rr) {}

	void draw_lines() const;
};





int main()
{
    using namespace Graph_lib;
    Simple_window win{Point{100,100}, 800, 800, "smileys"};


    FrownyHat szomor{Point{250,250}, 100};
    szomor.set_fill_color(Color::yellow);

    Smiley happ{Point{600,600}, 100};
    happ.set_fill_color(Color::yellow);

    HappyHat boldogkalap {Point{400,400}, 100};

    win.attach(szomor);
    win.attach(happ);
    win.attach(boldogkalap);
    win.wait_for_button();
}





void Smiley::draw_lines() const
{
	Circle::draw_lines();

	int rr = radius();
	int eye_rad = rr / 5;
	int eye_dis = rr / 2;
	int mouth_rad = rr / 2;


	fl_color(Color::black);
	fl_pie(point(0).x + rr - 3 * eye_rad, point(0).y + eye_dis, eye_rad + eye_rad, eye_rad + eye_rad, 0, 360);
	fl_pie(point(0).x + rr + eye_rad, point(0).y + eye_dis, eye_rad + eye_rad, eye_rad + eye_rad, 0, 360);
	fl_color(color().as_int());

	fl_color(Color::red);
	fl_arc(point(0).x + rr - mouth_rad, point(0).y + rr - mouth_rad, 2 * mouth_rad, 2 * mouth_rad, 180, 360);
}

void Frowny::draw_lines() const
{
	Circle::draw_lines();

	int rr = radius();
	int eye_rad = rr / 5;
	int eye_dis = rr / 2;
	int mouth_rad = rr / 2;


	fl_color(Color::black);
	fl_pie(point(0).x + rr - 3 * eye_rad, point(0).y + eye_dis, eye_rad + eye_rad, eye_rad + eye_rad, 0, 360);
	fl_pie(point(0).x + rr + eye_rad, point(0).y + eye_dis, eye_rad + eye_rad, eye_rad + eye_rad, 0, 360);
	fl_color(color().as_int());

	fl_color(Color::red);
	fl_arc(point(0).x + rr - mouth_rad, point(0).y + rr, 2 * mouth_rad, 2 * mouth_rad, 0, 180);
}

void HappyHat::draw_lines() const
{
	Smiley::draw_lines();

	int hat_w = 2 * radius();
	int hat_h = radius() / 10;

	fl_color(Color::green);
	fl_rectf(point(0).x, point(0).y + hat_h, hat_w, hat_h);
	fl_rectf(point(0).x + hat_w / 2 - hat_w / 4, point(0).y - 10 * hat_h, hat_w / 2, 11 * hat_h);
	fl_color(color().as_int());
}

void FrownyHat::draw_lines() const
{
	Frowny::draw_lines();

	int hat_w = 2 * radius();
	int hat_h = radius() / 8;

	fl_color(Color::dark_blue);
	fl_rectf(point(0).x, point(0).y + hat_h, hat_w, hat_h);
	fl_rectf(point(0).x + hat_w / 2 - hat_w / 4, point(0).y - 3 * hat_h, hat_w / 2, 4 * hat_h);
	fl_color(color().as_int());
}