#pragma once
#include "Graphics.h"

class Paddle
{
public:
	int x = 750;
	int y;
	int vx;
	int size;
	float speed;
private:
	int originalX, originalY;
};

