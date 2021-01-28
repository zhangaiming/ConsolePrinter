#include "Level.h"
#include "WidgetManager.h"
#include "Widget.h"

void Level::OnDestory()
{
	WidgetManager::ClearAll();
}
