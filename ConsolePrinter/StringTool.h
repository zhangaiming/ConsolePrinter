#pragma once
#include <string>

std::string ws2s(const std::wstring&);
std::wstring s2ws(const std::string&);
std::string splitWstring(std::wstring, int need);
int GetColumnNum(const std::string);
int GetColumnNum(const std::wstring);
int GetColumnNum(const char*);
