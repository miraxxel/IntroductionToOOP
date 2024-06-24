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
	// для неконстантного объекта
	char* get_str()
	{
		return str;
	}
	//			Constructors:
	// конструктор по умолчанию, который создает пустую строку размером 80 байт
							// :size(size) - перед () - переменная член класса, в () принимаемый параметр
	explicit String(int size = 80):size(size), str(new char[size] {})
	{
		//this->size = size;
		//this->str = new char[size] {};
		cout << "DefaultConstructor:\t" << this << endl;
	}
	String(const char str[]) :size(strlen(str) + 1), str(new char[size] {})
	{
		//this->size = strlen(str) + 1;
		//this->str = new char[size] {};
		for (int i = 0; str[i]; i++)this->str[i] = str[i];
		cout << "Constructor:\t\t" << this << endl;
	}

	String(const String& other) :size(other.size), str(new char[size] {})
	{
		// Deep Copy
		//this->size = other.size;
		//this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << this << endl;
	}

	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t\t" << this << endl;
	}

	//			Operators:
	String& operator=(const String& other)
	{
		if (this == &other)return *this;

		delete[] str;
		this->size = other.size;
		this->str = new char[size] {};

		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssignment:\t\t" << this << endl;

		return *this;
	}
	//			Methods:
	void print()const
	{
		cout << "Obj:\t" << this<<"\t";
		cout << "Size:\t" << size << "\t";
		cout << "Addr:\t" << &str << "\t";
		cout << "Str:\t" << str << endl;
	}
};

String operator+(const String& left, const String& right) 
{
	/*int newSize = str1.get_size() + str2.get_size(); 
	char* newStr = new char[newSize + 1];*/

	// -1 т.к. в конце каждой строке есть конкатенирующий ноль, здесь у нас их 2
	String buffer(left.get_size() + right.get_size() - 1);	// from 'int' to 'string'
	for (int i = 0; i < left.get_size(); i++)
		buffer.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		buffer.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	buffer.print();
	return buffer;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

//#define CAT_CHECK		// CAT - от 'конкатенация'
#define CONSTRUCTORS_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	String str1;	// Default Constructor
	str1.print();

	String str2(8);
	str2.print();	// 1Arg Constructor

	String str3 = "Hello"; // 1Arg Constructor
	str3.print();

	String str4();	// Здесь НЕ вызывается конструктор и НЕ создается объект, 
					// в этом выражении объявляется функция str4(), которая ничего не принимает, и возвращает объект класса 'String'.
	//str4.print();
	// Для явного вызова конструктора по умолчанию использовать {}, но не (
	String str5{};	// Явный вызов конструктора по умолчанию
	str5.print();

	String str6{ str3 }; // Copy Constructor, передаем то, что хотим скопировать, обычно передается в (), но в конструкторах в {}
	str6.print();

#endif // CONSTRUCTORS_CHECK

#ifdef CAT_CHECK 
	/*String str;
	str.print();*/

	String str1 = "Hello";
	String str2 = "World";

	str1 = str1;
	
	//String str3 = str1 + str2; // CopyConstructor
	String str3;
	str3 = str1 + str2;	// CopyAssignment
	//str3.print();
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;	// HelloWorld
#endif // CAT_CHECK

}