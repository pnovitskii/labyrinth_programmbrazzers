#include "crawler.h"

Crawler::Crawler()
{
	head_t.loadFromFile("graphics/head.png");
	head_s.setTexture(head_t);

	head_s.setPosition((float)position.y * 10, (float)position.x * 10);
}

void Crawler::moveUp()
{
	position.x--;
	updateHead();
}

void Crawler::moveLeft()
{
	position.y--;
	updateHead();
}

void Crawler::moveDown()
{
	position.x++;
	updateHead();
}

void Crawler::moveRight()
{
	position.y++;
	updateHead();
}

void Crawler::updateHead()
{
	head_s.setPosition((float)position.y * 10, (float)position.x * 10);
}
