#pragma once
#include <SFML/Graphics.hpp>
#include "field.h"
#include "crawler.h"
#include <iostream>
class Strategy{
public:
	virtual Vector2i step(Field& field, Crawler& crawler) { return Vector2i(); }
};
using namespace std;
class DirActionCreators {
public:
	Vector2i UpActionCreator() { return(Vector2i(-1, 0)); }
	Vector2i DownActionCreator() { return(Vector2i(1, 0)); }
	Vector2i LeftActionCreator() { return(Vector2i(0, -1)); }
	Vector2i RightActionCreator() { return(Vector2i(0, 1)); }
};


class Controller
{
public:
	RenderWindow window;
	Field field;
	Crawler crawler;
	DirActionCreators actions;
	Strategy *strategy = NULL;
	Controller();
	void update();
	bool status();
	void exit();
	void draw();
	void updateCrawler();
	bool moveCrawler(Vector2i dir);
	void step();
	void setStrategy(Strategy *str) { 
		delete strategy;
		strategy = str; 
	}
};
