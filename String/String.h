#pragma once
#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////
/////////		Объявление класса (Class Declaration)		///////////

class String
{
	int size;	// Размер строки в байтах
	char* str;	// Адрес строки в динамической памяти
public:
	const char* get_str()const;
	int get_size()const;
	char* get_str();	// для неконстантного объекта

	//			Constructors:
	explicit String(int size = 80);
	String(const char str[]);
	String(const String& other);
	~String();

	//			Operators:
	String& operator=(const String& other);
	//			Methods:
	void print()const;
};

String operator+(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);

/////////	Конец объявления класса (Class Declaration end)		///////////
//////////////////////////////////////////////////////////////////////////