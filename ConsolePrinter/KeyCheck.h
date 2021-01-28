#pragma once
#include <conio.h>
#include <iostream>

void CheckLoop() {
	while (1) {
		if (_kbhit())
			//当按下按键
		{
			std::cout << _getch();
		}
	}
}