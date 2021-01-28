#include "StringTool.h"
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning( disable : 4996 )
using namespace std;
std::wstring s2ws(const std::string& s)
{
	std::string curLocale = setlocale(LC_ALL, "");
	const char* _Source = s.c_str();
	size_t _Dsize = mbstowcs(NULL, _Source, 0) + 1;

	wchar_t* _Dest = new wchar_t[_Dsize];
	wmemset(_Dest, 0, _Dsize);
	mbstowcs(_Dest, _Source, _Dsize);
	std::wstring result = _Dest;
	delete[]_Dest;
	setlocale(LC_ALL, curLocale.c_str());
	return result;
}
std::string ws2s(const std::wstring& ws)
{
	string curLocale = setlocale(LC_ALL, NULL);
	setlocale(LC_ALL, "chs");
	const wchar_t* _Source = ws.c_str();
	size_t  _Dsize = 2 * ws.size() + 1;
	char* _Dest = new char[_Dsize];
	memset(_Dest, 0, _Dsize);
	wcstombs(_Dest, _Source, _Dsize);
	string str;
	str = _Dest;
	delete[]_Dest;
	setlocale(LC_ALL, curLocale.c_str());
	return str;
}

std::string splitWstring(std::wstring _wtext, int up) {
	int cur = 0;
	int i = 0;
	wstring result = s2ws("");
	while (i < _wtext.length()) {
		if (_wtext[i] >= 0x4E00 && _wtext[i] <= 0x9FBB) {
			if (cur >= up - 1) {
				return ws2s(result);
			}
			else if (cur <= up - 2) {
				result += _wtext[i];
				cur += 2;
			}
		}
		else {
			if (cur >= up) {
				return ws2s(result);
			}
			else if (cur <= up - 1) {
				result += _wtext[i];
				cur += 1;
			}
		}
		i++;
	}
	return ws2s(result);
}

int GetColumnNum(const char* text)
{
	return GetColumnNum(s2ws(text));
}

int GetColumnNum(const std::string text) {
	return GetColumnNum(s2ws(text));
}

int GetColumnNum(const std::wstring text) {
	int i = 0;
	int result = 0;
	while (i < text.length()) {
		if (text[i] >= 0x4E00 && text[i] <= 0x9FBB) {
			result += 2;
		}
		else {
			result += 1;
		}
		i++;
	}
	return result;
}