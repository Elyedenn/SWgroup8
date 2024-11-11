#include "pch.h"
#include "Enemy.h"
#include "Object.h"

Enemy::Enemy() : Object(ObjectType::Enemy)
{
    Object(Enemy);
}

Enemy::~Enemy()
{
}

void Enemy::Init()
{
    _maxHp = 100;
    _hp = _maxHp;
    _pos = {0,0};
}

void Enemy::Update()
{
    int detectCollisionCheck = DetectCollision();

    if(detectCollisionCheck == 0){
        Move();
    }
    else if(detectCollisionCheck == -1){
        Attack();
    }
}

int Enemy::DetectCollision()
{
    Pos nextPos = _pos;
    nextPos[1] += 1; 

    //한 칸 전진한 좌표가 맵정보에서 다른 좌표와 겹칠 경우 1,
    //겹치지 않아 이동이 가능하면 0,
    //적 구역을 모두 이동해 공격을 실행할것이면 -1 리턴;

    return 1;
}

void Enemy::Move()
{
    Hide();
    _pos[1] += 1;
    Show();
    Render();
}

void Enemy::Attack()
{
    //플레이어의 체력을 공격
}

void Enemy::ChangeHp(int hp)
{
    _hp -= hp;

    if(_hp <= 0){
        Destroy();
    }
}

void Enemy::Destroy()
{
    Hide();
    Render();

    //삭제할 정보 늘어날 시 수정필요
}

void Enemy::Render()
{
    //화면상으로 시각화
    //우선 당장 존재하는 시각화된 요소는 삭제
    //이후 정보맵에 존재하는 대로 재출력
    //정보맵에서 찾을 수 없으면 그대로 리턴
}

void Enemy::Show()
{
    //정보맵에 유닛을 표기
}

void Enemy::Hide()
{
    //정보맵에서 유닛을 숨김
}

int Enemy::GetHp()
{
    return _hp;
}

int Enemy::GetMaxHp()
{
    return _maxHp;
}

Pos Enemy::GetPos()
{
    return _pos;
}

ObjectType Enemy::GetObjectType()
{
    return _objectType;
}
