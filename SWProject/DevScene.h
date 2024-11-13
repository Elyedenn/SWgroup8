#pragma once
#include "Scene.h"

class Bullet;

class DevScene : public Scene
{
	using Super = Scene;

public:
	DevScene();
	virtual ~DevScene();

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	virtual void Add(Object* object) override;
	virtual void Remove(Object* object) override;
	virtual void Clear() override;


	virtual void GetUnitInfo(int32 unitNum, int32 arr[4][4]) override;

private:
	int32 _uX = 10;
	int32 _uY = 10;

	int32 _eX = 8;
	int32 _eY = 8;

	// temp
	vector<int32*> _unitInfo;
};

