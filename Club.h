#pragma once
#include <iostream>
#include <string>
#include "City.h"
using namespace std;

class Club
{
private:
	friend class System;
	friend class City;
	friend class Country;
	static int current_id;
	int id;
	Country *country;
	City *city;
	Club(int id, string c_name, string p_name) : id(id), city(new City(c_name, p_name))  {};
public:
	Club(string c_name, string p_name) : id(current_id), city(new City(c_name, p_name)) { current_id++; };
	void show_club();
};

