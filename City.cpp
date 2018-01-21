#include "stdafx.h"
#include "City.h"

int City::current_id = 0;

void City::show_city()
{
	cout << "ID: " << id << endl;
	cout << "City: " << c_name << endl;
	cout << "Country: " << p_name << endl;
	cout << endl;
}
