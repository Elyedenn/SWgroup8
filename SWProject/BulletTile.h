#pragma once
#include "Tile.h"

class BulletTile : public Tile
{
	using Super = Tile;

public:
	BulletTile(int32 tileSize);
	~BulletTile();

	virtual void Init();
	virtual void Update();
	virtual void Render(HDC hdc);

	void SpawnBullet();

private:
	const float _delay = 1.0;
	float _sumTime = 0;
};

