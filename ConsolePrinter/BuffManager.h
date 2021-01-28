#pragma once
#include "Buff.h"
#include <list>

using namespace std;

typedef list<Buff*> BUFFLIST;

class BuffManager {
	Role* parent;
	BUFFLIST buffList;	//buff列表

public:
	BuffManager(Role*);
	void Attach(Buff*);
	void Detach(BUFFLIST::iterator iter);
	BUFFLIST::iterator FindBuffinList(Buff*);
	void Apply();	//将所有Buff应用一遍并检查有无回合数已尽的buff,若有则删除
	BUFFLIST GetBuffList();
};