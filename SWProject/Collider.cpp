#include "pch.h"
#include "Collider.h"
#include "SphereCollider.h"
#include "BoxCollider.h"
#include "Object.h"

Collider::Collider(ColliderType colliderType) : _colliderType(colliderType)
{
}

Collider::~Collider()
{
}

void Collider::Init()
{
}

void Collider::Update()
{
}

void Collider::Render(HDC hdc)
{
}

bool Collider::CheckCollision(Collider* other)
{
	uint32 layer = other->GetCollisionLayerType();
	if (_collisionFlag & (1 << layer)) // 상대방이 나랑 충돌하고 싶어하나? 체크
		return true;

	return false;
}

bool Collider::CheckCollisionBox2Box(BoxCollider* b1, BoxCollider* b2)
{
		RECT r1 = b1->GetRect();
		RECT r2 = b2->GetRect();

		RECT intersect = {};
		return ::IntersectRect(&intersect, &r1, &r2);
}

bool Collider::CheckCollisionSphere2Box(SphereCollider* s1, BoxCollider* b2)
{
	return false;
}

bool Collider::CheckCollisionSphere2Sphere(SphereCollider* s1, SphereCollider* s2)
{
	Vector v1 = s1->GetOwner()->GetPos();
	float r1 = s1->GetRadius();
		
	Vector v2 = s2->GetOwner()->GetPos();
	float r2 = s2->GetRadius();

	Vector dir = v2 - v1;
	float dist = dir.Length();


	return dist <= (r1 + r2);
}

void Collider::AddCollisionFlagLayer(COLLISION_LAYER_TYPE layer)
{
	_collisionFlag |= (1 << layer);
}

void Collider::RemoveCollisionFlagLayer(COLLISION_LAYER_TYPE layer)
{
	_collisionFlag &= ~(1 << layer);
}
