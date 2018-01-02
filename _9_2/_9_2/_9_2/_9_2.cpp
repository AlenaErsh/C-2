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
#include "Time.h"

using namespace std;


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

