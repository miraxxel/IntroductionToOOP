#include<iostream>
using namespace std;

// строка - это динамический массив элементов char
// (массив - набор упорядоченных переменных, указатель на char в этом случае)
class String
{
	int size;	// Размер строки в байтах
	char* str;	// Адрес строки в динамической памяти
public:
	const char* get_str()const
	{
		return str;
	}
	int get_size()const
	{
		return size;
	}
	//			Constructors:
	// конструктор по умолчанию, который создает пустую строку размером 80 байт
	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefaultConstructor:\t" << this << endl;
	}
	String(const char str[])
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; str[i]; i++)this->str[i] = str[i];
		cout << "Constructor:\t\t" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t\t" << this << endl;
	}

	//			Methods:
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

String operator+(const String& str1, const String& str2) 
{
	int newSize = str1.get_size() + str2.get_size(); 
	char* newStr = new char[newSize + 1];
	// пока не готово
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

void main()
{
	setlocale(LC_ALL, "");

	/*String str;
	str.print();*/

	String str1 = "Hello";
	String str2 = "World";
	
	cout << str1 << endl;
	cout << str2 << endl;
	
	String str3 = str1 + str2;
	cout << str3 << endl;
}