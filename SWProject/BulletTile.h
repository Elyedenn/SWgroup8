#pragma once
#include "Tile.h"

class BulletTile : public Tile
{
	using Super = Tile;

public:
	BulletTile();
	~BulletTile();

	virtual void Init();
	virtual void Update();
	virtual void Render(HDC hdc);

	void SpawnBullet();

private:
	float _delay = 3.0;
	float _sumTime = 0;
};

