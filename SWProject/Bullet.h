#pragma once
#include <iostream>

class Bullet
{
public:
	int _x, _y;
	int _previousY;

	Bullet(int startX, int startY):_x(startX), _y(startY), _previousY(startY+1){}

	void MoveUp();
	void Clear() const;
	void Draw() const;
};