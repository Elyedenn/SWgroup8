#include "pch.h"
#include "Tile.h"
#include "Unit.h"
#include "SceneManager.h"

Tile::Tile(TileType tileType, int32 tileSize) : Object(ObjectType::Tile), _tileType(tileType), _tileSize(tileSize)
{
}

Tile::~Tile()
{
}

void Tile::Init()
{
	GET_SINGLE(SceneManager)->Add(this);
}

void Tile::Update()
{
}

void Tile::Render(HDC hdc)
{
	Utils::DrawRect(hdc, _pos, _tileSize, _tileSize);
}

void Tile::OnDamaged(int32 damage)
{
	_owner->OnDamaged(damage);
}
