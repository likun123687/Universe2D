#pragma once
#include "Object.h"

class BoxCollider;
class CircleCollider;
class Collider : public Object
{
public:
	Collider();
	~Collider();

public:
	virtual bool IsCollideWith(Collider* other) = 0;

public:
	virtual bool IsCollideWith(BoxCollider* other) = 0;
	virtual bool IsCollideWith(CircleCollider* other) = 0;

public:
	void OnCollisionEnter(Collider* collider) override
	{
		// �θ𿡰� �浹ü ����
		GetParent()->OnCollisionEnter(collider);
	};

	void Update(float deltaTime) override
	{
		Object::Update(deltaTime);
	}
	void Render() override
	{
		Object::Render();
	}
};

