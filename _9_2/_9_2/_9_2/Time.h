#pragma once

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Time
{	
private:
	int hour; 
	int min;
	int sec;

public:
	Time(int h, int m, int s);
	Time(int s);
	Time(const const char *str);
	~Time();

	int operator -(Time time2);
	void operator -(int s); 
	bool operator ==(Time time2);
	bool operator !=(Time time2);
	bool operator <(Time time2);
	bool operator >(Time time2);

	int ToSec();
	int ToMin();
	string ToString(int h, int m, int s);
	void Display();
};

