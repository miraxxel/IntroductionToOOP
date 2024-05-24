#include<iostream>
using namespace std;

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

	double distance(const Point)const 
	{
		return sqrt(x * x + y * y);
	}
};

//#define STRUCT_POINT

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

	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << "Координаты 1-ой точки: " << A.get_x() << " " << A.get_y() << endl;
	cout << "Расстояние до этой точки = " << A.distance(A) << endl;
}