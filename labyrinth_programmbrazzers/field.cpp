#include "field.h"
#include <iostream>
using namespace std;

Field::Field()
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
void Field::initWalls()
{
	//bool walls[61][81] = { 0 };
	//for (int i = 0; i < 61; i++)
		//walls[0][i] = 1;
	for (int i = 0; i < 81; i++)
		matrix[0][i].wall = 1;

}
bool Field::checkWall(int x, int y)
{
	return matrix[x][y].wall;
}
void Field::setPath(int x, int y)
{
	matrix[x][y].sprite.setTexture(path_t);
}
void Field::draw(RenderWindow& window)
{
	for (int i = 0; i < 61; i++)
	{
		for (int j = 0; j < 81; j++)
		{
			window.draw(matrix[i][j].sprite);
		}
	}
}
