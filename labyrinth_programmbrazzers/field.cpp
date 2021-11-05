#include "field.h"
#include <iostream>
using namespace std;
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
