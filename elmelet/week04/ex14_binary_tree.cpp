/*
    g++ ex14_binary_tree.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ex14_binary_tree `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

struct Binary_tree : Shape{

	Binary_tree(Point p, int lvl, string at_type = "line", Color at_color = fl_color() ) : levels{lvl}, acolor{at_color}, atype{at_type}
	{
		if(lvl > 0)
		{
			add(p);
			add_node(p, 1, "");
		}
		if(atype != "line" && atype != "arrow") error("Wrong attaching tpye given in constructor!\n");
	}

	virtual void draw_lines() const;
	void draw_attach() const;
	void draw_path() const;

	int get_levels() { return levels; }
	void set_radius(int rr) { r = rr; }
	void set_attach_type(string t) { if(atype == "line" || atype == "arrow") atype = t; else error("Wrong attaching tpye given in set_attach_type!\n");}
	void set_attach_color(Color col) { acolor = col; }

protected:
	int levels;
	int r = 25;
	Vector_ref<Lines> lines;
	Vector_ref<Text> cord;
	string atype; //line or arrow
	Color acolor;
	int node_num = pow(2,levels) - 1;

	void add_node(Point point, int rlvl, string path);
};

struct Modified_Binary_tree : Binary_tree{
	
	Modified_Binary_tree(Point p, int lvl, string at_type = "line", Color at_color = fl_color() ): Binary_tree(p, lvl, at_type, at_color) {}

	void draw_lines() const override;
};


int main()
{
    using namespace Graph_lib;
    Simple_window win{Point{100,100}, 1200, 1200, "binary tree v1"};

    for(int i = 0;i <= 5; ++i)
    {
    	Modified_Binary_tree test_fa {Point{600, 150}, i, "arrow", Color::red}; //goes funky over lvl 6
        
        win.attach(test_fa);
        win.set_label(string(1, i));
        win.wait_for_button();
    }


    //win.wait_for_button();
}





void Binary_tree::add_node(Point point, int rlvl, string path)
{
	if(rlvl == 1) 
		{
			cord.push_back(new Text{Point{point.x + 5, point.y + r}, "root"});
		}
	if( rlvl != levels )
	{
		int node_dis = levels * r * 2 / rlvl;
		Point lp {point.x - node_dis, point.y + 3*r};
		Point rp {point.x + node_dis, point.y + 3*r};

		if(atype == "line")
		{
			lines.push_back(new Lines{Point{point.x + r, point.y + 2*r},Point{lp.x + r, lp.y}});
			lines.push_back(new Lines{Point{point.x + r, point.y + 2*r},Point{rp.x + r, rp.y}});
		}
		else
		{
			int arrow_length = 10;
			lines.push_back(new Lines{Point{point.x + r, point.y + 2*r},Point{lp.x + r, lp.y}});
			lines.push_back(new Lines{Point{lp.x + r, lp.y}, Point{lp.x + r, lp.y - arrow_length}}); //goes up from connecting point
			lines.push_back(new Lines{Point{lp.x + r, lp.y}, Point{lp.x + r + arrow_length, lp.y}}); //goes rigth from c. p.

			lines.push_back(new Lines{Point{point.x + r, point.y + 2*r},Point{rp.x + r, rp.y}});
			lines.push_back(new Lines{Point{rp.x + r, rp.y}, Point{rp.x + r, rp.y - arrow_length}});
			lines.push_back(new Lines{Point{rp.x + r, rp.y}, Point{rp.x + r - arrow_length, rp.y}});
		}

		string lpath = path + "l"; cord.push_back(new Text{Point{lp.x + 5, lp.y + r}, lpath});
		string rpath = path + "r"; cord.push_back(new Text{Point{rp.x + 5, rp.y + r}, rpath});

		add(lp); 
		//cout << "added lp node\t"; 
		add(rp);
		//cout << "added rp node\n";
		add_node(lp, rlvl+1, lpath);
		add_node(rp, rlvl+1, rpath);
	}
}

void Binary_tree::draw_lines() const
{
	if (color().visibility()){
		for(int i = 0; i < node_num; ++i)//nodes 
		{
			fl_color(color().as_int());
			fl_arc(point(i).x, point(i).y, r+r, r+r, 0, 360);
			//cout << point(i).x << "\t" << point(i).y << endl;
		}
	Binary_tree::draw_attach();
	Binary_tree::draw_path();
	}
}

void Modified_Binary_tree::draw_lines() const
{
	if (color().visibility()){
		for(int i = 0; i < node_num; ++i)//nodes 
		{
			fl_color(color().as_int());
			fl_rect(point(i).x, point(i).y, 2 * r, 2 * r);
		}
	Binary_tree::draw_attach();
	Binary_tree::draw_path();
	}
}


void Binary_tree::draw_attach() const
{
	if(color().visibility())
	{
		fl_color(acolor.as_int());
		if(atype == "line")
		{
			for(int i = 0;i < node_num -1; ++i)//lines
				fl_line(lines[i].point(0).x, lines[i].point(0).y, lines[i].point(1).x, lines[i].point(1).y);

		}
		else
		{
			for(int i = 0;i < (node_num - 1 ) * 3; ++i)//arrows
				fl_line(lines[i].point(0).x, lines[i].point(0).y, lines[i].point(1).x, lines[i].point(1).y);

		}
		fl_color(color().as_int());
	}
}

void Binary_tree::draw_path() const
{
	for(int i = 0; i < node_num; ++i)
	{
		cord[i].draw_lines();
	}
}