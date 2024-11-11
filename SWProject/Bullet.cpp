#include "pch.h"
#include "Bullet.h"
#include "SphereCollider.h"
#include "Creature.h"
#include "CollisionManager.h"
#include "SceneManager.h"
#include "TimeManager.h"

Bullet::Bullet() : Object(ObjectType::Bullet)
{
}

Bullet::~Bullet()
{
}

void Bullet::Init()
{
	_collider = new SphereCollider(_radius);
	_collider->AddCollisionFlagLayer(COLLISION_LAYER_TYPE::CLT_OBJECT);

	GET_SINGLE(CollisionManager)->AddCollider(_collider);
	GET_SINGLE(SceneManager)->Add(this);
}

void Bullet::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	Vector move[4] = { {0,-1}, {0,1}, {-1,0}, {1,0} };

	_pos += move[_dir] * _speed * deltaTime;
}

void Bullet::Render(HDC hdc)
{
	HBRUSH myBrush = (HBRUSH)::GetStockObject(NULL_BRUSH);
	HBRUSH oldBrush = (HBRUSH)::SelectObject(hdc, myBrush);
	Utils::DrawCircle(hdc, _pos, _radius);
	::SelectObject(hdc, oldBrush);
	::DeleteObject(myBrush);
}

void Bullet::OnComponentBeginOverlap(Collider* src, Collider* dest)
{
	dynamic_cast<Creature*>(dest->GetOwner())->OnDamaged(_damage);

	GET_SINGLE(CollisionManager)->RemoveCollider(_collider);
	GET_SINGLE(SceneManager)->Remove(this);

	// ±¦ÂúÀ»±î..?
	delete this;
	return;
}

void Bullet::OnComponentEndOverlap(Collider* src, Collider* dest)
{

}
