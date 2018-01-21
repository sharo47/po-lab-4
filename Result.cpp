#include "stdafx.h"
#include "Result.h"


int Result::current_id = 0;

void Result::show_result()
{
	cout << "ID: " << id << endl;
	cout << "Contest ID:" << con_id << endl;
	cout << "Participant ID: " << part_id << endl;
	cout << "Points: " << points << endl;
	cout << endl;
}
