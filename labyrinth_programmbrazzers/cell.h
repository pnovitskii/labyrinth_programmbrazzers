#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Cell
{
	Vector2i position;
	Sprite sprite;
public:
	void setSprite(Texture texture);
};