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

	Field();
	void draw(RenderWindow& window);
	void setPath(int x, int y);
	void initWalls();
	bool checkWall(int x, int y);
};