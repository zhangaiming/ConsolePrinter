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

/*=============================��ɫö��,���õ���ɫ�Ա�ʹ��=================================*/
enum class Color {
	DEFAULT = -1,	//Ĭ��ɫ
	BLACK = 0,	//��ɫ
	WHITE = FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED,	//��ɫ
	GRAY = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED,	//��ɫ

	DARKBLUE = FOREGROUND_BLUE,	//����ɫ
	BLUE = FOREGROUND_INTENSITY | FOREGROUND_BLUE,	//��ɫ

	DARKRED = FOREGROUND_RED,	//���ɫ
	RED = FOREGROUND_INTENSITY | FOREGROUND_RED,	//��ɫ

	GREEN = FOREGROUND_INTENSITY | FOREGROUND_GREEN,	//��ɫ
	DARKGREEN = FOREGROUND_GREEN,	//����ɫ

	CYAN = FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN,	//��ɫ
	DARKCYAN = FOREGROUND_BLUE | FOREGROUND_GREEN,	//����ɫ

	MAGENTA = FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED,	//��ɫ
	DARKMAGENTA = FOREGROUND_BLUE | FOREGROUND_RED,	//����ɫ

	DARKYELLOW = FOREGROUND_RED | FOREGROUND_GREEN,	//���ɫ
	YELLOW = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,	//��ɫ

};

/*==================================������ǰ��+����ɫ����==================================*/
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

/*===============================���Դ�ӡ��ͬ��ɫ���ַ�����Printer===============================*/

class ConsolePrinter {
public:
	static WORD defaultColor;	//����̨Ĭ����ɫ
	static HANDLE hOut;	//����̨������

public:
	//��ӡ�ַ���,��ɫͳһ
	static void Print(const Vector2& beginPos, const char* c, const Color& fore, const Color& back);//ָ������,����ǰ���ͺ�
	static void Print(const Vector2& beginPos, const char* c, const Colors& color);//ָ������,������ɫ��
	
	static void Print(const char* c, const Color& fore, const Color& back);//��ָ�������ڵ�ǰλ�ü������,����ǰ���ͺ�
	static void Print(const char* c, const Colors& color);//��ָ�������ڵ�ǰλ�ü������,������ɫ��

	static void PrintLine(const Vector2& beginPos, const char* c, const Color& fore, const Color& back);//ָ������,����ǰ���ͺ�,�������
	static void PrintLine(const Vector2& beginPos, const char* c, const Colors& color);//ָ������,������ɫ��,�������

	static void PrintLine(const char* c, const Color& fore, const Color& back);//��ָ�������ڵ�ǰλ�ü������,����ǰ���ͺ�,�������
	static void PrintLine(const char* c, const Colors& color);//��ָ�������ڵ�ǰλ�ü������,������ɫ��,�������

	//����Ĭ�ϵ���ɫ
	static void SetDefaultColor(const Color& fore, const Color& back);
	static void SetDefaultColor(const Colors& colors);
	
protected:
	
	static void GoTo(const Vector2& pos);//���ù��λ��
	static void SetColor(Colors colors);//���õ�ǰ������ɫ
	static void ResetColor();//��������ɫ����Ϊdefault�е�ֵ
};

