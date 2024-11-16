#pragma once

class Collider;

class Object
{
public:
	Object(ObjectType type);
	virtual ~Object();

	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;



public:
	ObjectType GetObjectType() { return _type; }
	Pos GetPos() { return _pos; }
	Dir GetDir() { return _dir; }

	void SetPos(Pos pos) { _pos = pos; }
	void SetDir(Dir dir) { _dir = dir; }

	template<typename T>
	static T* CreateObject()
	{
		T* object = new T();
		object->Init();

		return object;
	}

	virtual void OnComponentBeginOverlap(Collider* src, Collider* dest) {};
	virtual void OnComponentEndOverlap(Collider* src, Collider* dest) {};

protected:
	ObjectType _type = ObjectType::None;
	Pos _pos = {};
	Dir _dir = DIR_UP;
};

