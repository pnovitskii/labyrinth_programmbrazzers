#include "controller.h"
#include <functional>
class Node {
	vector<Node*> next;
	Node* prev = NULL;
	int x = 0;
	int y = 0;
public:
	Node(int x, int y, Node* prev)
	{
		this->x = x;
		this->y = y;
		this->prev = prev;
	}
};
class List {
	Node* start = NULL;// new  Node(1, 0, NULL);
public:
	List(Node* start)
	{
		this->start = start;
	}
	/*void push(int x, int y, Node* prev) {

	}*/
};
Controller::Controller()
{
	window.create(VideoMode(810, 610), "Labyrinth");
	field.initWalls();
	//setStrategy(RightHand());
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
	window.draw(field.background_sprite);
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

bool Controller::moveCrawler(Vector2i dir)
{
	Vector2i pos = crawler.position;
	//cout << field.matrix[pos.x][pos.y].wall << endl;
	int newX = pos.x + dir.x;
	int newY = pos.y + dir.y;
	if (newX == 59 && newY == 80)
		exit();
	if (!(newX > 0 && newX < 60 && newY > 0 && newY < 80) || (field.matrix[newX][newY].wall == true))
	{
		dir = { 0, 0 };
		return false;
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
	return true;
}
void Controller::step()
{
	if (strategy == NULL) return;
	for (int i = 0; i < 1; i++) {
		Vector2i newPosition = strategy->step(field, crawler);
		cout << newPosition.x << " " << newPosition.y << endl;
		updateCrawler();
	}
}

void Controller::exit()
{
	window.close();
}


