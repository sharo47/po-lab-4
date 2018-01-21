#pragma once
#include <iostream>
#include <string>

using namespace std;

class Participant
{
private:
	friend class System;
	static int current_id;
	int id;
	string name;
	string surname;
	string sex;
	string birthdate;
	int cat_id;
	int club_id;
	string password;
	Participant(int id, string name, string surname, string sex, string birthdate, int cat_id, int club_id, string password) : id(id), name(name), surname(surname), sex(sex), birthdate(birthdate), cat_id(cat_id), club_id(club_id), password(password) {};
public:
	Participant(string name, string surname, string sex, string birthdate, int cat_id, int club_id, string password) : id(current_id), name(name), surname(surname), sex(sex), birthdate(birthdate), cat_id(cat_id), club_id(club_id), password(password) { current_id++; };
	void show_participant();
};

