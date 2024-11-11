#include "pch.h"
#include "SphereCollider.h"
#include "SceneManager.h"
#include "BoxCollider.h"
#include "Object.h"

SphereCollider::SphereCollider(float radius) : Collider(ColliderType::Sphere), _radius(radius)
{
}

SphereCollider::~SphereCollider()
{
}

void SphereCollider::Init()
{
	Super::Init();
}

void SphereCollider::Update()
{
	Super::Update();
}

void SphereCollider::Render(HDC hdc)
{
	Super::Render(hdc);

	if (_showDebug == false)
		return;

	Vector cameraPos = GET_SINGLE(SceneManager)->GetCameraPos();
	Vector pos = GetOwner()->GetPos();

	pos.x -= (cameraPos.x - GWinSizeX / 2);
	pos.y -= (cameraPos.y - GWinSizeY / 2);

	HBRUSH myBrush = (HBRUSH)::GetStockObject(NULL_BRUSH);
	HBRUSH oldBrush = (HBRUSH)::SelectObject(hdc, myBrush);
	Utils::DrawCircle(hdc, pos, _radius);
	::SelectObject(hdc, oldBrush);
	::DeleteObject(myBrush);
}

bool SphereCollider::CheckCollision(Collider* other)
{
	if (Super::CheckCollision(other) == false) // 충돌을 체크했더니 충돌을 원하지 않는다면
		return false;

	switch (other->GetColliderType())
	{
	case ColliderType::Box:
		return CheckCollisionSphere2Box(this, dynamic_cast<BoxCollider*>(other));
	case ColliderType::Sphere:
		return CheckCollisionSphere2Sphere(this, dynamic_cast<SphereCollider*>(other));
		
	}
	
	return false;
}
