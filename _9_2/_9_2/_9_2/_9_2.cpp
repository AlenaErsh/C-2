// ConsoleApplication1.cpp: ���������� ����� ����� ��� ����������� ����������.
//
/*������� ����� Time ��� ������ �� �������� � ������� "����:������:�������".

����� ������ �������� � ���� �� ����� 4� ������� �������������:
�������, �������(�������� "23:59:59"), ���������, ��������.

������������� ���������� ��������:
����������� �������� ����� ����� ��������� ������� � ��������+
���������� �� ������� ��������� ���������� ������+
���������� �������� ������� +
�������� � �������+
�������� � ������(� ����������� �� ����� ������)+*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>

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
		min = (s - hour * 3600) / 60;
		sec = s - hour * 3600 - min * 60;
	}

	Time(const const char *str) {
		string a;
		int n = 0, time[3];
		for (int i = 0; i < (strlen(str) + 1); i++) {
			if (str[i] != ':') {
				a += str[i];
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

	/*���������� �������� ����� ����� ��������� � ��������*/
	int operator -(Time time2) {
		return ToSec() - time2.ToSec();
	}

	/*��������� �� ������� ��������� ���������� ������*/
	void operator -(int s) {
		Time interm(ToSec() - s);
		this->hour = interm.hour;
		this->min = interm.min;
		this->sec = interm.sec;
	}

	/*��������� ���� �������� ������� (�����?)*/
	bool operator ==(Time time2) {
		return (this->hour == time2.hour) && (this->min == time2.min) && (this->sec == time2.sec);
	}

	/*��������� ���� �������� ������� (�� �����?)*/
	bool operator !=(Time time2) {
		return !(this->hour == time2.hour) && (this->min == time2.min) && (this->sec == time2.sec);
	}

	/*��������� ���� �������� ������� (������?)*/
	bool operator <(Time time2) {
		if (this -> hour < time2.hour) return true;
		else if (this->hour > time2.hour) return false;

		if (this->min < time2.min) return true;
		else if (this->min > time2.min) return false;

		return (this->sec < time2.sec);
	}

	/*��������� ���� �������� ������� (������??)*/
	bool operator >(Time time2) {
		if (this->hour > time2.hour) return true;
		else if (this->hour < time2.hour) return false;

		if (this->min > time2.min) return true;
		else if (this->min < time2.min) return false;

		return (this->sec > time2.sec);
	}


	/*������� ����� � �������*/
	int ToSec()
	{
		return (hour * 3600 + min * 60 + sec);
	}

	/*������� ����� � ������*/
	int ToMin()
	{
		return (hour * 60 + min) + round(sec/60.0);
	}

	string ToString(int h, int m, int s) {
		ostringstream oss;
		oss << h << ":" << m << ":" << s << endl;
		return oss.str();
	}

	void Display() {
		cout << ToString(hour,min,sec);
	}

};

/*������� ����� �������*/
Time Init() {
	int answ;
	cout << "� ����� ���� �� ������ ������ �����?" << endl;
	cout << "1. �����" << endl;
	cout << "2. �������" << endl;
	cout << "3. ������ ������� '����:������:�������'" << endl;
	cin >> answ;
	switch (answ) {
	case 1: {
		int h, m, s;
		cout << "������� ��� ����� : ����, ������, ������� - ����� ������" << endl;
		cin >> h >> m >> s;
		Time Ob(h, m, s);
		return Ob;
		break;
	}
	case 2: {
		int s;
		cout << "������� ����� � ��������" << endl;
		cin >> s;
		Time Ob(s);
		return Ob;
		break;
	}
	case 3: {
		char str[80];
		cout << "������� ����� � ������� - ����:������:�������" << endl;
		cin >> str;
		Time Ob(str);
		return Ob;
		break;
	}
	default: {
		cout << "������. ������� ���������� ����� ������ ����." << endl;
		Init();
		break;
	}
	}
}

/*������� ������ �� ��������*/
void Task() {
	int answ;
	cout << "------------" << endl;
	cout << "����� �������� ������ ���������?" << endl;
	cout << "1. ��������� �������� ����� ����� ��������� � ��������" << endl;
	cout << "2. ��������� �� ������� ��������� ���������� ������" << endl;
	cout << "3. ��������� ���� �������� �������" << endl;
	cout << "4. ������� ������� � �������" << endl;
	cout << "5. ������� ������� � ������ (�������� �� �����)" << endl;
	cin >> answ;
	switch (answ) {
	case 1: {
		cout << "------------" << endl;
		cout << "������� ��� ������� �������:" << endl;
		Time Ob1 = Init();
		Time Ob2 = Init();
		cout << "�������� ����� ����� ��������� �������:" << endl;
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
		cout << "������� ����� :" << endl;
		Time Ob = Init();
		cout << "������� ���������� ������:" << endl;
		int n;
		cin >> n;
		Ob - n;
		cout << "������������ ����� ����� ���������:" << endl;
		Ob.Display();
		break;
	}
	case 3: {
		cout << "------------" << endl;
		cout << "������� ��� ������� �������:" << endl;
		Time Ob1 = Init();
		Time Ob2 = Init();
		if (Ob1 == Ob2) {
			cout << "������� ������� �����" << endl;
		}
		else {
			cout << "������� ������� �� �����" << endl;
			if (Ob1 < Ob2) {
				cout << "������ ����� ������ �������" << endl;
			}
			else {
				cout << "������ ����� ������ �������" << endl;
			}
		}
		break;
	}
	case 4: {
		cout << "------------" << endl;
		cout << "������� �����:" << endl;
		Time Ob = Init();
		cout << "����� � ��������:" << endl;
		cout << Ob.ToSec() << endl;
		break;
	}
	case 5: {
		cout << "------------" << endl;
		cout << "������� �����:" << endl;
		Time Ob = Init();
		cout << "����� � �������:" << endl;
		cout << Ob.ToMin() << endl;
		break;
	}
	default: {
		cout << "������. ������� ���������� ����� ������ ����." << endl;
		Task();
		break;
	}
	}
}

/*������� ����������� ��������*/
bool Answ() {
	int answ;
	cout << "------------" << endl;
	cout << "������ ���������� ��������?" << endl;
	cout<<"1. ��"<<endl;
	cout << "2. ���" << endl;
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
		cout << "������. ������� ���������� ����� ������ ����." << endl;
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

