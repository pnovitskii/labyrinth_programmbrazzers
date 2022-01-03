#include "field.h"
#include <iostream>
using namespace std;

Field::Field()
{
	background_image.loadFromFile("graphics/background1.png");
	background_texture.loadFromImage(background_image);
	background_sprite.setTexture(background_texture);
	background_sprite.setPosition(0, 0);
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
	
	for (int i = 0; i < 61; i++)
	{
		for (int j = 0; j < 81; j++)
		{
			if ((int)background_image.getPixel(j * 10, i * 10).r == 0)
			{
				matrix[i][j].wall = true;
				
			}
				//x[i][j] = 1;
				
		}
		
	}
	

}
bool Field::checkWall(int x, int y)
{
	return matrix[x][y].wall;
}
void Field::setPath(int x, int y)
{
	matrix[x][y].sprite.setTexture(path_t);
	//cout << (int)background_image.getPixel(y * 10, x * 10).r << " " << (int)background_image.getPixel(y * 10, x * 10).g << " " << (int)background_image.getPixel(y * 10, x * 10).b << endl;
	
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
