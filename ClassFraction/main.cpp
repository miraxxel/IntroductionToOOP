#include<iostream>
using namespace std;

#define delimiter "\n-----------------------------------------\n"

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);

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
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}

	Fraction& operator++() // Prefix increment
	{
		numerator += denominator;
		//to_proper(); // упрощаем дробь
		return *this; // разыменованный указатель на объект

		/* // другой вариант
		integer++;
		return *this;*/
	}
	Fraction operator++(int) // Postfix increment
	{
		// т.к. постфиксный инкремент выполняется самым последним, 
		// то мы сохраняем старое значение объекта
		Fraction old = *this;
		numerator += denominator;
		//to_proper(); // упрощаем дробь
		return old; // возвращаем старый объект

		/*Fraction old = *this;
		integer++;
		//to_proper(); // упрощаем дробь
		return old; // возвращаем старый объект*/
	}


	//			Methods:
	Fraction& reduce()
	{
		// Алгоритм Евклида
		int more, less, rest;

		if (numerator > denominator) more = numerator, less = denominator;
		else more = denominator, less = numerator;

		do
		{
			rest = more % less;
			more = less;
			less = more;
		} while (rest);

		int GCD = more; // GCD - Greatest Common Divesor
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}

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
	).to_proper().reduce();
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	return left * right.inverted();
}

//				Comparison operator
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return 
		left.get_numerator() * right.get_denominator() ==
		right.get_numerator() * left.get_denominator();
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	/*left.to_improper();
	right.to_improper();
	return left.get_denominator() != right.get_denominator() && left.get_numerator() != right.get_numerator();*/

	return !(left == right);
}
bool operator>(Fraction left, Fraction right)
{
	/*left.to_improper();
	right.to_improper();
	return left.get_denominator() > right.get_denominator() && left.get_numerator() > right.get_numerator();*/

	return
		left.get_numerator() * right.get_denominator() >
		right.get_numerator() * left.get_denominator();
}
bool operator<(Fraction left, Fraction right)
{
	return
		left.get_numerator() * right.get_denominator() <
		right.get_numerator() * left.get_denominator();
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	return !(left < right);
	//return left > right || left == right;
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	return !(left > right);
	//return left < right || left == right;
}
std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}
std::istream& operator>>(std::istream& in, Fraction& obj)
{
	int integer, numerator, denominator;

	in >> integer >> numerator >> denominator;
	if (in)
	{
		obj.set_integer(integer);
		obj.set_numerator(numerator);
		obj.set_denominator(denominator);
	}
	else
		cout << "На ввод ожидается 3 целых числа (1 - целая часть, 2 - числитель, 3 - знаменатель)!!!\nЗначения по умолчанию: ";
	return in;
}

//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define COMPARISON_OPERATORS_CHECK
#define STREAMS_CHECK

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

#ifdef ARITHMETICAL_OPERATORS_CHECK
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

	/*cout << "Инкремент для A постфиксный: ";
	A.print();
	A++;
	A.print();
	cout << "Инкремент для B префиксный: ";
	B.print();
	++B;
	B.print();*/

	A.print();
	B.print();
	A *= B;
	A.print();

	A /= B;
	A.print();
#endif //ARITHMETICAL_OPERATORS_CHECK

#ifdef COMPARISON_OPERATORS_CHECK
	/*cout << "Сравнение дробей A и B: " << (A == B) << endl;
	cout << "A не равно B: " << (A != B) << endl;

	cout << "A > B: " << (A > B) << endl;
	cout << "B > A: " << (B > A) << endl;

	cout << "A < B: " << (A < B) << endl;
	cout << "B < A: " << (B < A) << endl;

	cout << "A >= B: " << (A >= B) << endl;
	cout << "B >= A: " << (B >= A) << endl;

	cout << "A <= B: " << (A <= B) << endl;
	cout << "B <= A: " << (B <= A) << endl;*/

	cout << (Fraction(1, 2) >= Fraction(5, 10)) << endl;
#endif COMPARISON_OPERATORS_CHECK
#ifdef STREAMS_CHECK

	Fraction A(2, 3, 4);
	cout << "Введите простую дробь (1 - целая часть, 2 - числитель, 3 - знаменатель):\n"; cin >> A;
	cout << A << endl;

#endif // STREAMS_CHECK
}
