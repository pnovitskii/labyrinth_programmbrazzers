#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
class Crawler
{
public:
	Texture head_t;
	Sprite head_s;
	Vector2i position = {1, 0};

	Crawler();
	void moveUp();
	void moveLeft();
	void moveDown();
	void moveRight();
	
	void updateHead();
	//bool chw
};