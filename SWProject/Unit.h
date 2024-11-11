#pragma once
#include "Creature.h"

class Unit : public Creature
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

