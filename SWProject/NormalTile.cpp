#include "pch.h"
#include "NormalTile.h"

NormalTile::NormalTile(int32 tileSize) : Tile(TileType::Normal, tileSize)
{
}

NormalTile::~NormalTile()
{
}

void NormalTile::Init()
{
	Super::Init();
}

void NormalTile::Update()
{
	Super::Update();
}

void NormalTile::Render(HDC hdc)
{
	Super::Render(hdc);

}
