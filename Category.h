#pragma once
#include <iostream>
#include <string>

using namespace std;

class Category
{
private:
	friend class System;
	static int current_id;
	int id;
	string name;
	Category(int id, string name) : id(id), name(name) {};
public:
	Category(string name) : id(current_id), name(name) { current_id++; };
	void show_category();
};

