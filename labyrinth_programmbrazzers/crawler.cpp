#include "crawler.h"

void Crawler::moveUp()
{
	position.x--;
}

void Crawler::moveLeft()
{
	position.y--;
}

void Crawler::moveDown()
{
	position.x++;
}

void Crawler::moveRight()
{
	position.y++;
}
