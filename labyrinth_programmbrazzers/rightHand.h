#pragma once
#include "controller.h"
class RightHand : public Strategy {
public:
	int go = 0;
	Vector2i step(Field& field, Crawler& crawler);
};