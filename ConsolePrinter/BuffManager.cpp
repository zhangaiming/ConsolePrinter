#include "BuffManager.h"

BuffManager::BuffManager(Role* role)
{
	parent = role;
}

void BuffManager::Attach(Buff* buff)
{
	buffList.push_back(buff);
	buff->OnAttach(parent);
}

void BuffManager::Detach(BUFFLIST::iterator iter)
{
	(*iter)->OnDetach(parent);
	buffList.erase(iter);
}

BUFFLIST::iterator BuffManager::FindBuffinList(Buff* buff)
{
	BUFFLIST::iterator iter;
	for (iter = buffList.begin(); iter != buffList.end(); iter++) {
		if ((*iter) == buff) {
			break;
		}
	}
	return iter;
}



void BuffManager::Apply()
{
	BUFFLIST temp(buffList);
	for (BUFFLIST::iterator iter = buffList.begin(); iter != buffList.end();) {
		(*iter)->OnApply(parent);
		if ((*iter)->GetRestTurn() <= 0) {
			Detach(iter++);
			return;
		}
		iter++;
	}
}

BUFFLIST BuffManager::GetBuffList()
{
	return buffList;
}
