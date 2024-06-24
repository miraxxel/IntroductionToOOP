#pragma once
#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////
/////////		���������� ������ (Class Declaration)		///////////

class String
{
	int size;	// ������ ������ � ������
	char* str;	// ����� ������ � ������������ ������
public:
	const char* get_str()const;
	int get_size()const;
	char* get_str();	// ��� �������������� �������

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

/////////	����� ���������� ������ (Class Declaration end)		///////////
//////////////////////////////////////////////////////////////////////////