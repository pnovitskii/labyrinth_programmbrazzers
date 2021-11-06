#pragma once
#include <SFML/Graphics.hpp>
#include "field.h"
#include "crawler.h"
class Controller
{
public:
	RenderWindow window;
	Field field;
	Texture background_texture;
	Sprite background_sprite;
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
	void moveCrawler(Vector2i dir);
};