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
	Vector2i newPosition = strategy.step(field, crawler);
	cout << newPosition.x << " " << newPosition.y << endl;
	updateCrawler();
	//field.matrix[newPosition.x][newPosition.y].path = true;
}
//Vector2i Controller::find()
//{
//	//List list;
//	/*function<bool()> check ;
//	function<bool()> go;*/
//	cout << strategy.go << endl;
//	Vector2i check;
//	Vector2i go;
//	if (strategy.go == 0) {
//		check = { 1, 0 };
//		go = { 0, 1 };
//	}
//	else if (strategy.go == 1) {
//		check = { 0, -1 };
//		go = { 1, 0 };
//	}
//	else if (strategy.go == 2) {
//		check = { -1, 0 };
//		go = { 0 , -1 };
//	}
//	else if (strategy.go == 3) {
//		check = { 0, 1 };
//		go = { -1, 0 };
//	}
//
//	if (moveCrawler(check))
//	{
//		strategy.go = (strategy.go + 1) % 4;
//		return;
//	}
//	else if (!moveCrawler(go))
//	{
//		if (strategy.go == 0)
//			strategy.go = 3;
//		else
//			strategy.go -= 1;
//	}  
//}
void Controller::exit()
{
	window.close();
}

Vector2i RightHand::step(Field &field, Crawler &crawler)
{
	Vector2i check;
	Vector2i go;
	if (this->go == 0) {
		check = { 1, 0 };
		go = { 0, 1 };
	}
	else if (this->go == 1) {
		check = { 0, -1 };
		go = { 1, 0 };
	}
	else if (this->go == 2) {
		check = { -1, 0 };
		go = { 0 , -1 };
	}
	else if (this->go == 3) {
		check = { 0, 1 };
		go = { -1, 0 };
	}

	if (crawler.move(check, field) != Vector2i(-1, -1))
	{
		this->go = (this->go + 1) % 4;
		return crawler.position;
	}
	else if (crawler.move(go, field) == Vector2i(-1, -1))
	{
		if (this->go == 0)
			this->go = 3;
		else
			this->go -= 1;
	}
	return crawler.position;
}
