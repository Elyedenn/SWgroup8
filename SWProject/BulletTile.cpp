#include "pch.h"
#include "BulletTile.h"
#include "Bullet.h"
#include "TimeManager.h"
#include "SceneManager.h"

BulletTile::BulletTile(int32 tileSize) : Tile(TileType::BulletTile, tileSize)
{
}

BulletTile::~BulletTile()
{
}

void BulletTile::Init()
{
	Super::Init();
}

void BulletTile::Update()
{
	Super::Update();

	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	_sumTime += deltaTime;

	if (_sumTime >= _delay)
	{
		_sumTime = 0;
		SpawnBullet();
	}
}

void BulletTile::Render(HDC hdc)
{
	Super::Render(hdc);

	HPEN myPen = ::CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	HPEN oldPen = (HPEN)::SelectObject(hdc, myPen);

	Utils::DrawCircle(hdc, _pos, _tileSize / 3);

	::SelectObject(hdc, oldPen);
	::DeleteObject(myPen);

}

void BulletTile::SpawnBullet()
{
	Bullet* bullet = Object::CreateObject<Bullet>();

	bullet->SetPos(_pos);
	bullet->SetDir(_dir);
}
