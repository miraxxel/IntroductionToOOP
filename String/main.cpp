#include"String.h"

/// ----------------------------------------------------------------- ///

#define CAT_CHECK		// CAT - от 'конкатенация'
//#define CONSTRUCTORS_CHECK

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