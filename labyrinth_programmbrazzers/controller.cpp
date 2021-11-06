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
	field.draw(window);
	window.draw(crawler.head_s);
	window.display();
}

void Controller::updateCrawler()
{
	if (field.matrix[crawler.position.x][crawler.position.y].path == false)
	{
		field.setPath(crawler.position.x, crawler.position.y);
	}
}

void Controller::moveCrawler(Vector2i dir)
{
	Vector2i pos = crawler.position;
	int newX = pos.x + dir.x;
	int newY = pos.y + dir.y;
	if (newX == 59 && newY == 80)
		exit();
	if (!(newX > 0 && newX < 60 && newY > 0 && newY < 80))
	{
		dir = { 0, 0 };
		return;
	}
	if (dir.y == 1)
		crawler.moveRight();
	else if (dir.y == -1)
		crawler.moveLeft();
	else if (dir.x == 1)
		crawler.moveDown();
	else if (dir.x == -1)
		crawler.moveUp();
	dir = { 0, 0 };
}

void Controller::exit()
{
	window.close();
}


