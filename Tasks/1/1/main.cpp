/*
1.	Создать класс «Дата» (число, месяц, год).
Должны быть реализованы  различные типы конструкторов (без параметров, с параметрами, конструктор копирования),
методы для работы с датой.
*/

#include <iostream>

using namespace std;

class Date {
private:
	int day;
	int month;
	int year;
public:
	Date() {
		day = 1;
		month = 1;
		year = 2023;
	}

	Date(int day, int month, int year) {
		this->day = day;
		this->month = month;
		this->year = year;
	}

	Date(const Date &option) {
		this->day = option.day;
		this->month = option.month;
		this->year = option.year;
	}

	int GetDay() {
		return day;
	}

	int GetMonth() {
		return month;
	}

	int GetYear() {
		return year;
	}
};

int main(void) {
	
	Date d(2, 9, 2023);
	cout << d.GetDay() << "." << d.GetMonth() << "." << d.GetYear() << endl;

	return 0;
}
