#include <iostream>

using namespace std;

class Car { //базовый класс - "Машина"
protected:
	string name; //марка машины
	unsigned int speed; //максимальная скорость машины
public:
	Car(string name, unsigned int speed) { //конструктор для инициализации полей
		this->name = name;
		this->speed = speed;
	}

	virtual void print() {
		cout << "name: " << name << endl << "max speed: " << speed << endl;
	}
};

class Bus : //производный класс - "Автобус"
	public Car {
protected:
	unsigned int passengers; //дополнительное поле - максимальное число пассажиров
public:
	Bus(string name, unsigned int speed, unsigned int passengers) : //конструктор
		Car(name, speed) { //явный вызов конструктора базового класса
		this->passengers = passengers;
	}
	void print() { //переопределенный метод print()
		Car::print();
		cout << "max amount of passengers of bus: " << passengers << endl; //допечатываем поле passengers
	}
};

int main() {
	Car car{ "mark 1", 200 };
	car.print();

	Bus bus{ "mark 2", 100, 50 };
	bus.print();

	return 0;
}