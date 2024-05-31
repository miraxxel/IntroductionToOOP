#include<iostream>
using namespace std;

// дробь определяется как отношение количества взятых частей 
// к общему числу разделенных частей
class Fraction
{
	int numerator;
	int denominator;

public:
	// геттеры
	int get_numerator() const { return numerator; }
	int get_denominator() const { return denominator; }

	// сеттеры
	void set_numerator(int numerator) { this->numerator = numerator; }
	void set_denominator(int denominator) 
	{ 
		if (denominator != 0) 
			this->denominator = denominator; 
	}
	
	// конструктор
	Fraction(int numerator, int denominator)
	{
		this->numerator = numerator;
		this->denominator = denominator;
		cout << "(TwoArg) Constructor: \t" << this << endl;
	}
	// деструктор
	~Fraction()
	{
		cout << "Destructor: \t\t" << this << endl;
	}

	// перегрузка операторов
	// не успеваю, сделаю позже

	// методы
	void print()const
	{
		cout << this << ": fraction = " << numerator << "/" << denominator << endl;
	}
};


void main()
{
	setlocale(LC_ALL, "");

	Fraction A(1, 2);
	A.print();
}