#pragma once
#include "Vector.h"
#include <Windows.h>

#define FORE_DEFAULT Color::DEFAULT
#define FORE_Black Color::BLACK
#define FORE_WHITE Color::WHITE
#define FORE_GRAY Color::GRAY
#define FORE_DARKBLUE Color::DARKBLUE
#define FORE_BLUE Color::BLUE
#define FORE_DARKRED Color::DARKRED
#define FORE_RED Color::RED
#define FORE_GREEN Color::GREEN
#define FORE_DARKGREEN Color::DARKGREEN
#define FORE_CYAN Color::CYAN
#define FORE_DARKCYAN Color::DARKCYAN
#define FORE_MAGENTA Color::MAGENTA
#define FORE_DARKMAGENTA Color::DARKMAGENTA
#define FORE_DARKYELLOW Color::DARKYELLOW
#define FORE_YELLOW Color::YELLOW

#define BACK Color::DEFAULT * 16
#define BACK_Black Color::BLACK * 16
#define BACK_WHITE Color::WHITE * 16
#define BACK_GRAY Color::GRAY * 16
#define BACK_DARKBLUE Color::DARKBLUE * 16
#define BACK_BLUE Color::BLUE * 16
#define BACK_DARKRED Color::DARKRED * 16
#define BACK_RED Color::RED * 16
#define BACK_GREEN Color::GREEN * 16
#define BACK_DARKGREEN Color::DARKGREEN * 16
#define BACK_CYAN Color::CYAN * 16
#define BACK_DARKCYAN Color::DARKCYAN * 16
#define BACK_MAGENTA Color::MAGENTA * 16
#define BACK_DARKMAGENTA Color::DARKMAGENTA * 16
#define BACK_DARKYELLOW Color::DARKYELLOW * 16
#define BACK_YELLOW Color::YELLOW * 16

/*=============================颜色枚举,调好的颜色以便使用=================================*/
enum class Color {
	DEFAULT = -1,	//默认色
	BLACK = 0,	//黑色
	WHITE = FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED,	//白色
	GRAY = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED,	//灰色

	DARKBLUE = FOREGROUND_BLUE,	//深蓝色
	BLUE = FOREGROUND_INTENSITY | FOREGROUND_BLUE,	//蓝色

	DARKRED = FOREGROUND_RED,	//深红色
	RED = FOREGROUND_INTENSITY | FOREGROUND_RED,	//红色

	GREEN = FOREGROUND_INTENSITY | FOREGROUND_GREEN,	//绿色
	DARKGREEN = FOREGROUND_GREEN,	//深绿色

	CYAN = FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN,	//青色
	DARKCYAN = FOREGROUND_BLUE | FOREGROUND_GREEN,	//深青色

	MAGENTA = FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED,	//紫色
	DARKMAGENTA = FOREGROUND_BLUE | FOREGROUND_RED,	//深紫色

	DARKYELLOW = FOREGROUND_RED | FOREGROUND_GREEN,	//深黄色
	YELLOW = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,	//黄色

};

/*==================================保存有前景+背景色的类==================================*/
struct Colors {
private:
	Color foregroundColor;
	Color backgroundColor;

public:
	WORD GetForeColor();
	WORD GetBackColor();
	Colors():foregroundColor(Color::DEFAULT),backgroundColor(Color::DEFAULT){}
	Colors(const Color& fore, const Color& back):foregroundColor(fore),backgroundColor(back){}
};

/*===============================可以打印不同颜色的字符串的Printer===============================*/

class ConsolePrinter {
public:
	static WORD defaultColor;	//控制台默认颜色
	static HANDLE hOut;	//控制台输出句柄

public:
	//打印字符串,颜色统一
	static void Print(const Vector2& beginPos, const char* c, const Color& fore, const Color& back);//指定坐标,输入前景和后景
	static void Print(const Vector2& beginPos, const char* c, const Colors& color);//指定坐标,输入颜色组
	
	static void Print(const char* c, const Color& fore, const Color& back);//不指定坐标在当前位置继续输出,输入前景和后景
	static void Print(const char* c, const Colors& color);//不指定坐标在当前位置继续输出,输入颜色组

	static void PrintLine(const Vector2& beginPos, const char* c, const Color& fore, const Color& back);//指定坐标,输入前景和后景,输出后换行
	static void PrintLine(const Vector2& beginPos, const char* c, const Colors& color);//指定坐标,输入颜色组,输出后换行

	static void PrintLine(const char* c, const Color& fore, const Color& back);//不指定坐标在当前位置继续输出,输入前景和后景,输出后换行
	static void PrintLine(const char* c, const Colors& color);//不指定坐标在当前位置继续输出,输入颜色组,输出后换行

	//设置默认的颜色
	static void SetDefaultColor(const Color& fore, const Color& back);
	static void SetDefaultColor(const Colors& colors);
	
protected:
	
	static void GoTo(const Vector2& pos);//设置光标位置
	static void SetColor(Colors colors);//设置当前画笔颜色
	static void ResetColor();//将画笔颜色设置为default中的值
};

