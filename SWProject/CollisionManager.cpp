#include "pch.h"
#include "CollisionManager.h"
#include "Collider.h"
#include "Object.h"

void CollisionManager::Init()
{
}

void CollisionManager::Update()
{
	vector<Collider*> colliders = _colliders; // 일단 참조로 받지만 괜찮을까..?

	for (int i = 0; i < colliders.size(); i++)
	{
		for (int j = i + 1; j < colliders.size(); j++)
		{
			Collider* src = colliders[i];
			Collider* dest = colliders[j];

			if (src->CheckCollision(dest))
			{
				if (src->_collisionMap.contains(dest) == false) // 처음 충돌이다.
				{
					src->GetOwner()->OnComponentBeginOverlap(src, dest);
					dest->GetOwner()->OnComponentBeginOverlap(dest, src);
					src->_collisionMap.insert(dest);
					dest->_collisionMap.insert(src);
				}
			}
			else
			{
				if (src->_collisionMap.contains(dest)) // 포개진게 방금 끝났다. OnComponentBeginOverlap, OnComponentEndOverlap 가 한번씩만 호출되도록 하는거.
				{
					src->GetOwner()->OnComponentEndOverlap(src, dest);
					dest->GetOwner()->OnComponentEndOverlap(dest, src);
					src->_collisionMap.erase(dest);
					dest->_collisionMap.erase(src);
				}
			}
		}
	}
}

void CollisionManager::AddCollider(Collider* collider)
{
	_colliders.push_back(collider);
}

void CollisionManager::RemoveCollider(Collider* collider)
{
	if (collider == nullptr)
		return;

	auto it = std::remove(_colliders.begin(), _colliders.end(), collider);
	_colliders.erase(it, _colliders.end());
}
