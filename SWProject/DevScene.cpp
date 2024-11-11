#include "pch.h"
#include "DevScene.h"
#include "Object.h"
#include "Bullet.h"

DevScene::DevScene()
{
}

DevScene::~DevScene()
{
}

void DevScene::Init()
{
	Super::Init();

	_unitBoard.resize(_uY);
	for (int i = 0; i < _uY; i++)
	{
		_unitBoard[i].resize(_uX);
		for (int j = 0; j < _uX; j++)
			_unitBoard[i][j] = 0;
	}

	_enemyBoard.resize(_eY);
	for (int i = 0; i < _eY; i++)
	{
		_enemyBoard[i].resize(_eX);
		for (int j = 0; j < _eX; j++)
			_enemyBoard[i][j] = 0;
	}
}

void DevScene::Update()
{
	Super::Update();

	// 총알 화면 벗어난 거 확인후 제거
	for (auto it = _bullets.begin(); it != _bullets.end(); )
	{
		Bullet* bullet = *it;
		Pos pos = bullet->GetPos();
		if (pos.x < 0 || pos.x > GWinSizeX || pos.y < 0 || pos.y > GWinSizeY)
		{
			SAFE_DELETE(bullet);
			it = _bullets.erase(it);  // 현재 요소를 지운 후, 유효한 다음 요소로 이동
		}
		else 
			++it;  // 범위 내에 있는 경우 다음 요소로 이동
	}

}

void DevScene::Render(HDC hdc)
{
	Super::Render(hdc);


}

void DevScene::Add(Object* object)
{
	if (object == nullptr)
		return;

	auto findIt = std::find(_objects.begin(), _objects.end(), object);

	if (findIt != _objects.end())
		return;

	_objects.push_back(object);
}

void DevScene::Remove(Object* object)
{
	if (object == nullptr)
		return;

	auto it = std::remove(_objects.begin(), _objects.end(), object);
	_objects.erase(it, _objects.end());

	delete object;
}

void DevScene::Clear()
{
	std::for_each(_objects.begin(), _objects.end(), [=](Object* obj) {delete obj; });
	_objects.clear();
}

void DevScene::SetUnitBoard(int y, int x, int value)
{
	if (y < _uY && x < _uX && y >= 0 && x >= 0)
		_unitBoard[y][x] = value;
}

void DevScene::SetEnemyBoard(int y, int x, int value)
{
	if (y < _eY && x < _eX && y >= 0 && x >= 0)
		_enemyBoard[y][x] = value;
}

void DevScene::AddBullet(Bullet* bullet)
{
	if (bullet == nullptr)
		return;

	auto findIt = std::find(_bullets.begin(), _bullets.end(), bullet);

	if (findIt != _bullets.end())
		return;

	_bullets.push_back(bullet);
}

void DevScene::RemoveBullet(Bullet* bullet)
{
	if (bullet == nullptr)
		return;

	auto it = std::remove(_bullets.begin(), _bullets.end(), bullet);
	_bullets.erase(it, _bullets.end());

	delete bullet;
}