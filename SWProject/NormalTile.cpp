#include "pch.h"
#include "NormalTile.h"

NormalTile::NormalTile() : Tile(TileType::Normal)
{
}

NormalTile::~NormalTile()
{
}

void NormalTile::Init()
{
}

void NormalTile::Update()
{
}

void NormalTile::Render(HDC hdc)
{
	Utils::DrawRect(hdc, _pos, _tileSize, _tileSize);
}
