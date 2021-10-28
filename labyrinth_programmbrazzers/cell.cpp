#include <iostream>
#include "cell.h"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

void Cell::setTexture(Texture texture)
{
	sprite.setTexture(texture);
}
