#include "Item.h"
#include "Role.h"

Item::Item(const char* _name, const char* _description, int _maxStack): maxStack(_maxStack),name(_name),description(_description)
{
}

char* Item::GetName()
{
	return (char*)name;
}

char* Item::GetDesc()
{
	return (char*)description;
}

void Item::OnUsed(Role* target)
{

}

int Item::GetType()
{
	return 0;
}

bool Item::EqualsTo(Item& item)
{
	/*if(item.GetType() == this->GetType())
		return true;
	return false;*/
	return *this == item;
}

bool Item::operator==(Item& b)
{
	if (this->GetType() == b.GetType())
		return true;
	return false;
}