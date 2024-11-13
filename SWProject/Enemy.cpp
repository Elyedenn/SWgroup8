#include "pch.h"
#include "Enemy.h"
#include "Object.h"
#include "TimeManager.h"
#include "CollisionManager.h"
#include "SphereCollider.h"
#include "SceneManager.h"
#include "Scene.h"

Enemy::Enemy() : Creature(ObjectType::Enemy)
{
}

Enemy::~Enemy()
{
}

void Enemy::Init()
{
	Super::Init();

	_collider = new SphereCollider(_radius);
	_collider->SetOwner(this);
	_collider->SetCollisionLayer(CLT_ENEMY);
	_collider->AddCollisionFlagLayer(CLT_OBJECT);

	GET_SINGLE(SceneManager)->Add(this);
	GET_SINGLE(CollisionManager)->AddCollider(_collider);
}

void Enemy::Update()
{
	Super::Update();

	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	if (_isHit)
	{
		if (_sumTime < _hitTime)
			_sumTime += deltaTime;
		else
		{
			_sumTime = 0;
			_isHit = false;
		}
	}

	switch (_state)
	{
	case EnemyState::Move:
		MoveUpdate();
		break;
	case EnemyState::Attack:
		AttackUpdate();
		break;
	case EnemyState::Skill:
		SkillUpdate();
		break;
	}
}

void Enemy::Render(HDC hdc)
{
	Super::Render(hdc);

	if (_isHit)
	{
		HPEN myPen = ::CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)::SelectObject(hdc, myPen);

		HBRUSH myBrush = (HBRUSH)::CreateSolidBrush(RGB(255, 0, 0));
		HBRUSH oldBrush = (HBRUSH)::SelectObject(hdc, myBrush);

		Utils::DrawCircle(hdc, _pos, _radius);

		::SelectObject(hdc, oldPen);
		::DeleteObject(myPen);
		::SelectObject(hdc, oldBrush);
		::DeleteObject(myBrush);
	}
	else
	{
		HPEN myPen = ::CreatePen(PS_SOLID, 1, RGB(255, 0, 0)); // 새로운 색상 지정
		HPEN oldPen = (HPEN)::SelectObject(hdc, myPen); // 옛날 색상 기억

		Utils::DrawCircle(hdc, _pos, _radius);

		::SelectObject(hdc, oldPen); // 다시 색상을 옛날걸로 변경 (안해주면 모든게 빨간색이 된다.)
		::DeleteObject(myPen);
	}
}

//***********************************
//				TICK
//***********************************

void Enemy::MoveUpdate()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	Vector move[4] = { {0,-1}, {0,1}, {-1,0}, {1,0} };

	_pos += move[_dir] * _speed * deltaTime;


	RECT unitSpace = GET_SINGLE(SceneManager)->GetCurrentScene()->GetUnitSpace();
	switch (_dir)
	{
	case DIR_DOWN:
		if (_pos.y >= unitSpace.top - _radius)
			ChangeState(EnemyState::Attack);
		break;
	case DIR_UP:
		if (_pos.y <= unitSpace.bottom + _radius)
			ChangeState(EnemyState::Attack);
		break;
	case DIR_RIGHT:
		if (_pos.x >= unitSpace.left - _radius)
			ChangeState(EnemyState::Attack);
		break;
	case DIR_LEFT:
		if (_pos.x <= unitSpace.right + _radius)
			ChangeState(EnemyState::Attack);
		break;
	}
}

void Enemy::AttackUpdate()
{
	// TODO
}

void Enemy::SkillUpdate()
{
}

void Enemy::ChangeState(EnemyState state)
{
	_state = state;
	// sumTime = 0 등
}


void Enemy::OnDamaged(int32 damage)
{
	_isHit = true;

	_hp = max(0, _hp - damage);

	if (_hp <= 0)
		OnDead();
}

void Enemy::OnDead()
{
	// TODO 골드 추가 등
	GET_SINGLE(CollisionManager)->RemoveCollider(_collider);
	GET_SINGLE(SceneManager)->Remove(this);
}

void Enemy::OnComponentBeginOverlap(Collider* src, Collider* dest)
{
}

void Enemy::OnComponentEndOverlap(Collider* src, Collider* dest)
{
}

