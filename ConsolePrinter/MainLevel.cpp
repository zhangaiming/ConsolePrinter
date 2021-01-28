#include "MainLevel.h"
#include "Button.h"
#include "ButtonGroup.h"
#include "WidgetManager.h"
#include "ConsolePrinter.h"
#include "UI_DEF.h"



void MainLevel::OnLoad()
{
	DrawFrame();
	LoadWidget();
	SetBeginText();
}

#include "Label.h"
#include "Button.h"
#include "ButtonGroup.h"
#include "List.h"
#include "GameInstance.h"
#include "Player.h"

void LoadUpperStateBox() {
	string pn;
	if (GameInstance::GetInstance()->GetPlayer() != nullptr)
		pn = GameInstance::GetInstance()->GetPlayer()->GetName().data();
	Label* playerName_pre = new Label(10, Vector2(1, 1), "你的名字: ", Color::DARKCYAN);
	Label* playerName = new Label(SCREENSIZE_HOR / 5 * 2 - 12, Vector2(11, 1), pn.data(), Color::DARKGREEN);
	playerName->tag = PlayerNameLabel;

	playerName_pre->Print();
	playerName->Print();

	Label* enemyName_pre = new Label(10, Vector2(1 + SCREENSIZE_HOR / 5 * 3, 1), "怪物名字: ", Color::DARKCYAN);
	Label* enemyName = new Label(SCREENSIZE_HOR / 5 * 2 - 12, Vector2(SCREENSIZE_HOR / 5 * 3 + 11, 1), "", Color::DARKGREEN);
	enemyName->tag = EnemyNameLabel;

	enemyName_pre->Print();
	enemyName->Print();
}

void LoadSelectList(){
	List* selectList = new List(Vector2(1, 6), Vector2(28, SCREENSIZE_VER - 10));
	selectList->tag = LeftSelectList;
}

#include "TextBox.h"
void LoadMainTextBox() {
	TextBox* textBox = new TextBox(Vector2(31, 6), Vector2(SCREENSIZE_HOR - 32, SCREENSIZE_VER - 10));
	textBox->tag = MainTextBox;
}

void LoadStateTextBox() {
	TextBox* textBox = new TextBox(Vector2(1, SCREENSIZE_VER - 3), Vector2(SCREENSIZE_HOR - 2, 2));
	textBox->tag = StateTextBox;
}

void LoadWidget() {
	LoadUpperStateBox();
	LoadSelectList();
	LoadMainTextBox();
	LoadStateTextBox();
}

void LoadMainMenu() {
	
	TextBox* box = (TextBox*)*WidgetManager::FindWidsWithTag(MainTextBox).begin();
	box->Clear();
	box->WriteLine("请在左侧选择要进行的操作!");

	Button* explore = new Button("探险", Vector2(0, 0), OnExplorePressed);
	Button* checkUp = new Button("查看属性", Vector2(0, 0), OnCheckUpPressed);
	Button* openInv = new Button("查看背包", Vector2(0, 0), OnOpenInventoryPressed);
	Button* showEqp = new Button("打开装备栏", Vector2(0, 0), OnShowEqpPressed);
	Button* exit = new Button(">>退出", Vector2(0, 0), OnExitPressed);
	List* list = (List*)*WidgetManager::FindWidsWithTag(LeftSelectList).begin();
	list->Clear();

	WidgetManager::FocusOn(list->GetHandle());
	list->AttachSelection(explore);
	list->AttachSelection(checkUp);
	list->AttachSelection(openInv);
	list->AttachSelection(showEqp);
	list->AttachSelection(exit);
	list->Print();
}

void DrawFrame() {
	//Upper
	ConsolePrinter::PrintRectangle("#", Vector2(0, 0), SCREENSIZE_HOR / 5 * 2, 6, Color::DARKMAGENTA);
	ConsolePrinter::PrintRectangle("#", Vector2(SCREENSIZE_HOR / 5 * 3, 0), SCREENSIZE_HOR / 5 * 2, 6, Color::DARKMAGENTA);
	ConsolePrinter::PrintHorLine("#", Vector2(SCREENSIZE_HOR / 5 * 2, 4), SCREENSIZE_HOR / 5, Color::DARKMAGENTA);

	//Left
	ConsolePrinter::PrintVerLine("#", Vector2(30, 6), SCREENSIZE_VER - 9, Color::DARKMAGENTA);

	//Bottom
	ConsolePrinter::PrintHorLine("#", Vector2(0, SCREENSIZE_VER - 4), SCREENSIZE_HOR, Color::DARKMAGENTA);
}



void SetBeginText() {
	LoadMainMenu();
}

void OnExplorePressed() {

}

#include "AttMenu.h"
void OnCheckUpPressed() {
	att::Load();
}

#include "EqpMenu.h"
void OnShowEqpPressed() {
	eqp::Load();
}

#include "InvMenu.h"
void OnOpenInventoryPressed() {
	Load();
}

#include "GameInstance.h"
void OnExitPressed() {
	GameInstance::GetInstance()->Shutdown();
}