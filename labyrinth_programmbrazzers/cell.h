#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Cell
{
	Vector2i position;
	Sprite sprite;
public:
	Cell(int x, int y, Texture texture)
	{
		position = { x, y };
		sprite.setTexture(texture);
	}
};