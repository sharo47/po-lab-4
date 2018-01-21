#include "stdafx.h"
#include "Club.h"

int Club::current_id = 0;

void Club::show_club()
{
	cout << "ID: " << id << endl;
	city->show_city();
	cout << endl;
}
