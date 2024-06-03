#include<iostream>
using namespace std;

#define delimiter "\n-----------------------------------------\n"

class Fraction
{
	int integer;
	int numerator;
	int denominator;

public:
	//			Incapsulation
	int get_integer()const { return integer; }
	int get_numerator() const { return numerator; }
	int get_denominator() const { return denominator; }

	void set_integer(int integer) { this->integer = integer; }
	void set_numerator(int numerator) { this->numerator = numerator; }
	void set_denominator(int denominator)
	{
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;
	}

	//			Constructors
	Fraction()
	{
		integer = 0;
		numerator = 0;
		denominator = 1;
		cout << "DefaultConstructor:\t" << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor: \t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor: \t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor: \t\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//			Operators:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	Fraction& operator++() // Prefix increment
	{
		numerator += denominator;
		//to_proper(); // упрощаем дробь
		return *this; // разыменованный указатель на объект
	}
	Fraction operator++(int) // Postfix increment
	{
		// т.к. постфиксный инкремент выполняется самым последним, 
		// то мы сохраняем старое значение объекта
		Fraction old = *this;
		numerator += denominator;
		//to_proper(); // упрощаем дробь
		return old; // возвращаем старый объект
	}


	//			Methods:
	Fraction& to_proper() // выделяем целую часть
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction& to_improper() // в неправильную дробь (убираем целую часть)
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}

	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}

	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
};

// что бы не копировать операнды во fraction (не создавать лишний объект и экономить память, 
// но если это преводит к нежелательному изменению данных, то передаем по значению)
Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	return left * right.inverted();
}
bool operator==(Fraction& left, Fraction& right)
{
	left.to_improper();
	right.to_improper();
	return left.get_denominator() == right.get_denominator() && left.get_numerator() == right.get_numerator();
}
bool operator!=(Fraction& left, Fraction& right)
{
	left.to_improper();
	right.to_improper();
	return left.get_denominator() != right.get_denominator() && left.get_numerator() != right.get_numerator();
}
bool operator>(Fraction& left, Fraction& right)
{
	left.to_improper();
	right.to_improper();
	return left.get_denominator() > right.get_denominator() && left.get_numerator() > right.get_numerator();
}
bool operator<(Fraction& left, Fraction& right)
{
	left.to_improper();
	right.to_improper();
	return left.get_denominator() < right.get_denominator() && left.get_numerator() < right.get_numerator();
}
bool operator>=(Fraction& left, Fraction& right)
{
	left.to_improper();
	right.to_improper();
	return left.get_denominator() >= right.get_denominator() && left.get_numerator() >= right.get_numerator();
}
bool operator<=(Fraction& left, Fraction& right)
{
	left.to_improper();
	right.to_improper();
	return left.get_denominator() <= right.get_denominator() && left.get_numerator() <= right.get_numerator();
}

//define CONSTRUCTORS_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	Fraction A;		// DefaultConstructor
	A.print();

	Fraction B = 5; // SingleArgConstructor
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = D;
	E.print();

	Fraction F;
	F = E;
	F.print();
#endif // CONSTRUCTORS_CHECK

	Fraction A(2, 3, 4);
	/*A.to_improver();
	A.print();
	A.to_proper();*/
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	Fraction C = A / B;
	C.print();

	A.print();
	B.print();

	cout << delimiter << endl;

	cout << "Сравнение дробей A и B: " << (A == B) << endl;
	cout << "A не равно B: " << (A != B) << endl;

	cout << "A > B: " << (A > B) << endl;
	cout << "B > A: " << (B > A) << endl;

	cout << "A < B: " << (A < B) << endl;
	cout << "B < A: " << (B < A) << endl;

	cout << "A >= B: " << (A >= B) << endl;
	cout << "B >= A: " << (B >= A) << endl;

	cout << "A <= B: " << (A <= B) << endl;
	cout << "B <= A: " << (B <= A) << endl;

	cout << "Инкремент для A постфиксный: ";
	A.print();
	A++;
	A.print();
	cout << "Инкремент для B префиксный: ";
	B.print();
	++B;
	B.print();
}
