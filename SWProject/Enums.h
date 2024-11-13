#pragma once

enum class SceneType
{
	None,
	DevScene,
	GameScene,
};

enum class ObjectType
{
	None,
	Unit,
	Enemy,
	Bullet,
	Tile,
};

enum class ColliderType
{
	Sphere,
	Box,
};

enum class TileType
{
	None,
	Normal,
	BulletTile,

};

//enum LAYER_TYPE
//{
//	LAYER_BACKGROUND,
//	LAYER_OBJECT,
//	LAYER_EFFECT,
//	// ...
//	LAYER_UI,
//
//	LAYER_MAXCOUNT
//};

enum COLLISION_LAYER_TYPE
{
	CLT_OBJECT,
	CLT_ENEMY,
	CLT_TILE,
	//...

};

enum Dir
{
	DIR_UP,
	DIR_DOWN,
	DIR_LEFT,
	DIR_RIGHT,

	DIR_MAXCOUNT
};

enum class EnemyState
{
	Move,
	Attack,
	Skill,
};