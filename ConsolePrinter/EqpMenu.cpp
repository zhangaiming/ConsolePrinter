#include "EqpMenu.h"
#include "WidgetManager.h"
#include "GameInstance.h"
#include "EquipmentBar.h"
#include "Player.h"
#include "Button.h"
#include "List.h"
#include "TextBox.h"
#include "MainLevel.h"
#include "ItemStack.h"
#include "Equipment.h"
#include "MainLevel.h"

namespace eqp {
	List* temp;
	TextBox* mainTextBox;
	TextBox* statementBox;

	ItemStack* selectedStack = nullptr;
	int _where = 0;
	Player* player = nullptr;

	void OnTypeSelected();
	void OnCannelSelected();
	void OnEquipmentLighted();
	void OnEquipmentUnlighted();

	void LoadEquipmentList();

	void eqp::Load()
	{
		temp = (List*)*WidgetManager::FindWidsWithTag(LeftSelectList).begin();
		mainTextBox = (TextBox*)*WidgetManager::FindWidsWithTag(MainTextBox).begin();
		statementBox = (TextBox*)*WidgetManager::FindWidsWithTag(StateTextBox).begin();
		player = GameInstance::GetInstance()->GetPlayer();
		LoadEquipmentList();
	}

	void LoadEquipmentList() {
		temp->Clear();
		temp->AttachSelection(new Button("头盔", Vector2(0, 0), OnTypeSelected, OnEquipmentLighted, OnEquipmentUnlighted));
		temp->AttachSelection(new Button("上装", Vector2(0, 0), OnTypeSelected, OnEquipmentLighted, OnEquipmentUnlighted));
		temp->AttachSelection(new Button("下装", Vector2(0, 0), OnTypeSelected, OnEquipmentLighted, OnEquipmentUnlighted));
		temp->AttachSelection(new Button("护手", Vector2(0, 0), OnTypeSelected, OnEquipmentLighted, OnEquipmentUnlighted));
		temp->AttachSelection(new Button("护腿", Vector2(0, 0), OnTypeSelected, OnEquipmentLighted, OnEquipmentUnlighted));
		temp->AttachSelection(new Button(">>返回", Vector2(0, 0), OnCannelSelected));
		temp->Print();
	}

	void LoadEquipmentOperateList();

	void OnTypeSelected(){
		
		LoadEquipmentOperateList();
	}
	
	void OnEquipmentLighted() {
		mainTextBox->Clear();
		_where = temp->GetCurIndex();
		selectedStack = GameInstance::GetInstance()->GetPlayer()->GetEquipmentBar()->GetEquipment(_where);
		if (selectedStack == nullptr) {
			statementBox->Clear();
			statementBox->WriteLine("未装备该部位!");
		}
		else {
			//selectedStack->SetAmount(1);
			statementBox->Clear();
			statementBox->WriteLine(string("装备名称: ") + selectedStack->item->GetName());
			statementBox->WriteLine(string("装备介绍: ") + selectedStack->item->GetDesc());
		}
		
	}

	void OnEquipmentUnlighted() {
		
	}

	void OnCannelSelected() {
		LoadMainMenu();
	}

	void OnUnequipPressed();
	void OnDropPressed();
	void OnECannelSelected();

	void LoadEquipmentOperateList() {
		temp->Clear();
		if (selectedStack == nullptr) {
			statementBox->Clear();
			temp->AttachSelection(new Button(">>返回", Vector2(0, 0), OnECannelSelected));
		}
		else {
			statementBox->Clear();
			mainTextBox->Clear();
			switch ((int)((Equipment*)selectedStack->item)->GetEType()) {
			case 0:mainTextBox->WriteLine("[头盔]"); break;
			case 1:mainTextBox->WriteLine("[上装]"); break;
			case 2:mainTextBox->WriteLine("[下装]"); break;
			case 3:mainTextBox->WriteLine("[护手]"); break;
			case 4:mainTextBox->WriteLine("[护腿]"); break;
			}

			mainTextBox->WriteLine(string("装备名称: ") + selectedStack->item->GetName());
			mainTextBox->WriteLine(string("装备介绍: ") + selectedStack->item->GetDesc());

			temp->AttachSelection(new Button("卸下", Vector2(0, 0), OnUnequipPressed));
			temp->AttachSelection(new Button("丢弃", Vector2(0, 0), OnDropPressed));
			temp->AttachSelection(new Button(">>返回", Vector2(0, 0), OnECannelSelected));
		}
		temp->Print();
	}
	
	void OnUnequipPressed() {
		if (player->GetInventory()->GetStacksNum() == player->GetInventory()->GetCapacity()) {
			//如果背包满了
			statementBox->Clear();
			statementBox->WriteLine("卸下失败,背包空间不足,请先清理背包!");
			OnECannelSelected();
		}
		else {
			player->GetInventory()->AddItemStack(selectedStack);
			player->GetEquipmentBar()->Unequip(_where);
			OnECannelSelected();
		}
	}
	
	void OnDropPressed() {
		player->GetEquipmentBar()->Unequip(_where);
		OnECannelSelected();
	}

	void OnECannelSelected() {
		LoadEquipmentList();
	}
}