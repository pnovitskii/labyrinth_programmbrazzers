#include "left_hand.h"

bool LeftHand::frontWall(Cell **matrix)
{
	if (matrix[position.x+direction.y][position.y+direction.x].wall == true)
		return false;
	return true;
}
