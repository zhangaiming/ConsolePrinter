#pragma once
#include <list>

class Selection {
protected:
	void(*selectedFunc)();
public:
	virtual void OnSelected() = 0;	//被选择事件
	virtual void OnLighted() = 0;	//高亮显示
	virtual void OnUnlighted() = 0;	//取消高亮显示
};