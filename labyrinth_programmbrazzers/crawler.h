#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
class Crawler
{
public:
	Vector2i position = {1, 0};
	void moveUp();
	void moveLeft();
	void moveDown();
	void moveRight();
};