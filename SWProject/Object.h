#pragma once

class Object
{
	public:
		Object(ObjectType objectType);
		~Object();

		void Init();
		void Update();
		void Render();



	private:
		Pos _pos = { 0,0 };
		int _hp = 0;
		int _maxHp;
		ObjectType _objectType = ObjectType::None;
};

