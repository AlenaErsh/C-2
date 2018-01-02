#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include "Time.h"


using namespace std;

Time::Time(int h, int m, int s)
{
	hour = h;
	min = m;
	sec = s;
}


Time::Time(int s) {
	hour = s / 3600;
	min = (s - hour * 3600) / 60;
	sec = s - hour * 3600 - min * 60;
}

Time::Time(const const char *str) {
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

Time::~Time() {

}

/*¬ычисление разности между двум€ моментами в секундах*/
int Time::operator -(Time time2) {
	return ToSec() - time2.ToSec();
}

/*¬ычитание из времени заданного количества секунд*/
void Time::operator -(int s) {
	Time interm(ToSec() - s);
	this->hour = interm.hour;
	this->min = interm.min;
	this->sec = interm.sec;
}

/*—равнение двух моментов времени (равны?)*/
bool Time::operator ==(Time time2) {
	return (this->hour == time2.hour) && (this->min == time2.min) && (this->sec == time2.sec);
}

/*—равнение двух моментов времени (не равны?)*/
bool Time::operator !=(Time time2) {
	return !(this->hour == time2.hour) && (this->min == time2.min) && (this->sec == time2.sec);
}

/*—равнение двух моментов времени (меньше?)*/
bool Time::operator <(Time time2) {
	if (this->hour < time2.hour) return true;
	else if (this->hour > time2.hour) return false;

	if (this->min < time2.min) return true;
	else if (this->min > time2.min) return false;

	return (this->sec < time2.sec);
}

/*—равнение двух моментов времени (больше??)*/
bool Time::operator >(Time time2) {
	if (this->hour > time2.hour) return true;
	else if (this->hour < time2.hour) return false;

	if (this->min > time2.min) return true;
	else if (this->min < time2.min) return false;

	return (this->sec > time2.sec);
}


/*ѕеревод числа в секунды*/
int Time::ToSec()
{
	return (hour * 3600 + min * 60 + sec);
}

/*ѕеревод числа в минуты*/
int Time::ToMin()
{
	return (hour * 60 + min) + round(sec / 60.0);
}

string Time::ToString(int h, int m, int s) {
	ostringstream oss;
	oss << h << ":" << m << ":" << s << endl;
	return oss.str();
}

void Time::Display() {
	cout << ToString(hour, min, sec);
}