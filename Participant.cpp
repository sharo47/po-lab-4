#include "stdafx.h"
#include "Participant.h"

int Participant::current_id = 0;

void Participant::show_participant()
{
	cout << "ID: " << id << endl;
	cout << "Name: " << name << " " << surname << endl;
	cout << "Sex: " << sex << endl;
	cout << "Birthdate: " << birthdate << endl;
	cout << "Category ID: " << cat_id << endl;
	cout << "Club ID: " << club_id << endl;
	cout << endl;
}
