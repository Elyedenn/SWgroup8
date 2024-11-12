#include "pch.h"
#include "BulletTile.h"
#include "Bullet.h"
#include "TimeManager.h"

BulletTile::BulletTile() : Tile(TileType::BulletTile)
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
}

void BulletTile::SpawnBullet()
{
	Bullet* bullet = Object::CreateObject<Bullet>();

	bullet->SetPos(_pos);
	bullet->SetDir(_dir);
}
