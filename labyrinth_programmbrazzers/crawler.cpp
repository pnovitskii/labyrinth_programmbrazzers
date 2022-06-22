#include "crawler.h"
#include "field.h"
Crawler::Crawler()
{
	head_t.loadFromFile("graphics/head.png");
	head_s.setTexture(head_t);

	head_s.setPosition((float)position.y * 10, (float)position.x * 10);
}
//bool CrawlercheckMove(Vector2i dir)
//{
//
//}
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

Vector2i Crawler::move(Vector2i dir, Field &field)
{
	Vector2i pos = this->position;
	//cout << field.matrix[pos.x][pos.y].wall << endl;
	int newX = pos.x + dir.x;
	int newY = pos.y + dir.y;
	//if (newX == 59 && newY == 80)
		//exit();
	if (!(newX > 0 && newX < 60 && newY > 0 && newY < 80) || (field.matrix[newX][newY].wall == true))
	{
		dir = { 0, 0 };
		return Vector2i(-1, -1);//false;
	}


	if (dir.y == 1)
		this->moveRight();
	else if (dir.y == -1)
		this->moveLeft();
	else if (dir.x == 1)
		this->moveDown();
	else if (dir.x == -1)
		this->moveUp();
	dir = { 0, 0 };
	return this->position;//true;
}

void Crawler::updateHead()
{
	head_s.setPosition((float)position.y * 10, (float)position.x * 10);
}

