#pragma once

class Object;
class UI;
class Actor;
class Creature;

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

	vector<Object*>& GetObjects() {	return _objects;};

	virtual void AddActor(Actor* actor);
	virtual void RemoveActor(Actor* actor);

	Creature* GetCreatureAt(VectorInt cellPos);
	
protected:
	vector<Object*> _objects;

public:

	vector<UI*> _uis;
};

