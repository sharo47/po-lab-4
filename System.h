#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <cstdio>
#include <fstream>
#include <iterator>
#include <ctime>
#include <algorithm>
#include "Admin.h"
#include "Category.h"
#include "Club.h"
#include "Contest.h"
#include "City.h"
#include "Participant.h"
#include "Result.h"

using namespace std;

class System
{
private:
	vector <Participant*> participants;
	vector <Result*> results;
	vector <Contest*> contests;
	vector <Category*> categories;
	vector <Club*> clubs;

	void load_data();
	void save_data();
	void load_participants();
	void save_participants();
	void load_results();
	void save_results();
	void load_contests();
	void save_contests();
	void load_categories();
	void save_categories();
	void load_clubs();
	void save_clubs();

	Participant* find_participant(int id);
	vector<Participant*> find_participant(string name, string surname);
	Participant* find_participant(int id, vector<Participant*> fltered_participants);
	Result* find_result(int id);
	vector<Result*> find_result(Contest* contest, Participant* participant);
	Result* find_result(int id, vector<Result*> filtered_results);
	Contest* find_contest(int id);
	vector<Contest*> find_contest(string name, int day, int month, int year);
	Contest* find_contest(int id, vector<Contest*> filtered_contests);
	Category* find_category(int id);
	vector<Category*> find_category(string name);
	Category* find_category(int id, vector<Category*> filtered_categories);
	Club* find_club(int id);
	vector<Club*> find_club(string c_name);
	Club* find_club(int id, vector<Club*> filtered_clubs);

	Participant* search_participant();
	Result* search_result();
	Result* search_result_for_participant(int id);
	Contest* search_contest();
	Category* search_category();
	Club* search_club();

	void admin_menu();
	void participant_menu(int id);
	void p_menu();
	void r_menu();
	void c_menu();
	void cat_menu();
	void club_menu();
	bool login();
	bool login(Participant* participant);

	void add_participant();
	void add_result();
	void add_contest();
	void add_category();
	void add_club();

	void edit_participant(Participant* participant);
	void edit_result(Result* result);
	void edit_contest(Contest* contest);
	void edit_category(Category* category);
	void edit_club(Club* club);

	void delete_participant(Participant* participant);
	void delete_result(Result* result);
	void delete_contest(Contest* contest);
	void delete_category(Category* category);
	void delete_club(Club* club);

	void show_participant(Participant* participant);
	void show_participants();
	void show_result(Result* result);
	void show_results();
	void show_contest(Contest* contest);
	void show_contests();
	void show_category(Category* category);
	void show_categories();
	void show_club(Club* club);
	void show_clubs();

//	void statistic(Result* result);

public:
	System() {};
	void menu();
};

