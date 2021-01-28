#pragma once
#include <list>
#include "Vector.h"

class Widget;

typedef std::list<Widget*> WIDLIST;

class WidgetManager {
	static WIDLIST widgets;
	static int focusingOnHandle;

public:
	static int GetFreeType();
	static void Attach(Widget*);
	static void Destory(Widget*);
	static void Destory(int);
	static void ClearAll();

	static Widget* GetWid(int _handle);
	static WIDLIST FindWidsWithTag(const char* _tag);

	static void BoardcastKey(int key);
	static void FocusOn(int _handle);


	static WIDLIST GetWidgets();
};