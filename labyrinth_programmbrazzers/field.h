#pragma once
#include <SFML/Graphics.hpp>
#include "cell.h"
using namespace sf;

class Field
{
public:
	Cell** matrix;
	Texture path_t;
public:
	Field()
	{
		matrix = new Cell * [61];
		for (int i = 0; i < 61; i++)
		{
			matrix[i] = new Cell[81];
		}
		path_t.loadFromFile("graphics/path.png");
		for (int i = 0; i < 61; i++)
		{
			for (int j = 0; j < 81; j++)
			{
				
				matrix[i][j].sprite.setPosition(j * 10, i * 10);
			}
		}
	}
	void draw(RenderWindow& window);
	void setPath(int x, int y);
};