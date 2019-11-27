#pragma once
class Vector2 {
public:
	int x, y;
	Vector2 operator+(const Vector2& vec);	//�ӷ�
	Vector2 operator-(const Vector2& vec);	//����
	Vector2 operator*(const int& num);	//����
	bool operator==(const Vector2& vec);	//���
	Vector2();
	Vector2(int, int);
};