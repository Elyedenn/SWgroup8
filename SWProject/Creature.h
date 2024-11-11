#pragma once
#include "Object.h"

class Creature : public Object
{
public:
	Creature(ObjectType type);
	virtual ~Creature() {};

	virtual void Init() {};
	virtual void Update() {};
	virtual void Render(HDC hdc) {};

public:
	virtual void OnComponentBeginOverlap(Collider* src, Collider* dest) {};
	virtual void OnComponentEndOverlap(Collider* src, Collider* dest) {};
	virtual void OnDamaged(int damage) {};
};

