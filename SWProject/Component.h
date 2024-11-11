#pragma once

class Object;

class Component
{
public:
	Component();
	virtual ~Component();

	virtual void Init() {}
	virtual void Update() {}
	virtual void Render(HDC hdc) {}

	void SetOwner(Object* owner) { _owner = owner; }
	Object* GetOwner() { return _owner; }

protected:
	Object* _owner = nullptr;
};

