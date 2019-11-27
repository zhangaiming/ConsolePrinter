#pragma once
#include "Vector.h"

class GameObject;

class Transform {
private:
	Vector2 position;

public:
	Vector2 scale;
	Transform* parent;
	int depth;
	GameObject* gameObject;

public:
	void MoveTo(const Vector2& destination);
	Vector2 GetPosition();
	Transform();
	Transform(Vector2 _position);
	Transform(Vector2 _position, Vector2 _scale);
};