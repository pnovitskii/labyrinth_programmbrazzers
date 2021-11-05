#include "controller.h"

Controller::Controller()
{
	window.create(VideoMode(810, 610), "Labyrinth");
	background_texture.loadFromFile("graphics/background.png");
	background_sprite.setTexture(background_texture);
	background_sprite.setPosition(0, 0);
}
void Controller::update()
{
	
}

bool Controller::status()
{
	return window.isOpen();
}
void Controller::draw()
{
	window.clear(Color::White);
	window.draw(background_sprite);
	window.display();
}
