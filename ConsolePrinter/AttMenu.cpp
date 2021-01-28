#include "AttMenu.h"
#include "MainLevel.h"
#include "WidgetManager.h"
#include "Button.h"
#include "List.h"
#include "TextBox.h"
#include "Player.h"
#include "GameInstance.h"

namespace att {
	List* temp;
	TextBox* mainTextBox;
	Player* player;

	void OnCannelPressed();

	void att::Load()
	{
		temp = (List*)*WidgetManager::FindWidsWithTag(LeftSelectList).begin();
		mainTextBox = (TextBox*)*WidgetManager::FindWidsWithTag(MainTextBox).begin();
		player = GameInstance::GetInstance()->GetPlayer();

		mainTextBox->Clear();
		temp->Clear();

		temp->AttachSelection(new Button(">>返回", Vector2(0, 0), OnCannelPressed));

		mainTextBox->WriteLine(string("玩家名称: ") + player->GetName());
		Attribute* attr = player->GetAttribute();
		string hp = to_string(attr->GetCurHP());
		hp += "/";
		hp += to_string(attr->GetMaxHP());

		string mm = to_string(attr->GetCurMM());
		mm += "/";
		mm += to_string(attr->GetMaxMM());
		mainTextBox->WriteLine(string("血量: ") + hp);
		mainTextBox->WriteLine(string("魔力: ") + mm);
		mainTextBox->WriteLine(string("攻击力: ") + to_string(attr->GetATK()));
		mainTextBox->WriteLine(string("防御力: ") + to_string(attr->GetDEF()));
		mainTextBox->WriteLine(string("速度: " + to_string(attr->GetSPD())));

		temp->Print();

	}

	void OnCannelPressed() {
		LoadMainMenu();
	}
}
