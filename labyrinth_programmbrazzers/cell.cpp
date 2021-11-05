#include <iostream>
#include "cell.h"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

void Cell::init(int x, int y)
{
	//position = {};
	sprite.setPosition(x * 10, y * 10);
	//sprite.setTexture(texture);
}
