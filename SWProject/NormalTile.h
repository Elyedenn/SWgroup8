#pragma once
#include "Tile.h"

class NormalTile : public Tile
{
	using Super = Tile;
public:
	NormalTile(int32 tileSize);
	~NormalTile();

	virtual void Init();
	virtual void Update();
	virtual void Render(HDC hdc);
};

