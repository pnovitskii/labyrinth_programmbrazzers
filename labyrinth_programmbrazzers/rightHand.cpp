#include "controller.h"
#include "rightHand.h"
Vector2i RightHand::step(Field& field, Crawler& crawler)
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