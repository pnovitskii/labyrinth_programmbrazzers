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

	Controller();
	void update();
	bool status();
	void draw();
	void updateCrawler();
};