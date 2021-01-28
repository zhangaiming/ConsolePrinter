#include "LevelManager.h"
#include "Level.h"
#include "Screen.h"

Level* LevelManager::curLevel = nullptr;

void LevelManager::Load(Level* target)
{
	if (curLevel != nullptr)
		curLevel->OnDestory();
	if (target != nullptr) {
		Screen::Erase();
		target->OnLoad();
		curLevel = target;
	}
}

#include "BeginMenu.h"
void LevelManager::LoadBeginLevel()
{
	Load(new BeginMenu());
}
