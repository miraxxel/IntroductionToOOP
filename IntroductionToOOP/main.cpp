#include<iostream>
using namespace std;
using::std::cout;
using::std::endl;

#define delimiter "\n---------------------------------------------\n"

// Создавая структуру/класс, мы создаем новый тип данных
// Структуру/класс ещё называют пользовательскими данных
// Пользовательские типы данных хранят целые наборы значений, 
// в отличии от примитивных типов, которые могут хранить только одно значение из множества возможных
class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	// До этого момента переменные не инициализированны
	// С помощью set мы можем задать им значение
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y) 
	{
		this->y = y;
	}
	//			Constructors:
	Point()
	{
		x = y = 0;
		cout << "DefaultConstructor: \t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "SingleArgConstructor: \t" << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "(TwoArg)Constructor: \t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor: \t" << this << endl;
	}

	~Point()
	{
		cout << "Destructor: \t\t" << this << endl;
	}
	//			Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssigmment (копия присваивания?):\t\t" << this << endl;
		return *this;
	}

	Point& operator++() // Prefix increment
	{
		x++;
		y++;
		return *this; // разыменованный указатель на объект
	}
	Point operator++(int) // Postfix increment
	{
		// т.к. постфиксный инкремент выполняется самым последним, 
		// то мы сохраняем старое значение объекта
		Point old = *this;
		x++;
		y++;
		return old; // возвращаем старый объект
	}

	//			Methods:
	double distance(const Point& other) const
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		return sqrt(x_distance * x_distance + y_distance * y_distance);
	}
	void print()const
	{
		cout << this << ": X = " << x << " Y = " << y << endl;
	}
};

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	return sqrt(x_distance * x_distance + y_distance * y_distance);
}

Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}

Point operator-(const Point& left, const Point& right)
{
	Point result
	(
		left.get_x() - right.get_x(),
		left.get_y() - right.get_y()
	);
	return result;
}

Point operator*(const Point& left, const Point& right)
{
	return Point
	(
		left.get_x() * right.get_x(),
		left.get_y() * right.get_y()
	);
}

bool operator==(const Point& left, const Point& right)
{
	/*if (left.get_x() == right.get_x() && left.get_y() == right.get_y())
		return true;
	else 
		return false;*/
	return left.get_x() == right.get_x() && left.get_y() == right.get_y();
}

//#define STRUCT_POINT
//#define DISTANCE_CHECK
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMMENT_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef STRUCT_POINT
	cout << "Hello OOP" << endl;

	int a;		// объявление переменной 'a' типа 'int'
	Point A;	// объявление переменной 'A' типа 'Point'
				// создание объекта(экземпляра) 'A' структуры 'Point'
	cout << sizeof(A) << endl;

	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT
#ifdef DISTANCE_CHECK
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << "Координаты 1-ой точки: " << A.get_x() << " " << A.get_y() << endl;
	cout << "Расстояние до этой точки = " << A.distance(A) << endl;
	
	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << "Координаты 2-ой точки: " << B.get_x() << " " << B.get_y() << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки 'A' до точки 'B' = " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки 'B' до точки 'A' = " << B.distance(A) << endl;
	cout << delimiter << endl;
	
	cout << "Расстояние от точки 'A' до точки 'B' = " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки 'B' до точки 'A' = " << distance(B, A) << endl;
	cout << delimiter << endl;
#endif // DISTANCE_CHECK
#ifdef CONSTRUCTORS_CHECK
	Point A;	// Default constructor
	A.print();

	Point B = 5;
	B.print();

	Point C(2, 3);
	C.print();

	Point D = C; // Copy constructor
	D.print();
#endif // CONSTUCTORS_CHECK
#ifdef ASSIGNMMENT_CHECK
	/*Point A(2, 3);  // Constructor
	Point B;		// Default Constructor
	B = A;			// Copy Assignmment
	B.print();*/

	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point(2, 3);
	cout << delimiter << endl;
	A.print();
	B.print();
	C.print(); 
#endif // ASSIGNMMENT_CHECK
#ifdef ARITHMETICAL_OPERATORS_CHECK
	Point A(2, 3);
	Point B(7, 8);
	A.print();
	B.print();

	Point C = A * B;
	C.print();

	C++;
	C.print();
#endif // ARITHMETICAL_OPERATORS_CHECK

	//cout << (2 == 3) << endl;
	cout << (Point(2, 3) == Point(3, 3)) << endl;
}