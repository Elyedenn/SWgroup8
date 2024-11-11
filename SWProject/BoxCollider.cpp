#include "pch.h"
#include "BoxCollider.h"
#include "SceneManager.h"
#include "SphereCollider.h"
#include "Object.h"

BoxCollider::BoxCollider() : Collider(ColliderType::Box)
{
}

BoxCollider::~BoxCollider()
{

}

void BoxCollider::Init()
{
	Super::Init();
}

void BoxCollider::Update()
{
	Super::Update();
}

void BoxCollider::Render(HDC hdc)
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
	Utils::DrawRect(hdc, pos, _size.x, _size.y);
	::SelectObject(hdc, oldBrush);
	::DeleteObject(myBrush);
}

bool BoxCollider::CheckCollision(Collider* other)
{
	if (Super::CheckCollision(other) == false) // 충돌을 체크했더니 충돌을 원하지 않는다면
		return false;


	switch (other->GetColliderType())
	{
	case ColliderType::Box:
		return CheckCollisionBox2Box(this, dynamic_cast<BoxCollider*>(other));
	case ColliderType::Sphere:
		return CheckCollisionSphere2Box(dynamic_cast<SphereCollider*>(other), this);
	}

	return false;
}

RECT BoxCollider::GetRect()
{
	Vector pos = GetOwner()->GetPos();
	Vector size = GetSize();

	RECT rect =
	{
		(int32)(pos.x - (size.x / 2)),
		(int32)(pos.y - (size.y / 2)),
		(int32)(pos.x + (size.x / 2)),
		(int32)(pos.y + (size.y / 2))
	};

	return rect;
}
