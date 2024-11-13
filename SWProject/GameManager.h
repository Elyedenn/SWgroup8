#pragma once

enum class Mode
{
	Normal,
	Build,
	Erase,
};

class GameManager
{
	DECLARE_SINGLE(GameManager);

public:
	void Init();
	void Update();
	void Render(HDC hdc);

	void NormalUpdate();
	void BuildUpdate();
	void EraseUpdate();


	void SelectStartIndex();

	void Clear();
private:
	Mode _mode = Mode::Normal;

	int32 _selectedBlock[4][4] = {};
	VectorInt _startIndex = { 0,0 };

	int32 _oneUnitSize = 0;

	Pos _mousePos = { 0,0 };

	int32 _playerGold = 0;
};

