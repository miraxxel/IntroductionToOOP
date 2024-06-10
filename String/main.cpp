#include<iostream>
using namespace std;

// строка - это динамический массив элементов char
// (массив - набор упорядоченных переменных, указатель на char в этом случае)
class String
{
	int size;	// Размер строки в байтах
	char* str;	// Адрес строки в динамической памяти
public:
	//			Constructors:
	// не реализуем инкапсюляцию, сразу переходим к конструкторам
	
	// конструктор по умолчанию, который создает пустую строку размером 80 байт
	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefaultConstructor:\t" << this << endl;
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