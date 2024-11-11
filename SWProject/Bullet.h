#pragma once
#include "Object.h"

class SphereCollider;

class Bullet : public Object
{
public:
	Bullet();
	~Bullet();

	void Init();
	void Update();
	void Render(HDC hdc);

	virtual void OnComponentBeginOverlap(Collider* src, Collider* dest) override;
	virtual void OnComponentEndOverlap(Collider* src, Collider* dest) override;

	float GetRadius() { return _radius; }
	void SetRadius(float radius) { _radius = radius; }


private:
	int _damage = 10;
	int _speed = 100;
	float _radius = 50.f;
	SphereCollider* _collider = nullptr;
};

