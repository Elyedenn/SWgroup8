#pragma once

class Object;
class UI;
class Actor;
class Creature;
class Bullet;

class Scene
{
public:
	Scene();
	virtual ~Scene();

public:
	virtual void Init();
	virtual void Update();
	virtual void Render(HDC hdc);

	virtual void Add(Object* object) abstract;
	virtual void Remove(Object* object) abstract;
	virtual void Clear() abstract;

	vector<Object*>& GetObjects() { return _objects; };

	Creature* GetCreatureAt(VectorInt cellPos);


	void SetUnitBoardAt(int32 y, int32 x, int32 value);
	int32 GetUnitBoardAt(int32 y, int32 x);

	void SetUnitSpace(RECT rect) { _unitSpace = rect; }
	RECT GetUnitSpace() { return _unitSpace; }

	virtual void GetUnitInfo(int32 unitNum, int32 arr[4][4]) abstract;

	int32 GetOneUnitSize() { return _oneUnitSize; }

protected:
	vector<Object*> _objects;


	// 설정 필요
	vector<vector<int>> _unitBoard;
	RECT _unitSpace = { 600,600,600,600 };
	int32 _oneUnitSize = 0;

public:

	vector<UI*> _uis;
};

