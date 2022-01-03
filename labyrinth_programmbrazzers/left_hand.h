#pragma once
#include "controller.h"
#include <vector>
class LeftHand : public Crawler
{
	Vector2i direction = { 0, 1 };
	vector<Vector2i> arr;
	bool frontWall(Cell **matrix);
	
};