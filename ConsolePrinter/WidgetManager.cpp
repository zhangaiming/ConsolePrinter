#include "WidgetManager.h"
#include "Widget.h"
#include <random>
#include <Windows.h>

WIDLIST WidgetManager::widgets;
int WidgetManager::focusingOnHandle = -1;

int WidgetManager::GetFreeType()
{
	LARGE_INTEGER seed;
	QueryPerformanceFrequency(&seed);
	QueryPerformanceCounter(&seed);
	srand(seed.QuadPart);
	int r = rand();
	if (GetWid(r) == nullptr)
		//如果当前生成的handle未被占用
		return r;
	else {
		return GetFreeType();
	}
}

void WidgetManager::Attach(Widget* widget)
{
	if (widget != nullptr)
		if(widgets.size() < 65536)
			if (widgets.size() == 0) {
				focusingOnHandle = widget->GetHandle();
				widgets.push_back(widget);
			}
			else if (GetWid(widget->GetHandle()) == nullptr)
				widgets.push_back(widget);
}

void WidgetManager::Destory(Widget* widget)
{
	Destory(widget->GetHandle());
}

void WidgetManager::Destory(int _handle)
{
	for (WIDLIST::iterator iter = widgets.begin(); iter != widgets.end();) {
		if ((*iter)->GetHandle() == _handle) {
			delete(*iter);
			widgets.erase(iter++);
		}
			
	}
}

void WidgetManager::ClearAll()
{
	for (WIDLIST::iterator iter = widgets.begin(); iter != widgets.end();) {
		widgets.erase(iter++);
	}
}

Widget* WidgetManager::GetWid(int _handle)
{
	for (WIDLIST::iterator iter = widgets.begin(); iter != widgets.end();) {
		if ((*iter) == nullptr)
			widgets.erase(iter++);
		else if ((*iter)->GetHandle() == _handle)
			return (*iter);
		++iter;
	}
	return nullptr;
}

WIDLIST WidgetManager::FindWidsWithTag(const char* _tag)
{
	WIDLIST result;
	for (WIDLIST::iterator iter = widgets.begin(); iter != widgets.end(); iter++) {
		if ((*iter) != nullptr && (*iter)->tag == _tag) {
			result.push_back((*iter));
		}
	}
	return result;
}

void WidgetManager::BoardcastKey(int key)
{
	/*WIDLIST temp = widgets;
	if(temp.size() > 0)
		for (auto iter = temp.begin(); temp.size() > 0 && iter != temp.end(); iter++) {
			if((*iter) != nullptr)
				(*iter)->OnKeyDown(key);
		}*/
	if (focusingOnHandle != -1 && GetWid(focusingOnHandle) != nullptr) {
		GetWid(focusingOnHandle)->OnKeyDown(key);
	}
	else {
		focusingOnHandle = -1;
	}
}

void WidgetManager::FocusOn(int _handle)
{
	if (GetWid(_handle) != nullptr) {
		focusingOnHandle = _handle;
		GetWid(_handle)->OnFocusStateChange(true);
	}
}

WIDLIST WidgetManager::GetWidgets()
{
	return widgets;
}
