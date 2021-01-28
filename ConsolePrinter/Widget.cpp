#include "Widget.h"
#include "WidgetManager.h"

Widget::Widget()
{
	widHandle = WidgetManager::GetFreeType();
	position = Vector2(0, 0);
	isVisialable = true;
	tag = (char*)"";
	WidgetManager::Attach(this);
}

Widget::Widget(Vector2 _pos)
{
	widHandle = WidgetManager::GetFreeType();
	position = _pos;
	isVisialable = true;
	tag = (char*)"";
	WidgetManager::Attach(this);
}

int Widget::GetHandle()
{
	return widHandle;
}

Widget* Widget::GetType()
{
	return this;
}

void Widget::OnKeyDown(int key)
{

}

void Widget::OnFocusStateChange(bool)
{
	
}
