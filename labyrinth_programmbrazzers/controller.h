#pragma once
#include <SFML/Graphics.hpp>
#include "field.h"

class Controller
{
public:
	RenderWindow window;
	Field field;
	Texture background_texture;
	Sprite background_sprite;

	Controller();
	void update();
	bool status();
	void draw();
};