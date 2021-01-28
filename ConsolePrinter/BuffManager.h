#pragma once
#include "Buff.h"
#include <list>

using namespace std;

typedef list<Buff*> BUFFLIST;

class BuffManager {
	Role* parent;
	BUFFLIST buffList;	//buff�б�

public:
	BuffManager(Role*);
	void Attach(Buff*);
	void Detach(BUFFLIST::iterator iter);
	BUFFLIST::iterator FindBuffinList(Buff*);
	void Apply();	//������BuffӦ��һ�鲢������޻غ����Ѿ���buff,������ɾ��
	BUFFLIST GetBuffList();
};