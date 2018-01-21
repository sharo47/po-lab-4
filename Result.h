#pragma once
#include <iostream>
#include <string>

using namespace std;

class Result
{
private:
	friend class System;
	static int current_id;
	int id;
	int con_id;
	int part_id;
	int points;
	Result(int id, int con_id, int part_id, int points) : id(id), con_id(con_id), part_id(part_id), points(points) {};
public:
	Result(int con_id, int part_id, int points): id(current_id), con_id(con_id), part_id(part_id), points(points) { current_id++; };
	void show_result();
};

