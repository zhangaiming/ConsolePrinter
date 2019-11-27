#include "Vector.h"

Vector2 Vector2::operator+(const Vector2& vec)
{
	Vector2 result = Vector2(this->x + vec.x, this->y + vec.y);
	return result;
}

Vector2 Vector2::operator-(const Vector2& vec)
{
	Vector2 result = Vector2(this->x - vec.x, this->y - vec.y);
	return result;
}

Vector2 Vector2::operator*(const int& num)
{
	Vector2 result = Vector2(this->x * num, this->y * num);
	return result;
}

bool Vector2::operator==(const Vector2& vec)
{
	if(this->x == vec.x && this->y == vec.y)
		return true;
	return false;
}

Vector2::Vector2()
{
	this->x = 0;
	this->y = 0;
}

Vector2::Vector2(int _x, int _y)
{
	this->x = _x;
	this->y = _y;
}
