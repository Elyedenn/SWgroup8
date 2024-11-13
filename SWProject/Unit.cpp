#include "pch.h"
#include "Unit.h"
#include "Object.h"
#include "BlockModel.h"

Unit::Unit() : Creature(ObjectType::Unit)
{
}

Unit::~Unit()
{
}

void Unit::Init()
{
}

void Unit::Update()
{
}

void Unit::Render()
{
}

void Unit::OnDamaged(int32 damage)
{
}

void Unit::OnDead()
{
}
