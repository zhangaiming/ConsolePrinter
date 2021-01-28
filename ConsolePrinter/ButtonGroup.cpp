#include "ButtonGroup.h"
#include "Button.h"

ButtonGroup* ButtonGroup::GetType()
{
	return this;
}

ButtonGroup::ButtonGroup()
{
	CurIndex = 0;
}

void ButtonGroup::Print()
{
	for (std::list<Button*>::iterator iter = selections.begin(); iter != selections.end(); iter++) {
		if ((*iter)->isVisialable)
			(*iter)->Print();
	}
}

bool ButtonGroup::AttachSelection(Button* target)
{
	for (std::list<Button*>::iterator iter = selections.begin(); iter != selections.end(); iter++) {
		if ((*iter) == target) {
			return false;
		}
	}
	if (selections.size() == 0) {
		target->isLighted = true;
	}
	selections.push_back(target);
	return true;
}

bool ButtonGroup::DetachSelection(Button* target)
{
	for (std::list<Button*>::iterator iter = selections.begin(); iter != selections.end(); iter++) {
		if ((*iter) == target) {
			selections.erase(iter);
			return true;
		}
	}
	return false;
}

Button* ButtonGroup::GetByIndex(int index)
{
	int i = 0;
	for (std::list<Button*>::iterator iter = selections.begin(); iter != selections.end(); iter++, i++) {
		if (i == index)
			return(*iter);
	}
	return nullptr;
}

Button* ButtonGroup::GetCur()
{
	return GetByIndex(CurIndex);
}

int ButtonGroup::GetCurIndex()
{
	return CurIndex;
}

void ButtonGroup::Select()
{
	if (GetCur() != nullptr)
		GetCur()->OnSelected();
}

void ButtonGroup::Last()
{
	if (GetCur() != nullptr) {
		GetCur()->OnUnlighted();
		CurIndex -= 1;
		if (CurIndex == -1)
			CurIndex = selections.size() - 1;
		GetCur()->OnLighted();
		Print();
	}
}

void ButtonGroup::OnFocusStateChange(bool state)
{
	if (selections.size() > 0) {
		if (state) {
			if(GetByIndex(CurIndex) != nullptr)
				GetByIndex(CurIndex)->OnLighted();
		}
		else {
			if (GetByIndex(CurIndex) != nullptr)
				GetByIndex(CurIndex)->OnUnlighted();
		}
	}
	
}

void ButtonGroup::Next()
{
	if (GetCur() != nullptr) {
		GetCur()->OnUnlighted();
		CurIndex += 1;
		if (CurIndex == selections.size())
			CurIndex = 0;
		GetCur()->OnLighted();
		Print();
	}
}

void ButtonGroup::OnKeyDown(int key)
{
	if (key == 119)
	{
		Last();
	}
	else if (key == 115)
		Next();
	else if (key == 32)
		Select();
}


