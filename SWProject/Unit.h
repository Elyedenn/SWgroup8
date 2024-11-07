#pragma once
#include "Object.h"

class Unit : public Object
{
public:
	Unit();
	~Unit();

	void Init();
	void Update();
	void Render();

private:
	// 타일 배열
};

