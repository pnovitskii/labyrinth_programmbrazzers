#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Cell
{
public:
	Texture texture;
public:
	Sprite sprite;
	bool path = false;
	bool wall = false;
	Cell(){}
	Cell(int x, int y)
	{
		sprite.setPosition(x * 10, y * 10);
	}
//public:
	void init(int x, int y);
};
