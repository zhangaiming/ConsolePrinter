#include "Items.h"
#include <stdio.h>

Cup::Cup() :Item("杯子", "这是一个杯子", 16)
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

Pen::Pen() :Item("笔", "这是一支笔", 4)
{
}

void Pen::OnUsed(Role* target)
{
	printf("这是一支笔");
}

int Pen::GetType()
{
	return 2;
}
