#include <Windows.h>
#include <iostream>

#include "Role.h"
#include "Skills.h"

using namespace std;



int main() {
	
}

//void SkillTest() {
//	Role* role = new Role(10);
//	Role* target = new Role(10);
//	if (role->skillManager->Attach(&FireUp())) {
//		role->skillManager->Apply(0, role, target);
//	}
//	else
//		cout << "技能加入失败...";
//
//	if (!role->skillManager->Detach(&FireUp())) {
//		cout << "技能删除失败...";
//	}
//	else
//		cout << "技能删除成功...";
//}

//void InvTest() {
//	void ShowInv(Inventory&);
//	//测试结果:AddItem方法正常, resort正常
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
//	cout << "物品名: " << itemStack->item->GetName() << endl;
//	cout << "物品描述: " << itemStack->item->GetDesc() << endl;
//	cout << "数量: " << itemStack->GetAmount() << endl;
//
//	itemStack->SetAmount(17);
//
//	cout << endl << "修改后的数量为: " << itemStack->GetAmount() << endl;
//}
//void BuffListTest() {
//	//测试结果 一切正常
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
//	//测试结果 Apply正常,属性修改判定正常,Attach正常
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
//	cout << "当前HP:" <<attribute->GetCurHP() << endl;
//	cout << "最大HP:" << attribute->GetMaxHP() << endl;
//	cout << "攻击力:" << attribute->GetATK() << endl;
//	cout << "防御力:" << attribute->GetDEF() << endl;
//	cout << "速度:" << attribute->GetSPD() << endl;
//}
//
//void CheckColor() {
//	//
//	//颜色测试代码
//	//
//
//	/*ConsolePrinter::Print(Vector2(0, 0), "白色", Color::WHITE, Color::NONE);
//	ConsolePrinter::Print(Vector2(0, 1), "灰色", Colors(Color::GRAY, Color::NONE));
//
//	ConsolePrinter::Print(Vector2(0, 2), "蓝色", Color::BLUE, Color::NONE);
//	ConsolePrinter::Print(Vector2(0, 3), "深蓝色", Colors(Color::DARKBLUE, Color::NONE));
//
//	ConsolePrinter::Print(Vector2(0, 4), "红色", Color::RED, Color::NONE);
//	ConsolePrinter::Print(Vector2(0, 5), "深红色", Colors(Color::DARKRED, Color::NONE));
//
//	ConsolePrinter::Print(Vector2(0, 6), "绿色", Color::GREEN, Color::NONE);
//	ConsolePrinter::Print(Vector2(0, 7), "深绿色", Colors(Color::DARKGREEN, Color::NONE));
//
//	ConsolePrinter::Print(Vector2(0, 8), "青色", Color::CYAN, Color::NONE);
//	ConsolePrinter::Print(Vector2(0, 9), "深青色", Colors(Color::DARKCYAN, Color::NONE));
//
//	ConsolePrinter::Print(Vector2(0, 10), "紫色", Color::MAGENTA, Color::NONE);
//	ConsolePrinter::Print(Vector2(0, 11), "深紫色", Colors(Color::DARKMAGENTA, Color::NONE));
//
//	ConsolePrinter::Print(Vector2(0, 12), "黄色", Color::YELLOW, Color::NONE);
//	ConsolePrinter::Print(Vector2(0, 13), "深黄色", Colors(Color::DARKYELLOW, Color::NONE));*/
//}