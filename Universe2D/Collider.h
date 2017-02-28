#pragma once
#include "Object.h"

class BoxCollider;
class CircleCollider;

class Collider : public Object
{
protected:
	Vector2 m_Offset;

public:
	Collider() {};
	~Collider() {};

	static Collider* CreateCircle(float radius, const Vector2& offset);
	// Box Create �����ؾ���

public:
	virtual bool IsCollideWith(Collider* other) = 0;

	virtual bool IsCollideWith(BoxCollider* other) = 0;
	virtual bool IsCollideWith(CircleCollider* other) = 0;

public:
	const Vector2& GetOffset() const
	{
		return m_Offset;
	}
	void SetOffset(const Vector2& offset)
	{
		m_Offset = offset;
	}

public:
	// Collision �Լ��� ȣ��Ǹ� �θ� ������Ʈ�� �����մϴ�
	virtual void OnCollision(Collider* collider) override
	{
		this->GetParent()->OnCollision(collider);
	};
};

