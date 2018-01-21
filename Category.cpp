#include "stdafx.h"
#include "Category.h"

int Category::current_id = 0;

void Category::show_category()
{
	cout << "ID: " << id << endl;
	cout << "Name: " << name << endl;
	cout << endl;
}
