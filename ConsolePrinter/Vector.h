#pragma once
class Vector2 {
public:
	int x, y;
	Vector2 operator+(const Vector2& vec);	//加法
	Vector2 operator-(const Vector2& vec);	//减法
	Vector2 operator*(const int& num);	//数乘
	bool operator==(const Vector2& vec);	//相等
	Vector2();
	Vector2(int, int);
};