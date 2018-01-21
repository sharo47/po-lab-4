#include "stdafx.h"
#include "Contest.h"


int Contest::current_id = 0;

void Contest::show_contest()
{
	cout << "ID: " << id << endl;
	cout << "Name: " << name << endl;
	cout << "Date: " << day << "/" << month << "/" << year << endl;
	cout << endl;
}
