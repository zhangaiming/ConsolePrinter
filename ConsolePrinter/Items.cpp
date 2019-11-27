#include "Items.h"
#include <stdio.h>

Cup::Cup() :Item("����", "����һ������", 16)
{
}

void Cup::OnUsed(Role* target)
{
	printf("this is a cup!");
}

int Cup::GetType()
{
	return 1;
}

Pen::Pen() :Item("��", "����һ֧��", 4)
{
}

void Pen::OnUsed(Role* target)
{
	printf("����һ֧��");
}

int Pen::GetType()
{
	return 2;
}
