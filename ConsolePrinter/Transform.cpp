#include "Transform.h"
#include "GameObject.h"

void Transform::MoveTo(const Vector2& destination)
{
	position = destination;
	gameObject->Print();
}

Vector2 Transform::GetPosition()
{
	return position;
}
