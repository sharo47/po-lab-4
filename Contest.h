#pragma once
#include <iostream>
#include <string>
using namespace std;

class Contest
{
private:
	friend class System;
	static int current_id;
	int id;
	string name;
	int day;
	int month;
	int year;
	Contest(int id, string name, int day, int month, int year) : id(id), name(name), day(day), month(month), year(year) {};
public:
	Contest(string name, int day, int month, int year) : id(current_id), name(name), day(day), month(month), year(year) {current_id++;};
	void show_contest();
};

