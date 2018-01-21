#pragma once
#include <iostream>
#include <string>
#include "Country.h"

using namespace std;

class City
{
private:
	friend class System;
//	friend class Country;
	friend class Club;
	static int current_id;
	int id;
	string c_name;
	string p_name;
	City(int id, string c_name, string p_name) : id(id), c_name(c_name), p_name(p_name) {};
public:
	City(string c_name, string p_name) : id(current_id), c_name(c_name), p_name(p_name) { current_id++; };
	void show_city();
};

