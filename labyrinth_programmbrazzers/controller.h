#pragma once
#include <SFML/Graphics.hpp>
#include "field.h"
#include "crawler.h"
#include <iostream>
class Strategy{
public:
	virtual void step(){}
};
using namespace std;
class DirActionCreators {
public:
	Vector2i UpActionCreator() { return(Vector2i(-1, 0)); }
	Vector2i DownActionCreator() { return(Vector2i(1, 0)); }
	Vector2i LeftActionCreator() { return(Vector2i(0, -1)); }
	Vector2i RightActionCreator() { return(Vector2i(0, 1)); }
};
class RightHand : Strategy {
public:
	//int str[4] = { 0, 1, 2, 3 };
	int go = 0;
	Vector2i step(Field &field, Crawler &crawler);// {
		/*Vector2i check;
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

		if (moveCrawler(check))
		{
			this->go = (this->go + 1) % 4;
			return;
		}
		else if (!moveCrawler(go))
		{
			if (this->go == 0)
				this->go = 3;
			else
				this->go -= 1;
		}*/
	//}
};

class Controller
{
public:
	RenderWindow window;
	Field field;
	
	
	Crawler crawler;
	DirActionCreators actions;
	RightHand strategy;
	//Vector2i dir = { 0, 0 };
	//moveDir dir = idle;
	Controller();
	void update();
	bool status();
	void exit();
	void draw();
	void updateCrawler();
	//void setDir(Vector2i d);
	bool moveCrawler(Vector2i dir);
	void step();
	
	Vector2i find();
};
