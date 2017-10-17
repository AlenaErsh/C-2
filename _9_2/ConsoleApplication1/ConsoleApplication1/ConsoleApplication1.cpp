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

using namespace std;

class Time {

	int hour, min, sec;

public:

	Time(int h, int m, int s) {
		hour = h;
		min = m;
		sec = s;
	}

	Time(int s) {
		hour = s / 3600;
		min = (s - hour*3600) / 60;
		sec = s - hour * 3600 - min * 60;
	}

	Time(const const char *str) {
		string a;
		int n=0, time[3];
		for (int i = 0; i < (strlen(str)+1); i++) {
			if (str[i] != ':') {
				a+=str[i];
			}
			else {
				time[n] = atoi(a.c_str());
				n++;
				a = "";
			}

		}
		hour = time[0];
		min = time[1];
		sec = time[2];
	}

	/*Вычисление разности между двумя моментами времени в секундах*/
	void operator +(Time obj) {
		this->sec += obj.sec;
		if (this->sec >= 60) {
			this->min++;
			this->sec -= 60;
		}
		this->min += this->min + obj.min;
		if (this->min >= 60) {
			this->hour++;
			this->min -= 60;
		}
		this->hour += this->hour + obj.hour;
	}

	/*Вычитание из времени заданного количества секунд*/
	void operator -(int s) {
		this->sec -= s;
		while (this->sec < 0){
			this->min--; 
			this->sec += 60;
		}

		while (this->min < 0){
			this->hour--; 
			this->min += 60;
		}

		while (this->hour < 0) {
			this->hour++;
		}
	}

	/*Сравнение двух моментов времени (равны?)*/
	bool operator ==(Time obj){
		if (this->hour == obj.hour){
			if (this->min == obj.min){
				if (this->sec == obj.sec)
					return true;
				else
					return false;
			}
			else return false;
		}
		else return false;
	}

	/*Сравнение двух моментов времени (не равны?)*/
	bool operator !=(Time obj){
		if (this->hour == obj.hour){
			if (this->min == obj.min){
				if (this->sec == obj.sec)
					return false;
				else
					return true;
			}
			else return true;
		}
		else return true;
	}

	/*Сравнение двух моментов времени (меньше?)*/
	bool operator <(Time obj) {
		if (this->hour== obj.hour) {
			if (this->min == obj.min) {
				if (this->sec == obj.sec) {
					return false;
				}
				else {
					if (this->sec > obj.sec) {
						return false;
					}
					return true;
				}
			}
			else {
				if (this->min > obj.min) {
					return false;
				}
				return true;
			}
		}
		else {
			if (this->hour > obj.hour) {
				return false;
			}
			return true;
		}
	}

	/*Сравнение двух моментов времени (больше??)*/
	bool operator >(Time obj) {
		if (this->hour == obj.hour) {
			if (this->min == obj.min) {
				if (this->sec == obj.sec) {
					return false;
				}
				else {
					if (this->sec < obj.sec) {
						return false;
					}
					return true;
				}
			}
			else {
				if (this->min < obj.min) {
					return false;
				}
				return true;
			}
		}
		else {
			if (this->hour < obj.hour) {
				return false;
			}
			return true;
		}
	}


	/*Перевод числа в секунды*/
	int ToSec()
	{
		return (hour * 3600 + min * 60 + sec);
	}

	/*Перевод числа в минуты*/
	int ToMin()
	{
		return (hour * 60 + min);
	}

	void Display() {
		cout << hour << ":" << min << ":" << sec << endl;
	}

};

/*Функция ввода времени*/
Time Init() {
	int answ;
	cout << "В каком виде вы хотите ввести время?" << endl;
	cout << "1. Числа" << endl;
	cout << "2. Секунды" << endl;
	cout << "3. Строка формата 'часы:минуты:секунды'" << endl;
	cin >> answ;
	switch (answ){
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
		cout<<"Введите время в секундах"<<endl;
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
		cout<<"Ошибка. Введите корректный номер пункта меню."<<endl;
		Init();
	}		
	}
}

/*Функция работы со временем*/
void Task() {
	int answ;
	cout << "Какое действие хотите выполнить?" << endl;
	cout << "1. Вычислить разность между двумя моментами в секундах" << endl;
	cout << "2. Вычитание из времени заданного количества секунд" << endl;
	cout << "3. Сравнение двух моментов времени" << endl;
	cout << "4. Перевод времени в секунды" << endl;
	cout << "5. Перевод времени в минуты (округляя до целых)" << endl; 
	cin >> answ;
	switch (answ) {
	case 1: {
		cout << "Введите два момента времени:" << endl;
		Time Ob1 = Init();
		Time Ob2 = Init();
		Ob1 + Ob2;
		Ob1.Display();
		break;
	}
	case 2: {
		cout << "Введите время :" << endl;
		Time Ob = Init();
		cout << "Введите количество секунд:" << endl;
		int n;
		cin >> n;
		Ob - n;
		Ob.Display();
		break;
	}
	case 3: {
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
		cout << "Введите время:" << endl;
		Time Ob = Init();
		cout << "Время в секундах:" << endl;
		cout<<Ob.ToSec()<<endl;
		break;
	}
	case 5: {
		cout << "Введите время:" << endl;
		Time Ob = Init();
		cout << "Время в минутах:" << endl;
		cout << Ob.ToMin() << endl;
		break;
	}
	default: {
		cout << "Ошибка. Введите корректный номер пункта меню." << endl;
		Task();
	}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Task();
	system("pause");
    return 0;
}

