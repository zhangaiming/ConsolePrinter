#pragma once
#include <list>

class Selection {
protected:
	void(*selectedFunc)();
public:
	virtual void OnSelected() = 0;	//��ѡ���¼�
	virtual void OnLighted() = 0;	//������ʾ
	virtual void OnUnlighted() = 0;	//ȡ��������ʾ
};