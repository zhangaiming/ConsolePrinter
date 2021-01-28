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
		temp->AttachSelection(new Button("ͷ��", Vector2(0, 0), OnTypeSelected, OnEquipmentLighted, OnEquipmentUnlighted));
		temp->AttachSelection(new Button("��װ", Vector2(0, 0), OnTypeSelected, OnEquipmentLighted, OnEquipmentUnlighted));
		temp->AttachSelection(new Button("��װ", Vector2(0, 0), OnTypeSelected, OnEquipmentLighted, OnEquipmentUnlighted));
		temp->AttachSelection(new Button("����", Vector2(0, 0), OnTypeSelected, OnEquipmentLighted, OnEquipmentUnlighted));
		temp->AttachSelection(new Button("����", Vector2(0, 0), OnTypeSelected, OnEquipmentLighted, OnEquipmentUnlighted));
		temp->AttachSelection(new Button(">>����", Vector2(0, 0), OnCannelSelected));
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
			statementBox->WriteLine("δװ���ò�λ!");
		}
		else {
			//selectedStack->SetAmount(1);
			statementBox->Clear();
			statementBox->WriteLine(string("װ������: ") + selectedStack->item->GetName());
			statementBox->WriteLine(string("װ������: ") + selectedStack->item->GetDesc());
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
			temp->AttachSelection(new Button(">>����", Vector2(0, 0), OnECannelSelected));
		}
		else {
			statementBox->Clear();
			mainTextBox->Clear();
			switch ((int)((Equipment*)selectedStack->item)->GetEType()) {
			case 0:mainTextBox->WriteLine("[ͷ��]"); break;
			case 1:mainTextBox->WriteLine("[��װ]"); break;
			case 2:mainTextBox->WriteLine("[��װ]"); break;
			case 3:mainTextBox->WriteLine("[����]"); break;
			case 4:mainTextBox->WriteLine("[����]"); break;
			}

			mainTextBox->WriteLine(string("װ������: ") + selectedStack->item->GetName());
			mainTextBox->WriteLine(string("װ������: ") + selectedStack->item->GetDesc());

			temp->AttachSelection(new Button("ж��", Vector2(0, 0), OnUnequipPressed));
			temp->AttachSelection(new Button("����", Vector2(0, 0), OnDropPressed));
			temp->AttachSelection(new Button(">>����", Vector2(0, 0), OnECannelSelected));
		}
		temp->Print();
	}
	
	void OnUnequipPressed() {
		if (player->GetInventory()->GetStacksNum() == player->GetInventory()->GetCapacity()) {
			//�����������
			statementBox->Clear();
			statementBox->WriteLine("ж��ʧ��,�����ռ䲻��,����������!");
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