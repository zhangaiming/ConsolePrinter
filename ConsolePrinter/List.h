#pragma once
#include "ButtonGroup.h"

class Button;

class List : public ButtonGroup {
	Vector2 scale;
	int upperIndex;

public:
	List(Vector2 _pos, Vector2 _scale);

	void Erase();
	void Print();

	void Next();
	void Last();

	int GetUpperIndex();
	void SetUpperIndex(int);
	std::list<Button*>::iterator GetUpperIter();

	bool AttachSelection(Button*);
	bool DetachSelection(Button*);
	void Clear();

	void OnKeyDown(int key);
};