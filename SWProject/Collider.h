#pragma once
#include "Component.h"

class BoxCollider;
class SphereCollider;

class Collider : public Component
{
public:
	Collider(ColliderType colliderType);
	virtual ~Collider() override;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	virtual bool CheckCollision(Collider* other);

	ColliderType GetColliderType() { return _colliderType; }
	void SetShowDebug(bool show) { _showDebug = show; }

public:
	static bool CheckCollisionBox2Box(BoxCollider* b1, BoxCollider* b2);
	static bool CheckCollisionSphere2Box(SphereCollider* s1, BoxCollider* b2);
	static bool CheckCollisionSphere2Sphere(SphereCollider* s1, SphereCollider* s2);

	void SetCollisionLayer(COLLISION_LAYER_TYPE layer) { _collisionLayer = layer; }
	COLLISION_LAYER_TYPE GetCollisionLayerType() { return _collisionLayer; }

	void SetCollisionFlag(uint32 flag) { _collisionFlag = flag; }
	uint32 GetCollisionFlag() { return _collisionFlag; }

	void ResetCollisionFlag() { _collisionFlag = 0; } // 모든 애들이랑 충돌을 안하겠다.
	void AddCollisionFlagLayer(COLLISION_LAYER_TYPE layer); // 어떤 애랑만 충돌을 하고 싶다.
	void RemoveCollisionFlagLayer(COLLISION_LAYER_TYPE layer); // 어떤 애랑 충돌을 더이상 하기 싫다.



protected:
	ColliderType _colliderType;
	bool _showDebug = true; // 디버그 모드에서 이 충돌 범위를 보여줄지
	
public: // 지금 그냥 Get, Set 만들기 귀찮아서 public 임.
	unordered_set<Collider*> _collisionMap; // 지금까지 충돌한 애들

	// 나는 누구인가?
	COLLISION_LAYER_TYPE _collisionLayer = CLT_OBJECT;

	// 누구랑 충돌할 것인가?
	uint32 _collisionFlag = 0xFFFFFFFF;
};

