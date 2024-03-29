#pragma once
#include <SFML/Graphics.hpp>
#include "field.h"
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
	//bool move(Vector2i dir);
	Vector2i move(Vector2i dir, Field &field);
	void updateHead();
};