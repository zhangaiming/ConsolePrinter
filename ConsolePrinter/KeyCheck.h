#pragma once
#include <conio.h>
#include <iostream>

void CheckLoop() {
	while (1) {
		if (_kbhit())
			//�����°���
		{
			std::cout << _getch();
		}
	}
}