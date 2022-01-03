#pragma once
#include "controller.h"
class Dnq : public Crawler
{
	void find();
	bool judge(Cell cell);
	void find(int l, int r);
	int dx[4] = { 0,1,0, -1 }; // перемещение пути в направлении x
	int dy[4] = { 1,0,-1,0 };
	int n, m;
	int starti, startj;
	int endi, endj;
};
struct Node
{
	int i;
	int j;
	int s;
};