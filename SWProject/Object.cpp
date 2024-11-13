#include "pch.h"
#include "Object.h"
#include "SceneManager.h"

Object::Object(ObjectType type) : _type(type)
{
	GET_SINGLE(SceneManager)->Add(this);
}

Object::~Object()
{
}
