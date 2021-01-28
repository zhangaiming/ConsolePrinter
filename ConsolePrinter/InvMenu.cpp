#include "InvMenu.h"
#include "List.h"
#include "WidgetManager.h"
#include "GameInstance.h"
#include "MainLevel.h"
#include "Button.h"
#include "Player.h"
#include "Inventory.h"
#include "ItemStack.h"
#include "Item.h"
#include "TextBox.h"
#include "Equipment.h"

void LoadUsableItemOperateMenu();
void OnItemUsePressed();
void OnDropPressed();
void OnCannelPressed();
void OnItemSelected();
void LoadEquipmenOperateMenu();
void OnItemLighted();
void OnItemUnlighted();
void OnEquipmentUsePressed();

ItemStack* selectedStack = nullptr;
List* temp;
TextBox* stateBox;

void Load() {
	temp = (List*)*WidgetManager::FindWidsWithTag(LeftSelectList).begin();
	stateBox = (TextBox*)*WidgetManager::FindWidsWithTag(StateTextBox).begin();
	temp->Clear();
	Inventory* inv = GameInstance::GetInstance()->GetPlayer()->GetInventory();
	inv->Sort();
	for (int i = 0; i < inv->GetStacksNum(); i++) {
		ItemStack* cur = inv->GetStackAt(i);
		if (cur != nullptr) {
			string text = cur->item->GetName();
			text += "			*";
			text += std::to_string(cur->GetAmount());
			temp->AttachSelection(new Button(text.data(), Vector2(0, 0), OnItemSelected, OnItemLighted, OnItemUnlighted));
		}
	}
	temp->AttachSelection(new Button(">>返回", Vector2(0, 0), []() {LoadMainMenu(); }));

	
	temp->Print();
}

void OnItemLighted() {
	Inventory* inv = GameInstance::GetInstance()->GetPlayer()->GetInventory();
	stateBox->WriteLine(inv->GetStackAt(temp->GetCurIndex())->item->GetDesc());
}

void OnItemUnlighted() {
	stateBox->Clear();
}

void OnItemSelected() {
	Inventory* inv = GameInstance::GetInstance()->GetPlayer()->GetInventory();
	selectedStack = inv->GetStackAt(temp->GetCurIndex());
	if (selectedStack->item->GetType() < 10000) {
		LoadUsableItemOperateMenu();
	}
	else if (selectedStack->item->GetType() > 10000) {
		LoadEquipmenOperateMenu();
	}
}

void LoadUsableItemOperateMenu() {
	temp = (List*)*WidgetManager::FindWidsWithTag("LeftSelectList").begin();
	temp->Clear();
	temp->AttachSelection(new Button(">>使用", Vector2(0, 0), OnItemUsePressed));
	temp->AttachSelection(new Button(">>丢弃", Vector2(0, 0), OnDropPressed));
	temp->AttachSelection(new Button(">>返回", Vector2(0, 0), OnCannelPressed));
	temp->Print();
}

void LoadEquipmenOperateMenu() {
	temp = (List*)*WidgetManager::FindWidsWithTag("LeftSelectList").begin();
	temp->Clear();
	temp->AttachSelection(new Button(">>装备", Vector2(0, 0), OnEquipmentUsePressed));
	temp->AttachSelection(new Button(">>丢弃", Vector2(0, 0), OnDropPressed));
	temp->AttachSelection(new Button(">>返回", Vector2(0, 0), OnCannelPressed));
	temp->Print();
}

#include "Player.h"

void OnItemUsePressed() {
	selectedStack->Use(GameInstance::GetInstance()->GetPlayer());
	Load();
}

void OnEquipmentUsePressed() {
	Player* player = GameInstance::GetInstance()->GetPlayer();
	ItemStack* e = selectedStack;
	ItemStack* equippedE = nullptr;
	equippedE = player->GetEquipmentBar()->GetEquipment((int)((Equipment*)e->item)->GetEType());
	player->GetEquipmentBar()->Equip(e);
	player->GetInventory()->DropItem(e->item, 1);
	if (equippedE != nullptr) {
		player->GetInventory()->AddItemStack(equippedE);
	}
	Load();
}

void OnDropPressed() {
	GameInstance::GetInstance()->GetPlayer()->GetInventory()->DropItem(selectedStack->item, selectedStack->GetAmount());
	Load();
}

void OnCannelPressed() {
	Load();
}