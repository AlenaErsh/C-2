// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//
/*Создать класс Time для работы со временем в формате "часы:минуты:секунды".

Класс должен включать в себя не менее 4х функций инициализации:
числами, строкой(например "23:59:59"), секундами, временем.

Обязательными операциями являются:
—Вычисление разности между двумя моментами времени в секундах+
—Вычитание из времени заданного количества секунд+
—Сравнение моментов времени +
—Перевод в секунды+
—Перевод в минуты(с округлением до целой минуты)+*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include "Time.h"

using namespace std;


/*Функция ввода времени*/
Time Init() {
	int answ;
	cout << "В каком виде вы хотите ввести время?" << endl;
	cout << "1. Числа" << endl;
	cout << "2. Секунды" << endl;
	cout << "3. Строка формата 'часы:минуты:секунды'" << endl;
	cin >> answ;
	switch (answ) {
	case 1: {
		int h, m, s;
		cout << "Введите три числа : часы, минуты, секунды - через пробел" << endl;
		cin >> h >> m >> s;
		Time Ob(h, m, s);
		return Ob;
		break;
	}
	case 2: {
		int s;
		cout << "Введите время в секундах" << endl;
		cin >> s;
		Time Ob(s);
		return Ob;
		break; 
	}
	case 3: {
		char str[80];
		cout << "Введите время в формате - часы:минуты:секунды" << endl;
		cin >> str;
		Time Ob(str);
		return Ob;
		break;
	}
	default: {
		cout << "Ошибка. Введите корректный номер пункта меню." << endl;
		Init();
		break;
	}
	}
}

/*Функция работы со временем*/
void Task() {
	int answ;
	cout << "------------" << endl;
	cout << "Какое действие хотите выполнить?" << endl;
	cout << "1. Вычислить разность между двумя моментами в секундах" << endl;
	cout << "2. Вычитание из времени заданного количества секунд" << endl;
	cout << "3. Сравнение двух моментов времени" << endl;
	cout << "4. Перевод времени в секунды" << endl;
	cout << "5. Перевод времени в минуты (округляя до целых)" << endl;
	cin >> answ;
	switch (answ) {
	case 1: {
		cout << "------------" << endl;
		cout << "Введите два момента времени:" << endl;
		Time Ob1 = Init();
		Time Ob2 = Init();
		cout << "Разность между двумя моментами времени:" << endl;
		if (Ob1 > Ob2) {
			cout << Ob1 - Ob2 << endl;
		}
		else {
			if (Ob2 > Ob1) {
				cout << Ob2 - Ob1 << endl;
			}
			else {
				cout << "0" << endl;
			}
		}
		break;
	}
	case 2: {
		cout << "------------" << endl;
		cout << "Введите время :" << endl;
		Time Ob = Init();
		cout << "Введите количество секунд:" << endl;
		int n;
		cin >> n;
		Ob - n;
		cout << "Получившееся время после вычитания:" << endl;
		Ob.Display();
		break;
	}
	case 3: {
		cout << "------------" << endl;
		cout << "Введите два момента времени:" << endl;
		Time Ob1 = Init();
		Time Ob2 = Init();
		if (Ob1 == Ob2) {
			cout << "Моменты времени равны" << endl;
		}
		else {
			cout << "Моменты времени не равны" << endl;
			if (Ob1 < Ob2) {
				cout << "Первое время меньше второго" << endl;
			}
			else {
				cout << "Первое время больше второго" << endl;
			}
		}
		break;
	}
	case 4: {
		cout << "------------" << endl;
		cout << "Введите время:" << endl;
		Time Ob = Init();
		cout << "Время в секундах:" << endl;
		cout << Ob.ToSec() << endl;
		break;
	}
	case 5: {
		cout << "------------" << endl;
		cout << "Введите время:" << endl;
		Time Ob = Init();
		cout << "Время в минутах:" << endl;
		cout << Ob.ToMin() << endl;
		break;
	}
	default: {
		cout << "Ошибка. Введите корректный номер пункта меню." << endl;
		Task();
		break;
	}
	}
}

/*Функция продолжения действий*/
bool Answ() {
	int answ;
	cout << "------------" << endl;
	cout << "Хотите продолжить действия?" << endl;
	cout<<"1. Да"<<endl;
	cout << "2. Нет" << endl;
	cin >> answ;
	switch (answ)
	{
	case 1: {
		return true;
	}
	case 2: {
		return false;
	}
	default: {
		cout << "Ошибка. Введите корректный номер пункта меню." << endl;
		Answ();
		break;
	}
	}

}

void Repeat() {
	while (Answ()) {
		Task();
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Task();
	Repeat();
	system("pause");
	return 0;
}

