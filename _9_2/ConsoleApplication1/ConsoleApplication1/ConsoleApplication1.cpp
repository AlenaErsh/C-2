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

	/*���������� �������� ����� ����� ��������� ������� � ��������*/
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

	/*��������� �� ������� ��������� ���������� ������*/
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

	/*��������� ���� �������� ������� (�����?)*/
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

	/*��������� ���� �������� ������� (�� �����?)*/
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

	/*��������� ���� �������� ������� (������?)*/
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

	/*��������� ���� �������� ������� (������??)*/
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


	/*������� ����� � �������*/
	int ToSec()
	{
		return (hour * 3600 + min * 60 + sec);
	}

	/*������� ����� � ������*/
	int ToMin()
	{
		return (hour * 60 + min);
	}

	void Display() {
		cout << hour << ":" << min << ":" << sec << endl;
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
	switch (answ){
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
		cout<<"������� ����� � ��������"<<endl;
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
		cout<<"������. ������� ���������� ����� ������ ����."<<endl;
		Init();
	}		
	}
}

/*������� ������ �� ��������*/
void Task() {
	int answ;
	cout << "����� �������� ������ ���������?" << endl;
	cout << "1. ��������� �������� ����� ����� ��������� � ��������" << endl;
	cout << "2. ��������� �� ������� ��������� ���������� ������" << endl;
	cout << "3. ��������� ���� �������� �������" << endl;
	cout << "4. ������� ������� � �������" << endl;
	cout << "5. ������� ������� � ������ (�������� �� �����)" << endl; 
	cin >> answ;
	switch (answ) {
	case 1: {
		cout << "������� ��� ������� �������:" << endl;
		Time Ob1 = Init();
		Time Ob2 = Init();
		Ob1 + Ob2;
		Ob1.Display();
		break;
	}
	case 2: {
		cout << "������� ����� :" << endl;
		Time Ob = Init();
		cout << "������� ���������� ������:" << endl;
		int n;
		cin >> n;
		Ob - n;
		Ob.Display();
		break;
	}
	case 3: {
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
		cout << "������� �����:" << endl;
		Time Ob = Init();
		cout << "����� � ��������:" << endl;
		cout<<Ob.ToSec()<<endl;
		break;
	}
	case 5: {
		cout << "������� �����:" << endl;
		Time Ob = Init();
		cout << "����� � �������:" << endl;
		cout << Ob.ToMin() << endl;
		break;
	}
	default: {
		cout << "������. ������� ���������� ����� ������ ����." << endl;
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

