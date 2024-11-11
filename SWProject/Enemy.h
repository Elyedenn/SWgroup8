#pragma once
#include "Object.h"

class Enemy : public Object
{
public:
	Enemy();
	~Enemy();

	void Init();

	void Update();
	int DetectCollision();//적 유닛 충돌 여부 검사 함수
	void Move();//적 유닛 이동 함수
	void Attack();//적 유닛 공격 함수
	void ChangeHp(int hp);//적 유닛의 체력 변경 함수
	void Destroy();//적 유닛 체력 < 0 일 경우, 소멸하는 함수

	void Render();//시각화
	void Show();//정보맵에서의 수정(등록)
	void Hide();//정보맵에서의 수정(삭제)
	
	int GetHp();
	int GetMaxHp();
	Pos GetPos();
	ObjectType GetObjectType();

private:

};
