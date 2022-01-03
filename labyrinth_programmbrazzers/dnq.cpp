#include "dnq.h"
#include "cell.h"
#include <queue>
void Dnq::find()
{

}

bool Dnq::judge(Cell cell)
{
	int x = cell.sprite.getPosition().x / 10;
	int y = cell.sprite.getPosition().y / 10;
	if (x < 0 || x >= 81 || y < 0 || y >= 61)
		return true;
	if (cell.path == true)
		return true;
	if (cell.wall == true)
		return true;

	return false;
}
void Dnq::find(int l, int r)
{
	queue<Node> q;
	Node cur, next;
	int ni, nj;
	cur.i = starti;
	cur.j = startj;
	cur.s = 0;
	visited[starti][startj] = true;
	q.push(cur);
	while (!q.empty())
	{
		cur = q.front();
		q.pop();
		if (cur.i == endi && cur.j == endj)
			return cur;
		for (int i = 0; i < 4; i++)
		{
			// Четыре метода обхода
			ni = cur.i + dx[i];
			nj = cur.j + dy[i];
			if (judge(ni, nj))
			{
				// Если этот шаг не работает, попробуйте следующий шаг
				continue;
			}
			// можешь идти
			next.i = ni;
			next.j = nj;
			next.s = cur.s + 1;
			q.push(next);
		}

	}
	return cur;
}