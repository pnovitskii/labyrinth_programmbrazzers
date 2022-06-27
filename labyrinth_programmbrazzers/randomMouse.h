#pragma once
#include "controller.h"
#include <vector>
#include <time.h>
#include <cstdlib>
class RandomMouse : public Strategy {
public:
	int go = 0;
	Vector2i prev;
	
	Vector2i step(Field& field, Crawler& crawler) {
		srand(time(NULL));
		vector<Vector2i> arr(4, Vector2i(-1, -1));
		
		Vector2i pos = crawler.position;
		Vector2i up = Vector2i(pos.x - 1, pos.y);
		Vector2i down = Vector2i(pos.x + 1, pos.y);
		Vector2i left = Vector2i(pos.x, pos.y - 1);
		Vector2i right = Vector2i(pos.x, pos.y + 1);
		if (field.matrix[up.x][up.y].wall == false)// && up != prev)
			arr[0]=up;
		if (field.matrix[down.x][down.y].wall == false)// && down != prev)
			arr[1]=down;
		if (field.matrix[left.x][left.y].wall == false)// && left != prev)
			arr[2]=left;
		if (field.matrix[right.x][right.y].wall == false)// && right != prev)
			arr[3]=right;
		if (1)
		{
			//for (auto x : arr)
				//cout << x.x << " " << x.y << endl;
			bool flag = false;
			int counter = 0;
			for (int i = 0; i < 4; i++)
			{
				if (arr[i] == Vector2i(-1, -1)) {
					counter++;
					//arr.erase(arr.begin() + i);
				}
			}
			if (counter == 3)
			{
				for (int i = 0; i < 4; i++)
				{
					if (arr[i] != Vector2i(-1, -1))
						if (arr[i] == prev)
							flag = true;
							//prev = Vector2i(-1, -1);
				}
				
			}
			int randDir = rand()%arr.size();
			cout << randDir << endl;
			Vector2i dir = arr[randDir];
			if (dir != Vector2i(-1, -1)) {
				cout << "yes\n";
				if (dir == prev && flag == false)
					return Vector2i();
				//if (!flag)
				prev = pos;
				int newX = pos.x + dir.x;
				int newY = pos.y + dir.y;
				if (randDir == 3)
					crawler.moveRight();
				else if (randDir == 2)
					crawler.moveLeft();
				else if (randDir == 1)
					crawler.moveDown();
				else if (randDir == 0)
					crawler.moveUp();
				//break;
			}
				
			
			
		}
		return Vector2i();
	}
};