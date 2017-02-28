#include "Precompiled.h"
#include "CircleCollider.h"

#include "Object.h"

CircleCollider::CircleCollider() : m_Radius(0.f)
{
}
CircleCollider::~CircleCollider()
{
}

CircleCollider* CircleCollider::Create(float radius, const Vector2& offset)
{
	auto collider = new (std::nothrow) CircleCollider();
	if (collider && collider->InitializeWithCircle(radius, offset))
	{
		collider->AutoRelease();
		return collider;
	}

	SAFE_DELETE(collider);
	return nullptr;
}

bool CircleCollider::InitializeWithCircle(float radius, const Vector2& offset)
{
	SetRadius(radius);
	SetOffset(offset);

	return true;
}

bool CircleCollider::IsCollideWith(Collider* other)
{
	return other->IsCollideWith(this);
}

bool CircleCollider::IsCollideWith(CircleCollider* other)
{
	auto deltaPos = (GetParent()->GetPosition() + GetOffset()) - other->GetParent()->GetPosition();
	auto distance = sqrt(pow(deltaPos.x, 2) + pow(deltaPos.y, 2));

	if (distance > (GetRadius() + other->GetRadius()))
		return false;

	return true;
}
bool CircleCollider::IsCollideWith(BoxCollider* other)
{
	return false;
}