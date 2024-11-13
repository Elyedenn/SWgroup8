#include "pch.h"
#include "GameManager.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Object.h"
#include "Unit.h"
#include "NormalTile.h"
#include "BulletTile.h"
#include "Tile.h"

void GameManager::Init()
{
	_oneUnitSize = GET_SINGLE(SceneManager)->GetCurrentScene()->GetOneUnitSize();
}

void GameManager::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	_mousePos = GET_SINGLE(InputManager)->GetMousePos();

	switch (_mode)
	{
	case Mode::Normal:
		NormalUpdate();
		break;
	case Mode::Build:
		BuildUpdate();
		break;
	case Mode::Erase:
		EraseUpdate();
		break;
	}
}

void GameManager::Render(HDC hdc)
{
	if (_mode == Mode::Build)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (_selectedBlock[i][j] != 0)
				{
					if (i + 1 < 4 && _selectedBlock[i + 1][j] != 0)
						Utils::DrawLine(hdc, 
							Pos{ _mousePos.x + (j - _startIndex.x) * _oneUnitSize, 
								 _mousePos.y + (i - _startIndex.y) * _oneUnitSize },
							Pos{ _mousePos.x + (j - _startIndex.x) * _oneUnitSize,
								 _mousePos.y + (i + 1 - _startIndex.y) * _oneUnitSize });
					if (j + 1 < 4 && _selectedBlock[i][j + 1] != 0)
						Utils::DrawLine(hdc,
							Pos{ _mousePos.x + (j - _startIndex.x) * _oneUnitSize,
								 _mousePos.y + (i - _startIndex.y) * _oneUnitSize },
							Pos{ _mousePos.x + (j + 1 - _startIndex.x) * _oneUnitSize,
								 _mousePos.y + (i - _startIndex.y) * _oneUnitSize });
				}
			}
		}
	}
}

void GameManager::NormalUpdate()
{
	if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::KEY_1))
	{
		_mode = Mode::Build;
		GET_SINGLE(SceneManager)->GetCurrentScene()->GetUnitInfo(0, _selectedBlock);
		SelectStartIndex();
	}
}

void GameManager::BuildUpdate()
{
	if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::LeftMouse))
	{
		Unit* unit = Object::CreateObject<Unit>();

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				// TODO SetPos ºÎºÐ
				if (_selectedBlock[i][j] == (int)TileType::Normal)
				{
					NormalTile* NTile = new NormalTile(_oneUnitSize);
					NTile->Init();
					NTile->SetPos(Pos{ _mousePos.x + (j - _startIndex.x) * _oneUnitSize,
									  _mousePos.y + (i - _startIndex.y) * _oneUnitSize });
					unit->_tiles[i][j] = NTile;
					unit->_tileTypes[i][j] = TileType::Normal;
				}
				else if (_selectedBlock[i][j] == (int)TileType::BulletTile)
				{
					BulletTile* BTile = new BulletTile(_oneUnitSize);
					BTile->Init();
					BTile->SetPos(Pos{ _mousePos.x + (j - _startIndex.x) * _oneUnitSize,
									  _mousePos.y + (i - _startIndex.y) * _oneUnitSize });
					unit->_tiles[i][j] = BTile;
					unit->_tileTypes[i][j] = TileType::BulletTile;
				}				
			}
		}
	}

	if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::KEY_1))
	{
		_mode = Mode::Normal;
	}
}

void GameManager::EraseUpdate()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();
}



void GameManager::SelectStartIndex()
{
	bool found = false;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (_selectedBlock[i][j] != 0)
			{
				_startIndex = { i,j };
				found = true;
				break;
			}
		}
		if (found)
			break;
	}
}

void GameManager::Clear()
{
}