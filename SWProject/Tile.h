#pragma once
#include "Object.h"

class Tile : public Object
{
public:
	Tile(TileType tileType);
	~Tile();

	virtual void Init();
	virtual void Update();
	virtual void Render(HDC hdc);

	TileType GetTileType() { return _tileType; }
	
	int GetTileSize() { return _tileSize; }
	void GetTileSize(int tileSize) { _tileSize = tileSize; }


protected:
	TileType _tileType = TileType::None;
	int _tileSize = 0;
};

