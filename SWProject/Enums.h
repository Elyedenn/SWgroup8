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
	Alley,
	Enemy,
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

enum Dir
{
	DIR_UP,
	DIR_DOWN,
	DIR_LEFT,
	DIR_RIGHT,

	DIR_MAXCOUNT
};
