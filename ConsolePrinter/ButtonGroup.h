#pragma once
#include "Widget.h"

class Button;

class ButtonGroup : public Widget {
protected:
	std::list<Button*> selections;
	int CurIndex;

public:
	ButtonGroup* GetType();
	ButtonGroup();
	void Print();

	virtual bool AttachSelection(Button*);
	virtual bool DetachSelection(Button*);

	Button* GetByIndex(int index);
	Button* GetCur();
	int GetCurIndex();
	void Select();	//选择当前选项
	virtual void Next();
	virtual void Last();

	void OnFocusStateChange(bool);

	virtual void OnKeyDown(int key);
};