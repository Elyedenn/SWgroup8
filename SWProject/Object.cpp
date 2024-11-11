#include "pch.h"
#include "Object.h"
#include <iostream>
#include <thread>
#include "Bullet.h"


Object::Object(ObjectType objectType) : _objectType(objectType)
{

}

Object::~Object()
{
}

void Object::HideCursor() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void Object::Init()
{
	HideCursor();
	_lastFireTime = std::chrono::steady_clock::now();
	std::cout << "\033[" << _unitY + 1 << ";" << _unitX + 1 << " H¡á";
}

void Object::Update()
{
	auto now = std::chrono::steady_clock::now();
	auto timeSinceLastFire = std::chrono::duration_cast<std::chrono::milliseconds>(now - _lastFireTime).count();

	if (timeSinceLastFire >= _fireIntervalMs) {
		_bullets.push_back(Bullet(_unitX, _unitY - 1));
		_lastFireTime = now;
	}

	for (auto& bullet : _bullets) {
		bullet.Clear();
		bullet.MoveUp();
	}

	_bullets.erase(std::remove_if(_bullets.begin(), _bullets.end(), [](Bullet& b) { return b._y < 0; }), _bullets.end());

	std::cout << "\033[" << _unitY + 1 << ";" << _unitX + 1 << "H¡á";
	for (const auto& bullet : _bullets) {
		bullet.Draw();
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(50));
}

void Object::Render()
{
}
