#include <iostream>


//Инкапсуляция, агрегация, композиция

//Формирование класса\\

class NameOfClass; // - объявление класса

class NameOfClass {
	//Внутренности фигурных скобок - тело класса.
	// тут хранятся свойства и поведения объектов

// хранящиеся здесь элементы доступны только членам класса, дружественным классам и функциям и членам классов наследников
protected:




//хранящиеся здесь элементы доступны только членам класса, дружественным классам и функциям 
private:
	int even_;

// хранящийся здесь элементы доступны всем клиентам класса.
// Наследникам класса, и клиентам наследника.
public:

	// обычно в этой зоне оставляют только методы класса

	NameOfClass() {
		SetEven(2);
		even_ = 2;
	}

	//конструктор применил делигацию работы для передачи прав на создание и заполнение своего поля
	// конструктору поля
	NameOfClass(int newNum): even_(newNum) {

		if (even_ % 2 == 1)
			throw 1;

	}
	//дилегация на поля применяется для возможности работы с универсальной инициализацией через {} и 
	// и является единственным способом заполнить поля которые являются ссылками и неинициализированными константами



	void SomeWork() {
		std::cout << "I'm alive!\n";
	}

	int GetEven() {
		return even_;
	}

	void SetEven(int newNum) {
		if (newNum % 2 == 0) {
			even_ = newNum;
		}
		else {
			throw 1;
		}
	}
};// - Определение класса. 


int main() {
	setlocale(0, "");
	int n;

	NameOfClass obj; // создали экземпляр класса с именем obj
	obj.SomeWork();
	obj.SetEven(8);
	std::cout << obj.GetEven() << std::endl;
	NameOfClass obj2{ 10 };
	std::cout << obj2.GetEven() << std::endl;
	obj2.SetEven(4);
	std::cout << obj2.GetEven() << std::endl;


	return 0;
}

class Day {
private:
	int units_;
public:
	Day() :units_(0) {}
	Day(int days) :units_(days) {
		if (units_ < 0)
			throw 1;
	}
	int Days() {
		return units_;
	}
	void Days(const Day& obj) {
		this->units_ = obj.units_;
	}
	void AddDays(const Day& obj) {
		this->units_ += obj.units_;
	}

};

class Month {
private:
	int units_;
public:

	Month():units_(0){}
	Month(int month) :units_(month) {
		if (units_ < 0)
			throw 1;
	}
	Month(Day days) {
		units_ = days.Days() / 30;
	}

	int Months() {
		return units_;
	}

	void Months(const Month& obj) {
		units_ = obj.units_;
	}

	void AddMonths(const Month& obj) {
		units_ += obj.units_;
	}

};

class Year {
private:
	int units_;
public:

	Year() :units_(0) {}
	Year(int Year) :units_(Year) {
		if (units_ < 0)
			throw 1;
	}
	Year(Day days) {
		units_ = days.Days() / 365;
	}
	Year(Month months) {
		units_ = months.Months() / 12;
	}

	int Years() {
		return units_;
	}

	void Years(const Year& obj) {
		units_ = obj.units_;
	}

	void AddYears(const Year& obj) {
		units_ += obj.units_;
	}

};

class Date {
private:
	Day day_;
	Month month_;
	Year year_;

public:
	//тут будут правила класса - даты


};//данный класс собирает внутри себя объекты других классов на правах
//	композиции


//Композиция - способ связи полей класса с его объектом при котором
// поле яляется неотъемлимой частью объекта без которого невозможна
// работа. При композиции объект в который сложены композиционные поля, 
// несет ответственность за время жизни этих полей.

// Агрегация - способ связи полей класса с его объектом при котором поле
// является легко заменяемой частью класса. отсутствие агрегационного 
// компонента не ведет к проблемам в жизненном цикле хранящего данное поле
// объекта.
// при агрегации хранящий объект не несет ответсвенности за время жизни
// хранимого на правах агрегации поля 
