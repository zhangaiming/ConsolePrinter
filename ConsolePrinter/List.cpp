#include "List.h"
#include "Button.h"

List::List(Vector2 _pos, Vector2 _scale) :ButtonGroup()
{
	position = _pos;
	scale = _scale;
	upperIndex = 0;
}

#include "ConsolePrinter.h"
void List::Erase()
{
	for (int y = 0; y < scale.y; y++) {
		ConsolePrinter::PrintHorLine(" ", Vector2(position.x, position.y + y), scale.x);
	}
}

void List::Print()
{
	if (selections.size() > 0) {
		int i = 0;
		for (std::list<Button*>::iterator iter = GetUpperIter(); i < scale.y && iter != selections.end(); iter++, i++) {
			if ((*iter) != nullptr) {
				(*iter)->position = Vector2(position.x, position.y + i);
				(*iter)->Print();
			}
		}
	}
}

void List::Next() {
	if (selections.size() > 0) {
		if (CurIndex < selections.size() - 1) {
			//如果不是最后一个
			GetCur()->OnUnlighted();
			GetCur()->Print();
			CurIndex++;
			if (CurIndex - upperIndex > scale.y - 1) {
				Erase();
				upperIndex++;
				Print();
			}
			GetCur()->OnLighted();
			GetCur()->Print();

		}
		else {
			//如果是最后一个
			upperIndex = 0;
			if (selections.size() > scale.y) {
				GetCur()->OnUnlighted();
				Erase();
				CurIndex = 0;
				GetCur()->OnLighted();
				Print();
			}
			else {
				GetCur()->OnUnlighted();
				GetCur()->Print();
				CurIndex = 0;
				GetCur()->OnLighted();
				GetCur()->position = Vector2(position.x, position.y);
				GetCur()->Print();
			}
			
		}
	}

}

void List::Last() {
	if (selections.size() > 0) {
		if (CurIndex > 0) {
			//如果不是第一个
			GetCur()->OnUnlighted();
			GetCur()->Print();
			CurIndex--;
			GetCur()->OnLighted();
			GetCur()->Print();

			if (upperIndex == CurIndex + 1) {
				Erase();
				upperIndex--;
				Print();
			}
		}
		else {
			//如果是第一个
			if (selections.size() > scale.y) {
				upperIndex = selections.size() - scale.y;
				GetCur()->OnUnlighted();
				Erase();
				CurIndex = selections.size() - 1;
				GetCur()->OnLighted();
				Print();
			}
			else {
				GetCur()->OnUnlighted();
				GetCur()->Print();
				CurIndex = selections.size() - 1;
				GetCur()->OnLighted();
				GetCur()->Print();
			}
		}
	}

}

int List::GetUpperIndex()
{
	return upperIndex;
}

void List::SetUpperIndex(int a)
{
	upperIndex = a;
}

std::list<Button*>::iterator List::GetUpperIter()
{
	std::list<Button*>::iterator result = selections.begin();
	for (int i = 0; i < upperIndex && i < selections.size(); i++) {
		result++;
	}
	return result;
}

bool List::AttachSelection(Button* target)
{
	for (std::list<Button*>::iterator iter = selections.begin(); iter != selections.end(); iter++) {
		if ((*iter) == target) {
			return false;
		}
	}
	if (selections.size() == 0) {
		target->OnLighted();
	}
	selections.push_back(target);
	if (selections.size() == 1)
		upperIndex = 0;
	return true;
}

bool List::DetachSelection(Button* target)
{
	for (std::list<Button*>::iterator iter = selections.begin(); iter != selections.end(); iter++) {
		if ((*iter) == target) {
			if ((*iter)->isLighted) {
				(*iter)->OnUnlighted();
			}
			selections.erase(iter);
			if (upperIndex > selections.size())
				upperIndex = selections.size();
			return true;
		}
	}
	return false;
}

void List::Clear()
{
	Erase();
	upperIndex = 0;
	CurIndex = 0;
	std::list<Button*> temp = selections;
	for (auto iter = temp.begin(); iter != temp.end(); iter++) {
		DetachSelection((*iter));
	}
}

void List::OnKeyDown(int key) {
	if (key == 119)
	{
		Last();
	}
	else if (key == 115)
		Next();
	else if (key == 32)
		Select();
}