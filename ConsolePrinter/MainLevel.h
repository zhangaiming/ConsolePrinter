#pragma once

#define MainTextBox (char*)"MainTextBox"
#define PlayerNameLabel (char*)"PlayerNameLabel"
#define EnemyNameLabel (char*)"EnemyNameLabel"
#define LeftSelectList (char*)"LeftSelectList"
#define StateTextBox (char*)"StateTextBox"

#include "Level.h"
void LoadMainMenu();

void DrawFrame();
void LoadWidget();
void SetBeginText();

void OnExplorePressed();
void OnCheckUpPressed();
void OnOpenInventoryPressed();
void OnExitPressed();

void OnExplorePressed();
void OnCheckUpPressed();
void OnOpenInventoryPressed();
void OnExitPressed();
void OnShowEqpPressed();
class MainLevel : public Level{
public:
	void OnLoad();
};