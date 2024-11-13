#pragma once
#include "Object.h"

class Unit;

class Tile : public Object
{
public:
	Tile(TileType tileType, int32 tileSize);
	~Tile();

	virtual void Init();
	virtual void Update();
	virtual void Render(HDC hdc);

	TileType GetTileType() { return _tileType; }

	void SetOwner(Unit* owner) { _owner = owner; }
	Unit* GetOwner() { return _owner; }

	void OnDamaged(int32 damage);

protected:
	TileType _tileType = TileType::None;
	int32 _tileSize = 0;
	Unit* _owner = nullptr;
};

