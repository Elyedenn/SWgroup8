#include "pch.h"
#include "DevScene.h"
#include "Object.h"
#include "Bullet.h"
#include "TimeManager.h"
#include "Enemy.h"

// temp
int32 TempBlock[][4][4] =
{
	{
		{0, 0, 0, 0},
		{2, 0, 0, 0},
		{1, 1, 2, 0},
		{0, 0, 0, 0}
	},
	{
		{0, 2, 0, 0},
		{0, 1, 0, 0},
		{2, 1, 0, 0},
		{0, 0, 0, 0}
	},
	{
		{0, 0, 0, 0},
		{2, 1, 1, 0},
		{0, 0, 2, 0},
		{0, 0, 0, 0}
	},
	{
		{0, 0, 0, 0},
		{1, 2, 0, 0},
		{1, 0, 0, 0},
		{2, 0, 0, 0}
	},
};

DevScene::DevScene()
{
}

DevScene::~DevScene()
{
}

void DevScene::Init()
{
	Super::Init();

	_oneUnitSize = Stage1_UnitSize;

	_unitBoard.resize(_uY);
	for (int i = 0; i < _uY; i++)
	{
		_unitBoard[i].resize(_uX);
		for (int j = 0; j < _uX; j++)
			_unitBoard[i][j] = 0;
	}
}

void DevScene::Update()
{
	Super::Update();

	//// 총알 화면 벗어난 거 확인후 제거
	//for (auto it = _bullets.begin(); it != _bullets.end(); )
	//{
	//	Bullet* bullet = *it;
	//	Pos pos = bullet->GetPos();
	//	if (pos.x < 0 || pos.x > GWinSizeX || pos.y < 0 || pos.y > GWinSizeY)
	//	{
	//		SAFE_DELETE(bullet);
	//		it = _bullets.erase(it);  // 현재 요소를 지운 후, 유효한 다음 요소로 이동
	//	}
	//	else 
	//		++it;  // 범위 내에 있는 경우 다음 요소로 이동
	//}


	// temp
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();
	tempTimer += deltaTime;
	if(tempTimer >= 5.0f)
	{
		// temp
		//BulletTile* BT = new BulletTile(30);
		//BT->SetPos(Pos{ 400,500 });
		//BT->SetDir(DIR_UP);
		Object* enemy = Object::CreateObject<Enemy>();
		enemy->SetPos(Pos{ 400,0 });
		enemy->SetDir(DIR_DOWN);
		tempTimer = 0;
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

void DevScene::GetUnitInfo(int32 unitNum, int32 arr[4][4])
{
	if (arr == nullptr)
		return;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			arr[i][j] = TempBlock[unitNum][i][j];
}
