#pragma once
#include "Object.h"

class Collider;
class CollisionManager : public Object, public Singleton<CollisionManager>
{
private:
	typedef std::vector<Collider*> ColliderList;
	ColliderList m_ColliderList;
	
public:
	CollisionManager();
	~CollisionManager();

public:
	// �ʱ�ȭ �Լ�
	bool Initialize();

	void AddCollider(Collider* collider);
	void RemoveCollider(Collider* collider);

public:
	void Update(float deltaTime) override;
};
