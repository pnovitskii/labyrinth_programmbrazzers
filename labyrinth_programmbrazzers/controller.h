#pragma once
#include <SFML/Graphics.hpp>
#include "field.h"
#include "crawler.h"
#include <iostream>
using namespace std;
class Controller
{
public:
	RenderWindow window;
	Field field;
	
	
	Crawler crawler;
	//Vector2i dir = { 0, 0 };
	//moveDir dir = idle;
	Controller();
	void update();
	bool status();
	void exit();
	void draw();
	void updateCrawler();
	//void setDir(Vector2i d);
	bool moveCrawler(Vector2i dir);
};