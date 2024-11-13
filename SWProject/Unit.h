#pragma once
#include "Creature.h"

class Tile;

class Unit : public Creature
{
public:
	Unit();
	~Unit();

	void Init();
	void Update();
	void Render();

	virtual void OnDamaged(int32 damage) override;
	virtual void OnDead() override;


	// Get, Set ¸¸µé±â ±ÍÂú¾Æ...
	TileType _tileTypes[4][4] = {};
	Tile* _tiles[4][4] = {};

private:
	int32 _hp = 50;
	int32 _maxHp = 50;
	int32 _price = 100;

	int32 _blockIndex = 0;


	VectorInt _startIndex = { 0,0 };
};

