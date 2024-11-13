#pragma once
#include "Creature.h"

class SphereCollider;

class Enemy : public Creature
{
	using Super = Creature;

public:
	Enemy();
	~Enemy();

	void Init();
	void Update();
	void Render(HDC hdc);

	void MoveUpdate();
	void AttackUpdate();
	void SkillUpdate();

	void ChangeState(EnemyState state);

	virtual void OnDamaged(int32 damage) override;
	virtual void OnDead() override;

	virtual void OnComponentBeginOverlap(Collider* src, Collider* dest) override;
	virtual void OnComponentEndOverlap(Collider* src, Collider* dest) override;

	float GetRadius() { return _radius; }
	void SetRadius(float radius) { _radius = radius; }


private:
	int32 _hp = 50;
	int32 _maxHp = 50;
	int32 _damage = 10;
	int32 _speed = 50;
	float _radius = 50.f;
	int32 _gold = 0;
	EnemyState _state = EnemyState::Move;


	float _sumTime = 0.0f;
	bool _isHit = false;
	const float _hitTime = 0.5f;
	

	SphereCollider* _collider = nullptr;
};

