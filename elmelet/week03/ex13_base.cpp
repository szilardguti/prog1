/*
    g++ ex13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ex13 `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

struct Arc : Shape
{
	Arc(Point p, int ww, int hh, int bb_angle, int ee_angle): 
		w{ww}, h{hh}, b_ang{bb_angle}, e_ang{ee_angle} 
		{
			add(Point{ p.x - w, p.y - h });
		}

	void draw_lines() const;

	////getter functions////
	Point center() const { return {point(0).x, point(0).y}; }
	int height() const { return h; }
	int width() const { return w; }
	int beginning_angle() const { return b_ang; }
	int ending_angle() const { return e_ang; }

	////setter functions////
	void set_height(int hh) { h = hh; }
	void set_width(int ww) { w = ww; }
	void set_beginning_angle(int bb_angle) { b_ang = bb_angle; }
	void set_ending_angle(int ee_angle) { e_ang = ee_angle; } 

private:
	int w,h;
	int b_ang,e_ang;
}; 

struct Box : Shape
{
	Box(Point xy, int ww, int hh): w{ww}, h{hh}, lab{""}
	{
		if (h<=0 || w<=0) error("Nem jó oldalhossz.");
		add(xy);
	}
	Box(Point x, Point y): w{ y.x - x.x }, h{ y.y - x.y }, lab{""}
	{
		if (h<=0 || w<=0) error("Nem jó pontok.");
		add(x);
	}
	Box(Point xy, int ww, int hh, const string& s): w{ww}, h{hh}, lab{s}
	{
		if (h<=0 || w<=0) error("Nem jó oldalhossz.");
		add(xy);
		add(Point{xy.x + w / 6, xy.y + 4 * (h / 6)});
	}
	Box(Point x, Point y, const string& s): w{ y.x - x.x }, h{ y.y - x.y }, lab{s}
	{
		if (h<=0 || w<=0) error("Nem jó pontok.");
		add(x);
		add(Point{x.x + w / 6, x.y + 4 * (h / 6)});
	}
	
	void draw_lines() const;

	void set_label(const string& s) { lab = s; } //'borrowed' from Text class
	string label() const { return lab; }

	void set_font(Font f) {fnt = f;}
	Font font() const { return Font(fnt); }

	void set_font_size(int sz) { fnt_sz = sz; }
	int font_size() const { return fnt_sz; }

	int height() const { return h; }
	int width() const { return w; }
private:
	int w, h;
	int arc_ratio = 6;

	string lab;
	Font fnt { fl_font() };
	int fnt_sz { 20<fl_size() ? fl_size() : 20 };
};

struct Arrow : Shape
{
	Arrow(Point a, Point b) 
	{
		add(a);
		add(b);
	}

	void calc_points();
	void draw_lines() const;
};


int main()
{
    using namespace Graph_lib;

    Simple_window win{Point{100,100}, 800, 800, "testing"};

    Box box {Point{100,100}, 100, 75, "teszt"};
    box.set_fill_color(Color::yellow);
    box.set_color(Color::green);
    Rectangle keret {Point{100,100}, 300, 150 };

    Arrow arr {Point{600,200}, Point{750,300}};

    //win.attach(keret);
    win.attach(box);
    win.attach(arr);
    win.wait_for_button();
}




void Arc::draw_lines() const
{
	if (fill_color().visibility()){
		fl_color(fill_color().as_int());
		fl_pie(point(0).x, point(0).y, 2 * w, 2 * h, b_ang, e_ang);
		fl_color(color().as_int());
	}

	if (color().visibility()){
		fl_color(color().as_int());
		fl_arc(point(0).x, point(0).y, 2 * w, 2 * h, b_ang, e_ang);
	}
}

void Box::draw_lines() const
{
	int arc_w = (w / arc_ratio) * 2;
	int arc_h = (h / arc_ratio) * 2;

	Point a1{ point(0).x, point(0).y }; //top left corner of the rectangle 'containing' the arc
	Point a2{ point(0).x, point(0).y + h - arc_h };
	Point a3{ point(0).x + w - arc_w, point(0).y };
	Point a4{ point(0).x + w - arc_w, point(0).y + h - arc_h};

	Line l1{Point{point(0).x + w / arc_ratio, point(0).y},Point{a3.x + w / arc_ratio, point(0).y}};	//---
	Line l2{Point{point(0).x, a1.x + h / arc_ratio},Point{a2.x, a2.y + h / arc_ratio}};	// | x
	Line l3{Point{a3.x + arc_w, a3.y + h / arc_ratio},Point{a4.x + arc_w, a4.y + h / arc_ratio}};	// x |
	Line l4{Point{a2.x + w / arc_ratio, a2.y + arc_h},Point{a4.x + w / arc_ratio, a4.y + arc_h}};	// ___

	if (fill_color().visibility())
	{
		fl_color(fill_color().as_int());

		fl_pie(a1.x, a1.y, arc_w, arc_h, 90, 180);
		fl_pie(a2.x, a2.y, arc_w, arc_h, 180, 270);
		fl_pie(a3.x, a3.y, arc_w, arc_h, 90, 0);
		fl_pie(a4.x, a4.y, arc_w, arc_h, 270, 360);

		fl_rectf(l1.point(0).x, l1.point(0).y, w - arc_w, h);
		fl_rectf(l2.point(0).x, l2.point(0).y, w, h - arc_h);

		fl_color(color().as_int());
	}

	if (color().visibility())
	{
		fl_color(color().as_int());

		fl_arc(a1.x, a1.y, arc_w, arc_h, 90, 180);
		fl_arc(a2.x, a2.y, arc_w, arc_h, 180, 270);
		fl_arc(a3.x, a3.y, arc_w, arc_h, 90, 0);
		fl_arc(a4.x, a4.y, arc_w, arc_h, 270, 360);

		
		fl_line(l1.point(0).x, l1.point(0).y, l1.point(1).x, l1.point(1).y);
		fl_line(l2.point(0).x, l2.point(0).y, l2.point(1).x, l2.point(1).y);
		fl_line(l3.point(0).x, l3.point(0).y, l3.point(1).x, l3.point(1).y);
		fl_line(l4.point(0).x, l4.point(0).y, l4.point(1).x, l4.point(1).y);
	}


	if (lab != "")
	{
		int ofnt = fl_font();
		int osz = fl_size();
		fl_font(fnt.as_int(), fnt_sz);
		fl_draw(lab.c_str(), point(1).x, point(1).y);
		fl_font(ofnt, osz);
	}
}


void Arrow::draw_lines() const 
{
		//https://math.stackexchange.com/questions/2125690/find-coordinates-of-3rd-right-triangle-point-having-2-sets-of-coordinates-and-a
		int arrowSize = 50;
		double halfA = arrowSize / 2;
		Point p1(point(0).x, point(0).y);
		Point p2(point(1).x, point(1).y);

		double distance = sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));

		Point p3(halfA / distance * p1.x + (1 - halfA / distance)*p2.x,
			halfA / distance * p1.y + (1 -halfA / distance)*p2.y);
	
		double lx = p3.x + ((halfA * (p2.y - p1.y)) / distance);
		double ly = p3.y + ((halfA * (p1.x - p2.x)) / distance);

		double rx = p3.x + ((halfA * (p1.y - p2.y)) / distance);
		double ry = p3.y + ((halfA * (p2.x - p1.x)) / distance);
		
		if (fill_color().visibility())
		{	
			fl_color(fill_color().as_int());
			fl_begin_complex_polygon();
			fl_vertex(p2.x, p2.y);
			fl_vertex(lx, ly);
			fl_vertex(rx, ry);
			fl_end_complex_polygon();
			fl_color(color().as_int());
		}
		
		if (color().visibility())
		{
			fl_line(p1.x, p1.y, p3.x, p3.y);
			fl_line(lx, ly, rx, ry);
			fl_line(p2.x, p2.y, rx, ry);
			fl_line(lx, ly, p2.x, p2.y);
		}
}