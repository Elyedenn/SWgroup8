#pragma once
#include "Tile.h"

class NormalTile : public Tile
{
public:
	NormalTile();
	~NormalTile();

	virtual void Init();
	virtual void Update();
	virtual void Render(HDC hdc);
};

