#pragma once
#include "Vector.h"
#include <list>

class Window;

class Widget {
public:
	Vector2 position;
	bool isVisialable;
	char* tag;

private:
	int widHandle;

public:
	Widget();
	Widget(Vector2 position);
	int GetHandle();
	virtual Widget* GetType();
	virtual void Print() = 0;
	virtual void OnKeyDown(int key);

	virtual void OnFocusStateChange(bool);
};