#pragma once
#include <vector>
#include <chrono>

class Bullet;

class Object
{
	public:
		Object(ObjectType objectType);
		~Object();

		void Init();
		void Update();
		void Render();



	private:
		void HideCursor();

		Pos _pos = { 0,0 };
		int _hp = 10;
		int _maxHp = 10;
		ObjectType _objectType = ObjectType::None;

		int _unitX = 10;
		int _unitY = 19;
		std::vector<Bullet> _bullets;
		int _fireIntervalMs = 1000;
		std::chrono::steady_clock::time_point _lastFireTime;
};

