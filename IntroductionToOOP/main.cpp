#include<iostream>
using namespace std;
using::std::cout;
using::std::endl;

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

	//			Methods:
	double distance(Point other) 
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		return sqrt(x_distance * x_distance + y_distance * y_distance);
	}

};

double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	return sqrt(x_distance * x_distance + y_distance * y_distance);
}

//#define STRUCT_POINT
#define DISTANCE_CHECK

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
	cout << "Расстояние от точки 'A' до точки 'B' = " << A.distance(B) << endl;
	cout << "Расстояние от точки 'B' до точки 'A' = " << B.distance(A) << endl;
	
	cout << "Расстояние от точки 'A' до точки 'B' = " << distance(A, B) << endl;
	cout << "Расстояние от точки 'B' до точки 'A' = " << distance(B, A) << endl;
#endif // DISTANCE_CHECK

}