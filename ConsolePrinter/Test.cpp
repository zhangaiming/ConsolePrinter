#include <Windows.h>
#include <iostream>

#include "GameInstance.h"

#include <conio.h>
#include <thread>

using namespace std;

int main() {
	GameInstance* gameInstance = GameInstance::GetInstance();
	gameInstance->Begin();
	return 0;
}

//void UIPrintTest() {
//	ButtonGroup* group = new ButtonGroup();
//	group->AttachSelection(new Button("��ť1", Vector2(0, 0), []() { cout << "��ť1������!"; }));
//	group->AttachSelection(new Button("��ť2", Vector2(0, 1), []() { cout << "��ť2������!"; }));
//	WidgetManager::Attach(group);
//	UIPrinter::Refresh();
//
//	group->Next();
//	UIPrinter::Refresh();
//}

//void SkillTest() {
//	Role* a = new Role(10, new string("������"));
//	Role* b = new Role(10, new string("target"));
//	SkillManager* manager = new SkillManager(a);
//	string result = string();
//	if ((result = manager->ApplySkill(new FireUp(), b)) != "")
//		cout << result;
//	else
//		cout << "NULL";
//	cout << endl;
//	manager->LearnSkill(new FireUp());
//
//	if ((result = manager->ApplySkill(new FireUp(), b)) != "")
//		cout << result;
//	else
//		cout << "NULL";
//	cout << endl;
//
//	manager->RemoveSkill(new FireUp());
//	if ((result = manager->ApplySkill(new FireUp(), b)) != "")
//		cout << result;
//	else
//		cout << "NULL";
//	cout << endl;
//
//	if ((result = manager->ApplySkill(new FireUp(), b)) != "")
//		cout << result;
//	else
//		cout << "NULL";
//	cout << endl;
//}

//void SkillTest() {
//	Role* role = new Role(10);
//	Role* target = new Role(10);
//	if (role->skillManager->Attach(&FireUp())) {
//		role->skillManager->Apply(0, role, target);
//	}
//	else
//		cout << "���ܼ���ʧ��...";
//
//	if (!role->skillManager->Detach(&FireUp())) {
//		cout << "����ɾ��ʧ��...";
//	}
//	else
//		cout << "����ɾ���ɹ�...";
//}

//void InvTest() {
//	void ShowInv(Inventory&);
//	//���Խ��:AddItem��������, resort����
//	Inventory* inv = new Inventory(5);
//	inv->AddItem(&Cup(), 10);
//	inv->AddItem(&Cup(), 10);
//
//	inv->AddItem(&Pen(), 10);
//	inv->AddItem(&Cup(), 13);
//	inv->AddItem(&Pen(), 10);
//	ShowInv(*inv);
//}

//void ShowInv(Inventory& inv) {
//	for (int i = 0; i < inv.GetCapacity(); i++) {
//		if (i < inv.GetStacksNum()) {
//			cout << inv.GetStackAt(i)->item->GetName() << "	*	" << inv.GetStackAt(i)->GetAmount() << endl;
//		}
//		else {
//			cout << "-----" << "	*	" << "-----" << endl;
//		}
//	}
//}

//void ItemStackTest() {
//	Poison* poison = new Poison();
//	ItemStack* itemStack = new ItemStack(poison, 10);
//
//	cout << "��Ʒ��: " << itemStack->item->GetName() << endl;
//	cout << "��Ʒ����: " << itemStack->item->GetDesc() << endl;
//	cout << "����: " << itemStack->GetAmount() << endl;
//
//	itemStack->SetAmount(17);
//
//	cout << endl << "�޸ĺ������Ϊ: " << itemStack->GetAmount() << endl;
//}
//void BuffListTest() {
//	//���Խ�� һ������
//	void ShowAttribute(Attribute*);
//
//	Role* role = new Role();
//	ShowAttribute(role->attribute);
//	BuffManager* buffManager = new BuffManager(role);
//	buffManager->Attach(&BurntBuff(10));
//	buffManager->Apply();
//	role->effectManager->Apply();
//	ShowAttribute(role->attribute);
//}
//
//void EffectListTest(){
//	//���Խ�� Apply����,�����޸��ж�����,Attach����
//	void ShowAttribute(Attribute*);
//
//	Role* role = &Role();
//	EffectManager* effectManager = new EffectManager(role);
//	ShowAttribute(role->attribute);
//	Effect* e = new Effect(EffectType::PLUS_MAXHP, 10);
//	effectManager->Attach(e);
//	effectManager->Apply();
//	cout << endl;
//	ShowAttribute(role->attribute);
//}
//
//void ShowAttribute(Attribute* attribute) {
//	cout << "��ǰHP:" <<attribute->GetCurHP() << endl;
//	cout << "���HP:" << attribute->GetMaxHP() << endl;
//	cout << "������:" << attribute->GetATK() << endl;
//	cout << "������:" << attribute->GetDEF() << endl;
//	cout << "�ٶ�:" << attribute->GetSPD() << endl;
//}
//
//void CheckColor() {
//	//
//	//��ɫ���Դ���
//	//
//
//	/*ConsolePrinter::Print(Vector2(0, 0), "��ɫ", Color::WHITE, Color::NONE);
//	ConsolePrinter::Print(Vector2(0, 1), "��ɫ", Colors(Color::GRAY, Color::NONE));
//
//	ConsolePrinter::Print(Vector2(0, 2), "��ɫ", Color::BLUE, Color::NONE);
//	ConsolePrinter::Print(Vector2(0, 3), "����ɫ", Colors(Color::DARKBLUE, Color::NONE));
//
//	ConsolePrinter::Print(Vector2(0, 4), "��ɫ", Color::RED, Color::NONE);
//	ConsolePrinter::Print(Vector2(0, 5), "���ɫ", Colors(Color::DARKRED, Color::NONE));
//
//	ConsolePrinter::Print(Vector2(0, 6), "��ɫ", Color::GREEN, Color::NONE);
//	ConsolePrinter::Print(Vector2(0, 7), "����ɫ", Colors(Color::DARKGREEN, Color::NONE));
//
//	ConsolePrinter::Print(Vector2(0, 8), "��ɫ", Color::CYAN, Color::NONE);
//	ConsolePrinter::Print(Vector2(0, 9), "����ɫ", Colors(Color::DARKCYAN, Color::NONE));
//
//	ConsolePrinter::Print(Vector2(0, 10), "��ɫ", Color::MAGENTA, Color::NONE);
//	ConsolePrinter::Print(Vector2(0, 11), "����ɫ", Colors(Color::DARKMAGENTA, Color::NONE));
//
//	ConsolePrinter::Print(Vector2(0, 12), "��ɫ", Color::YELLOW, Color::NONE);
//	ConsolePrinter::Print(Vector2(0, 13), "���ɫ", Colors(Color::DARKYELLOW, Color::NONE));*/
//}