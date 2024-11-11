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

	void SetUnitBoard(int y, int x, int value);
	void SetEnemyBoard(int y, int x, int value);
	
	
	virtual void AddBullet(Bullet* bullet) override;
	virtual void RemoveBullet(Bullet* bullet) override;


private:
	int _uX = 10;
	int _uY = 10;

	int _eX = 8;
	int _eY = 8;

	vector<vector<int>> _unitBoard;
	vector<vector<int>> _enemyBoard;

	vector<Bullet*> _bullets;
};

