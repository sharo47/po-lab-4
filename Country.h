#pragma once
#include <iostream>
#include <string>

using namespace std;

class Country
{
private:
	friend class System;
	friend class City;
	friend class Club;
//	Country(string p_name) : p_name(p_name) {};
public:
	string p_name;
	Country(string p_name) : p_name(p_name) {};
	void show_country();
};
