#include "pch.h"
#include "Bullet.h"
#include <iostream>


void Bullet::MoveUp() {
	if (_y >= 0) {
		_previousY = _y;
		--_y;
	}
}

void Bullet::Clear() const {
	if (_previousY >= 0) {
		std::cout << "\033[" << _previousY + 1 << ";" << _x + 1 << "H ";
	}
}

void Bullet::Draw() const {
	if (_y >= 0) {
		std::cout << "\033[" << _y + 1 << ";" << _x + 1 << "H*";
	}
}