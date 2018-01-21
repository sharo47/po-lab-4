#include "stdafx.h"
#include "System.h"


vector<string> split_string(string line, char c)
{
	vector<string> split_line;
	int beg = 0, end;
	do {
		end = line.find(c, beg);
		if (end == string::npos) {
			end = line.length();
		}
		if (line.substr(beg, end - beg).length() != 0) {
			split_line.push_back(line.substr(beg, end - beg));
		}
		beg = end + 1;
	} while (end != line.size());
	return split_line;
}

void System::load_data()
{
	cout << "Loading data..." << endl;
	load_participants();
	load_results();
	load_contests();
	load_categories();
	load_clubs();
	cout << "Done." << endl;
	system("cls");
}

void System::load_participants()
{
	fstream file;
	file.open("./data/participants.txt", ios::in);
	if (file.good() == false)
	{
		cout << "Participant file error." << endl;
	}
	else
	{
		string line;
		getline(file, line);
		if (line.length()>0)
			Participant::current_id = stoi(line);
		while (getline(file, line))
		{
			vector<string> split_line = split_string(line, ':');
			Participant* participant = new Participant(stoi(split_line[0]), split_line[1], split_line[2], split_line[3], split_line[4], stoi(split_line[5]), stoi(split_line[6]), split_line[7]);
			participants.push_back(participant);
		}
	}
	file.close();
	file.clear();
}

void System::load_results()
{
	fstream file;
	file.open("./data/results.txt", ios::in);
	if (file.good() == false)
	{
		cout << "Results file error." << endl;
	}
	else
	{
		string line;
		getline(file, line); 
		if (line.length()>0)
			Result::current_id = stoi(line);
		while (getline(file, line))
		{
			vector<string> split_line = split_string(line, ':');
			Result* result = new Result(stoi(split_line[0]), stoi(split_line[1]), stoi(split_line[2]), stoi(split_line[3]));
			results.push_back(result);
		}
	}
	file.close();
	file.clear();
}

void System::load_contests()
{
	fstream file;
	file.open("./data/contests.txt", ios::in);
	if (file.good() == false)
	{
		cout << "Contest file error." << endl;
	}
	else
	{
		string line;
		getline(file, line); 
		if (line.length()>0)
			Contest::current_id = stoi(line);
		while (getline(file, line))
		{
			vector<string> split_line = split_string(line, ':');
			Contest* contest = new Contest(stoi(split_line[0]), split_line[1], stoi(split_line[2]), stoi(split_line[3]), stoi(split_line[4]));
			contests.push_back(contest);
		}
	}
	file.close();
	file.clear();
}

void System::load_categories()
{
	fstream file;
	file.open("./data/categories.txt", ios::in);
	if (file.good() == false)
	{
		cout << "Category file error." << endl;
	}
	else
	{
		string line;
		getline(file, line); 
		if (line.length()>0)
			Category::current_id = stoi(line);
		while (getline(file, line))
		{
			vector<string> split_line = split_string(line, ':');
			Category* category = new Category(stoi(split_line[0]), split_line[1]);
			categories.push_back(category);
		}
	}
	file.close();
	file.clear();
}

void System::load_clubs()
{
	fstream file;
	file.open("./data/clubs.txt", ios::in);
	if (file.good() == false)
	{
		cout << "Club file error." << endl;
	}
	else
	{
		string line;
		getline(file, line);
		if (line.length()>0)
			Club::current_id = stoi(line);
		while (getline(file, line))
		{
			vector<string> split_line = split_string(line, ':');
			Club* club = new Club(stoi(split_line[0]), split_line[1], split_line[2]);
			clubs.push_back(club);
		}
	}
	file.close();
	file.clear();
}

void System::save_data()
{
	cout << "Saving data..." << endl;
	save_participants();
	save_results();
	save_contests();
	save_categories();
	save_clubs();
	cout << "Done." << endl;
	_getch();
}

void System::save_participants()
{
	fstream file;
	file.open("./data/participants.txt", ios::out);
	file << Participant::current_id << "\n";
	for (int i = 0; i < participants.size(); i++)
	{
		file << participants[i]->id << ":" << participants[i]->name << ":" << participants[i]->surname << ":" << participants[i]->sex << ":" << participants[i]->birthdate << ":" << participants[i]->cat_id << ":" << participants[i]->club_id  << "\n";
	}
	file.close();
	file.clear();
}

void System::save_results()
{
	fstream file;
	file.open("./data/results.txt", ios::out);
	file << Result::current_id << "\n";
	for (int i = 0; i < results.size(); i++)
	{
		file << results[i]->id << ":" << results[i]->con_id << ":" << results[i]->part_id << ":" << results[i]->points << "\n";
	}
	file.close();
	file.clear();
}

void System::save_contests()
{
	fstream file;
	file.open("./data/contests.txt", ios::out);
	file << Contest::current_id << "\n";
	for (int i = 0; i < contests.size(); i++)
	file << contests[i]->id << ":" << contests[i]->name << ":" << contests[i]->day << "/" << contests[i]->month << "/" << contests[i]->year << "\n";
	file.close();
	file.clear();
}

void System::save_categories()
{
	fstream file;
	file.open("./data/categories.txt", ios::out);
	file << Category::current_id << "\n";
	for (int i = 0; i < categories.size(); i++)
	{
		file << categories[i]->id << ":" << categories[i]->name << "\n";
	}
	file.close();
	file.clear();
}

void System::save_clubs()
{
	fstream file;
	file.open("./data/clubs.txt", ios::out);
	file << Club::current_id << "\n";
	for (int i = 0; i < clubs.size(); i++)
	{
		file << clubs[i]->id << ":" << clubs[i]->city << ":" << clubs[i]->country << "\n";
	}
	file.close();
	file.clear();
}

Participant * System::find_participant(int id)
{
	for (int i = 0; i < participants.size(); i++)
	{
		if (id == participants[i]->id)
		{
			return participants[i];
		}
	}
	return nullptr;
}

vector<Participant*> System::find_participant(string name, string surname)
{
	vector<Participant*> found_participants;
	for (int i = 0; i < participants.size(); i++)
	{
		if (name.compare(participants[i]->name) == 0 && surname.compare(participants[i]->surname) == 0)
		{
			found_participants.push_back(participants[i]);
		}
	}
	return found_participants;
}

Participant* System::find_participant(int id, vector<Participant*> filtered_participants)
{
	for (int i = 0; i < filtered_participants.size(); i++)
	{
		if (id == filtered_participants[i]->id)
		{
			return filtered_participants[i];
		}
	}
	return nullptr;
}

Result * System::find_result(int id)
{
	for (int i = 0; i < results.size(); i++)
	{
		if (id == results[i]->id)
		{
			return results[i];
		}
	}
	return nullptr;
}

vector<Result*> System::find_result(Contest* contest, Participant* participant)
{
	vector<Result*> found_results;
	for (int i = 0; i < results.size(); i++)
	{
		if (contest->id == results[i]->con_id && participant->id == results[i]->part_id)
		{
			found_results.push_back(results[i]);
		}
	}
	return found_results;
}

Result* System::find_result(int id, vector<Result*> filtered_results)
{
	for (int i = 0; i < filtered_results.size(); i++)
	{
		if (id == filtered_results[i]->id)
		{
			return filtered_results[i];
		}
	}
	return nullptr;
}

Contest * System::find_contest(int id)
{
	for (int i = 0; i < contests.size(); i++)
	{
		if (id == contests[i]->id)
		{
			return contests[i];
		}
	}
	return nullptr;
}

vector<Contest*> System::find_contest(string name, int day, int month, int year)
{
	vector<Contest*> found_contests;
	for (int i = 0; i < contests.size(); i++)
	{
		if (name.compare(contests[i]->name) == 0 && day == contests[i]->day && month == contests[i]->month & year == contests[i]->year)
		{
			found_contests.push_back(contests[i]);
		}
	}
	return found_contests;
}

Contest* System::find_contest(int id, vector<Contest*> filtered_contests)
{
	for (int i = 0; i < filtered_contests.size(); i++)
	{
		if (id == filtered_contests[i]->id)
		{
			return filtered_contests[i];
		}
	}
	return nullptr;
}

Category * System::find_category(int id)
{
	for (int i = 0; i < categories.size(); i++)
	{
		if (id == categories[i]->id)
		{
			return categories[i];
		}
	}
	return nullptr;
}

vector<Category*> System::find_category(string name)
{
	vector<Category*> found_categories;
	for (int i = 0; i < categories.size(); i++)
	{
		if (name.compare(categories[i]->name) == 0)
		{
			found_categories.push_back(categories[i]);
		}
	}
	return found_categories;
}

Category* System::find_category(int id, vector<Category*> filtered_categories)
{
	for (int i = 0; i < filtered_categories.size(); i++)
	{
		if (id == filtered_categories[i]->id)
		{
			return filtered_categories[i];
		}
	}
	return nullptr;
}

Club* System::find_club(int id)
{
	for (int i = 0; i < clubs.size(); i++)
	{
		if (id == clubs[i]->id)
		{
			return clubs[i];
		}
	}
	return nullptr;
}

vector<Club*> System::find_club(string c_name)
{
	vector<Club*> found_clubs;
	for (int i = 0; i < clubs.size(); i++)
	{
		if (c_name.compare(clubs[i]->city->c_name) == 0)
		{
			found_clubs.push_back(clubs[i]);
		}
	}
	return found_clubs;
}

Club* System::find_club(int id, vector<Club*> filtered_clubs)
{
	for (int i = 0; i < filtered_clubs.size(); i++)
	{
		if (id == filtered_clubs[i]->id)
		{
			return filtered_clubs[i];
		}
	}
	return nullptr;
}

Participant * System::search_participant()
{
	char key;
	do
	{
		cout << "Search participant" << endl;
		cout << "1 -by ID" << endl;
		cout << "2 - by name" << endl;
		key = _getch();
		switch (key)
		{
		case '1':
		{
			system("cls");
			int id;
			cout << "Searching by ID" << endl;
			cout << "ID: ";
			cin >> id;
			getchar();
			Participant* participant = find_participant(id);
			if (participant == nullptr)
			{
				cout << endl << "Doesn't exist." << endl;
			}
			else
			{
				cout << "Found!" << endl;
			}
			_getch();
			return participant;
		}
		case '2':
		{
			system("cls");
			string name;
			string surname;
			cout << "Searching by name" << endl;
			cout << "Nme: ";
			getline(cin, name);
			cout << "Surname: ";
			getline(cin, surname);

			vector<Participant*> found_participants = find_participant(name, surname);
			switch (found_participants.size())
			{
			case 0:
				cout << "Doesn't exist!" << endl;
				_getch();
				return nullptr;
			case 1:
				cout << "Found!" << endl;
				_getch();
				return found_participants[0];
			default:
				int id;
				cout << "Multiple results. Please provide the corresponding ID." << endl;
				cin >> id;
				getchar();
				Participant* participant = find_participant(id, found_participants);
				if (participant == nullptr)
				{
					cout << "Doesn't exist!" << endl;
				}
				else
				{
					cout << "Found!" << endl;
				}
				_getch();
				return participant;
			}
		}
		}
		system("cls");
	} while (key != '1' && key != '2');
}

Result * System::search_result()
{
	char key;
	do
	{
		cout << "Search result" << endl;
		cout << "1 - By ID" << endl;
		cout << "2 - By Contest and Participant" << endl;
		key = _getch();
		switch (key)
		{
		case '1':
		{
			system("cls");
			int id;
			cout << "Searching by ID" << endl;
			cout << "Enter id of the results: ";
			cin >> id;
			getchar();
			Result* result = find_result(id);
			if (result == nullptr)
			{
				cout << "Doesn't exist!" << endl;
			}
			else
			{
				cout << "Found!" << endl;
			}
			_getch();
			return result;
		}
		case '2':
		{
			system("cls");
			cout << "Searching by contest" << endl;
			Contest* contest = search_contest();
			if (contest != nullptr) {
				system("cls");
				cout << "Searching by participant" << endl;
				Participant* participant = search_participant();
				if (participant != nullptr) {
					vector<Result*> found_results = find_result(contest, participant);
					switch (found_results.size())
					{
					case 0:
						cout << "Doesn't exist!";
						cout << "Participant " << participant->id << " didn't take part!" << endl;
						_getch();
						return nullptr;
					case 1:
						cout << "Found!" << endl;
						_getch();
						return found_results[0];
					default:
						int id;
						cout << "Found multiple results! Please provide the corresponding ID." << endl;
						cin >> id;
						getchar();
						Result* result = find_result(id, found_results);
						if (result == nullptr)
						{
							cout << "Doesn't exist!" << endl;
						}
						else
						{
							cout << "Found!" << endl;
						}
						_getch();
						return result;
					}
				}
			}
			_getch();
			return nullptr;
		}
		}
		system("cls");
	} while (key != '1' && key != '2');
}

Result * System::search_result_for_participant(int id)
{
	int p_id = id;
		Contest* contest = search_contest();
		if (contest != nullptr) {
			Participant* participant = find_participant(p_id);
				if (participant != nullptr) {
					vector<Result*> found_results = find_result(contest, participant);
					switch (found_results.size())
					{
					case 0:
						cout << "Doesn't exist!";
						_getch();
						return nullptr;
					case 1:
						cout << "Found!" << endl;
						_getch();
						return found_results[0];
					}
				}
			}
			_getch();
			return nullptr;
}

Contest * System::search_contest()
{
	char key;
	do
	{
		cout << "Search contest" << endl;
		cout << "1 - by ID" << endl;
		cout << "2 - by name" << endl;
		cout << "3 - by date" << endl;
		key = _getch();
		switch (key)
		{
		case '1':
		{
			system("cls");
			int id;
			cout << "Searching by ID" << endl;
			cout << "ID: ";
			cin >> id;
			getchar();
			Contest* contest = find_contest(id);
			if (contest == nullptr)
			{
				cout << endl << "Doesn't exist." << endl;
			}
			else
			{
				cout << "Found!" << endl;
			}
			_getch();
			return contest;
		}
		case '2':
		{
			system("cls");
			string name;
			int day, month, year;
			cout << "Searching by name and date" << endl;
			cout << "Name: ";
			getline(cin, name);
			cout << "Day: ";
			cin >> day;
			cout << "Month: ";
			cin >> month;
			cout << "Year: ";
			cin >> year;
			vector<Contest*> found_contests = find_contest(name, day, month, year);
			switch (found_contests.size())
			{
			case 0:
				cout << "Doesn't exist!" << endl;
				_getch();
				return nullptr;
			case 1:
				cout << "Found!" << endl;
				_getch();
				return found_contests[0];
			default:
				int id;
				cout << "Multiple results. Please provide the corresponding ID." << endl;
				cin >> id;
				getchar();
				Contest* contest = find_contest(id, found_contests);
				if (contest == nullptr)
				{
					cout << "Doesn't exist!" << endl;
				}
				else
				{
					cout << "Found!" << endl;
				}
				_getch();
				return contest;
			}
		}
		}
		system("cls");
	} while (key != '1' && key != '2');
}

Category * System::search_category()
{
	char key;
	do
	{
		cout << "Search category" << endl;
		cout << "1 - by ID" << endl;
		cout << "2 - by name" << endl;
		key = _getch();
		switch (key)
		{
		case '1':
		{
			system("cls");
			int id;
			cout << "Searching by ID" << endl;
			cout << "ID: ";
			cin >> id;
			getchar();
			Category* category = find_category(id);
			if (category == nullptr)
			{
				cout << endl << "Doesn't exist." << endl;
			}
			else
			{
				cout << "Found!" << endl;
			}
			_getch();
			return category;
		}
		case '2':
		{
			system("cls");
			string name;
			cout << "Searching by name" << endl;
			cout << "Name: ";
			getline(cin, name);

			vector<Category*> found_categories = find_category(name);
			switch (found_categories.size())
			{
			case 0:
				cout << "Doesn't exist!" << endl;
				_getch();
				return nullptr;
			case 1:
				cout << "Found!" << endl;
				_getch();
				return found_categories[0];
			default:
				int id;
				cout << "Multiple results. Please provide the corresponding ID." << endl;
				cin >> id;
				getchar();
				Category* category = find_category(id, found_categories);
				if (category == nullptr)
				{
					cout << "Doesn't exist!" << endl;
				}
				else
				{
					cout << "Found!" << endl;
				}
				_getch();
				return category;
			}
		}
		}
		system("cls");
	} while (key != '1' && key != '2');
}

Club * System::search_club()
{
	char key;
	do
	{
		cout << "Search club" << endl;
		cout << "1 - by ID" << endl;
		cout << "2 - by city" << endl;
		key = _getch();
		switch (key)
		{
		case '1':
		{
			system("cls");
			int id;
			cout << "Searching by ID" << endl;
			cout << "ID: ";
			cin >> id;
			getchar();
			Club* club = find_club(id);
			if (club == nullptr)
			{
				cout << endl << "Doesn't exist." << endl;
			}
			else
			{
				cout << "Found!" << endl;
			}
			_getch();
			return club;
		}
		case '2':
		{
			system("cls");
			City* city;
			string c_name;
			cout << "Searching by city" << endl;
			cout << "City: ";
			cin >> c_name;
			
			vector<Club*> found_clubs = find_club(c_name);
			switch (found_clubs.size())
			{
			case 0:
				cout << "Doesn't exist!" << endl;
				_getch();
				return nullptr;
			case 1:
				cout << "Found!" << endl;
				_getch();
				return found_clubs[0];
			default:
				int id;
				cout << "Multiple results. Please provide the corresponding ID." << endl;
				cin >> id;
				getchar();
				Club* club = find_club(id, found_clubs);
				if (club == nullptr)
				{
					cout << "Doesn't exist!" << endl;
				}
				else
				{
					cout << "Found!" << endl;
				}
				_getch();
				return club;
			}
		}
		}
		system("cls");
	} while (key != '1' && key != '2');
}

void System::admin_menu()
{
	char key;
	do
	{
		cout << "Admin" << endl << endl;
		cout << "1 - Participants" << endl;
		cout << "2 - Results" << endl;
		cout << "3 - Contests" << endl;
		cout << "4 - Categories" << endl;
		cout << "5 - Clubs" << endl;
		cout << "\n\nPress ESC to quit.";
		key = _getch();
		switch (key)
		{
		case '1':
			system("cls");
			p_menu();
			break;
		case '2':
			system("cls");
			r_menu();
			break;
		case '3':
			system("cls");
			c_menu();
			break;
		case '4':
			system("cls");
			cat_menu();
			break;
		case '5':
			system("cls");
			club_menu();
			break;
		}
		system("cls");
	} while (key != '1' && key != '2' && key != '3' && key != '4' && key != '5');
}

void System::participant_menu(int id)
{
	Participant* participant;
	find_participant(id);
	char key;
	do
	{
		cout << "Participant" << " " << id << endl << endl;
		cout << "1 - Views results" << endl;
		cout << "2 - View own profile" << endl;
		cout << "\n\nPress ESC to quit.";
		key = _getch();
		switch (key) {
		case 1:
			system("cls");
			search_result_for_participant(id);
			break;
		case 2:
			system("cls");
			show_participant(find_participant(id));
			break;
		}
		system("cls");
	} while (key != '1' && key != '2');

}

void System::p_menu()
{
	char key;
	do
	{
		cout << "Participant menu" << endl << endl;
		cout << "1 - Add participant" << endl;
		cout << "2 - Edit participant" << endl;
		cout << "3 - Delete participant" << endl;
		cout << "4 - Show participant" << endl;
		cout << "5 - Show all participants" << endl;
		cout << "\n\nPress ESC to quit.";
		key = _getch();
		switch (key)
		{
		case '1':
			system("cls");
			add_participant();
			break;
		case '2':
			system("cls");
			edit_participant(search_participant());
			break;
		case '3':
			system("cls");
			delete_participant(search_participant());
			break;
		case '4':
			system("cls");
			show_participant(search_participant());
			break;
		case '5':
			system("cls");
			show_participants();
			break;
		}
		system("cls");
	} while (key != '1' && key != '2' && key != '3' && key != '4' && key != '5');
}

void System::r_menu()
{
	char key;
	do
	{
		cout << "Results menu" << endl << endl;
		cout << "1 - Add result" << endl;
		cout << "2 - Edit result" << endl;
		cout << "3 - Delete result" << endl;
		cout << "4 - Show result" << endl;
		cout << "5 - Show all results" << endl;
		cout << "6 - Calculate sum (?)" << endl;
		cout << "\n\nPress ESC to quit.";
		key = _getch();
		switch (key)
		{
		case '1':
			system("cls");
			add_result();
			break;
		case '2':
			system("cls");
			edit_result(search_result());
			break;
		case '3':
			system("cls");
			delete_result(search_result());
			break;
		case '4':
			system("cls");
			show_result(search_result());
			break;
		case '5':
			system("cls");
			show_results();
			break;
		case '6':
			system("cls");
//			statistic(search_result());
			break;
		}
		system("cls");
	} while (key != '1' && key != '2' && key != '3' && key != '4' && key != '5'  && key!='6');
}

void System::c_menu()
{
	char key;
	do
	{
		cout << "Contest menu" << endl << endl;
		cout << "1 - Add contest" << endl;
		cout << "2 - Edit contest" << endl;
		cout << "3 - Delete contest" << endl;
		cout << "4 - Show contest" << endl;
		cout << "5 - Show all contests" << endl;
		cout << "\n\nPress ESC to quit.";
		key = _getch();
		switch (key)
		{
		case '1':
			system("cls");
			add_contest();
			break;
		case '2':
			system("cls");
			edit_contest(search_contest());
			break;
		case '3':
			system("cls");
			delete_contest(search_contest());
			break;
		case '4':
			system("cls");
			show_contest(search_contest());
			break;
		case '5':
			system("cls");
			show_contests();
			break;
		}
		system("cls");
	} while (key != '1' && key != '2' && key != '3' && key != '4' && key != '5');
}

void System::cat_menu()
{
	char key;
	do
	{
		cout << "Category menu" << endl << endl;
		cout << "1 - Add category" << endl;
		cout << "2 - Edit category" << endl;
		cout << "3 - Delete category" << endl;
		cout << "4 - Show category" << endl;
		cout << "5 - Show all categories" << endl;
		cout << "\n\nPress ESC to quit.";
		key = _getch();
		switch (key)
		{
		case '1':
			system("cls");
			add_category();
			break;
		case '2':
			system("cls");
			edit_category(search_category());
			break;
		case '3':
			system("cls");
			delete_category(search_category());
			break;
		case '4':
			system("cls");
			show_category(search_category());
			break;
		case '5':
			system("cls");
			show_categories();
			break;
		}
		system("cls");
	} while (key != '1' && key != '2' && key != '3' && key != '4' && key != '5');
}

void System::club_menu()
{
	char key;
	do
	{
		cout << "Club menu" << endl << endl;
		cout << "1 - Add club" << endl;
		cout << "2 - Edit club" << endl;
		cout << "3 - Delete club" << endl;
		cout << "4 - Show club" << endl;
		cout << "5 - Show all clubs" << endl;
		cout << "\n\nPress ESC to quit.";
		key = _getch();
		switch (key)
		{
		case '1':
			system("cls");
			add_club();
			break;
		case '2':
			system("cls");
			edit_club(search_club());
			break;
		case '3':
			system("cls");
			delete_club(search_club());
			break;
		case '4':
			system("cls");
			show_club(search_club());
			break;
		case '5':
			system("cls");
			show_clubs();
			break;
		}
		system("cls");
	} while (key != '1' && key != '2' && key != '3' && key != '4' && key != '5');
}

bool System::login()
{
	cout << "Enter password" << endl;
	string pass_test;
	cin >> pass_test;
	if (pass_test == "admin1")
		return true;
	else
		return false;
}

bool System::login(Participant * participant)
{
	cout << "Enter password" << endl;
	string pass_test;
	getline(cin, pass_test);
	if (pass_test.compare(participant->password) == 0)
		return true;
	else
		return false;
}

/*void System::statistic(Result* result)
{
	for_each(results.begin(), results.end(), [](Result* result)
	{
		int val = result->points;
		val += result->points;
		cout << "Result sum: " << val << endl;
	});
}*/

/*
Club * System::search_club()
{
	char key;
	do
	{
		cout << "Search club" << endl;
		cout << "1 - by ID" << endl;
		cout << "2 - by city" << endl;
		key = _getch();
		switch (key)
		{
		case '1':
		{
			system("cls");
			int id;
			cout << "Searching by ID" << endl;
			cout << "ID: ";
			cin >> id;
			getchar();
			Club* club = find_club(id);
			if (club == nullptr)
			{
				cout << endl << "Doesn't exist." << endl;
			}
			else
			{
				cout << "Found!" << endl;
			}
			_getch();
			return club;
		}
		case '2':
		{
			system("cls");
			City* city;
			string c_name;
			cout << "Searching by city" << endl;
			cout << "City: ";
			cin >> city->c_name;
			
			vector<Club*> found_clubs = find_club(city->c_name);
			switch (found_clubs.size())
			{
			case 0:
				cout << "Doesn't exist!" << endl;
				_getch();
				return nullptr;
			case 1:
				cout << "Found!" << endl;
				_getch();
				return found_clubs[0];
			default:
				int id;
				cout << "Multiple results. Please provide the corresponding ID." << endl;
				cin >> id;
				getchar();
				Club* club = find_club(id, found_clubs);
				if (club == nullptr)
				{
					cout << "Doesn't exist!" << endl;
				}
				else
				{
					cout << "Found!" << endl;
				}
				_getch();
				return club;
			}
		}
		}
		system("cls");
	} while (key != '1' && key != '2');
}
*/
void System::add_participant()
{
	string name;
	string surname;
	string sex;
	string birthdate;
	int cat_id;
	int club_id;
	cout << "Adding participant" << endl;
	cout << "Name: ";
	getline(cin, name);
	cout << "Surname: ";
	getline(cin, surname);
	cout << "Sex: ";
	getline(cin, sex);
	cout << "Birthdate: ";
	getline(cin, birthdate);
	cout << "Category ID: ";
	cin >> cat_id;
	cout << "Club ID: ";
	cin >> club_id;
	participants.push_back(new Participant(name, surname, sex, birthdate, cat_id, club_id, surname));
	cout << endl << "Participant added.";
	_getch();
}

void System::add_result()
{
		Contest *contest;
		Participant *participant;
		cout << "Adding result." << endl;
		contest = search_contest();
		if (contest != nullptr) {
				system("cls");
				participant = search_participant();
				if (participant != nullptr) {
					system("cls");
						results.push_back(new Result(participant->id, contest->id, true));
						cout << "Result added.";
					}
					else {
						cout << "Result could not be added.";
					}
				}
				else {
					cout << "\has NOT been lent.";
				}
		_getch();
}

void System::add_contest()
{
	string name;
	int day;
	int month;
	int year;
	cout << "Adding contest" << endl;
	cout << "Name: ";
	getline(cin, name);
	cout << "Day: ";
	cin >> day;
	cout << "Month: ";
	cin >> month;
	cout << "Year: ";
	cin >> year;
	contests.push_back(new Contest(name, day, month, year));
	cout << "Contest added.";
	_getch();
}

void System::add_category()
{
	string name;
	cout << "Adding category" << endl;
	cout << "Name: ";
	getline(cin, name);
	categories.push_back(new Category(name));
	cout << "Category added.";
	_getch();
}

void System::add_club()
{
	City* city;
	Country* country;
	string c_name;
	string p_name;
	cout << "Adding club" << endl;
	cout << "City: ";
	getline(cin, c_name);
	cout << "Country: ";
	getline(cin, p_name);
	clubs.push_back(new Club(c_name, p_name));
	cout << endl << "Club added.";
	_getch();
}

void System::edit_participant(Participant * participant)
{
	system("cls");
	if (participant != nullptr)
	{
		char key;
		do
		{
			cout << "Edit participant" << endl;
			cout << "1 - Edit given name" << endl;
			cout << "2 - Edit surname" << endl;
			cout << "3 - Edit sex" << endl;
			cout << "4 - Edit birthdate" << endl;
			cout << "5 - Edit category" << endl;
			cout << "6 - Edit club" << endl;
			key = _getch();
			switch (key)
			{
			case '1':
			{
				system("cls");
				string name;
				cout << "Enter new given name: ";
				getline(cin, name);
				participant->name = name;
				cout << "Done.";
				_getch();
				break;
			}
			case '2':
			{
				system("cls");
				string surname;
				cout << "Enter new surname: ";
				getline(cin, surname);
				participant->surname = surname;
				cout << "Done.";
				_getch();
				break;
			}
			case '3':
			{
				system("cls");
				string sex;
				cout << "Enter new sex: ";
				getline(cin, sex);
				participant->sex = sex;
				cout << "Done.";
				_getch();
				break;
			}
			case '4':
			{
				system("cls");
				string birthdate;
				cout << "Enter new birthdate: ";
				getline(cin, birthdate);
				participant->birthdate = birthdate;
				cout << "Done.";
				_getch();
				break;
			}
			case '5':
			{
				system("cls");
				int cat_id;
				cout << "Enter new category ID: ";
				cin >> cat_id;
				participant->cat_id = cat_id;
				cout << "Done.";
				_getch();
				break;
			}
			case '6':
			{
				system("cls");
				int club_id;
				cout << "Enter new club ID: ";
				cin >> club_id;
				participant->club_id = club_id;
				cout << "Done.";
				_getch();
				break;
			}
			}
			system("cls");
		} while (key != '1' && key != '2' && key != '3' && key != '4' && key != '5' && key != '6');
	}
}

void System::edit_result(Result * result)
{
	system("cls");
	if (result != nullptr)
	{
		char key;
		do
		{
			cout << "Edit result" << endl;
			cout << "1 - Edit contest" << endl;
			cout << "2 - Edit participant" << endl;
			cout << "3 - Edit points" << endl;
			key = _getch();
			switch (key)
			{
			case '1':
			{
				system("cls");
				string name;
				int day, month, year;
				cout << "Editing contest" << endl;
				cout << "Enter new contest name: ";
				getline(cin, name);
				cout << "Enter new date: ";
				cin >> day >> month >> year;
				vector<Contest*> found_contests = find_contest(name, day, month, year);
				switch (found_contests.size())
				{
				case 0:
				{
					cout << "Contest doesn't exist!" << endl;
					cout << "Adding new contest" << endl;
					Contest* contest = new Contest(name, day, month, year);
					contests.push_back(contest);
					cout << "New contest has been added.";
					result->con_id = contest->id;
					cout << "Contest has been edited.";
					_getch();
					break;
				}
				case 1:
				{
					cout << "Found!";
					result->con_id = found_contests[0]->id;
					cout << "Result has been edited";
					_getch();
					break;
				}
				default:
				{
					int id;
					cout << "More than one result." << endl;
					cout << "Pleaes enter the corresponding contest ID: ";
					cin >> id;
					getchar();
					Contest* contest = find_contest(id, found_contests);
					if (contest == nullptr)
					{
						cout << "Doesn't exist!";
					}
					else
					{
						cout << "Found!";
						result->con_id = contest->id;
						cout << "Result has been edited.";
					}
					_getch();
					break;
				}
				}
			}
			case '2':
			{
				system("cls");
				string name;
				string surname;
				cout << "Editing participant" << endl;
				cout << "Enter new given name: ";
				getline(cin, name);
				cout << "Enter new surname: ";
				getline(cin, surname);
				vector<Participant*> found_participants = find_participant(name, surname);
				switch (found_participants.size())
				{
				case 0:
				{
					cout << "Participant doesn't exist!" << endl;
					cout << "Adding new participant" << endl;
					cout << "Enter sex: " << endl;
					string sex;
					getline(cin, sex);
					cout << "Enter birthdate: " << endl;
					string birthdate;
					getline(cin, birthdate);
					cout << "Enter category ID: " << endl;
					int cat_id;
					cin >> cat_id;
					cout << "Enter club ID: " << endl;
					int club_id;
					cin >> club_id;
					Participant* participant = new Participant(name, surname, sex, birthdate, cat_id, club_id, surname);
					participants.push_back(participant);
					cout << "New participant has been added.";
					result->part_id = participant->id;
					cout << "Result has been edited.";
					_getch();
					break;
				}
				case 1:
				{
					cout << "Found!";
					result->part_id = found_participants[0]->id;
					cout << "Result has been edited";
					_getch();
					break;
				}
				default:
				{
					int id;
					cout << "More than one result." << endl;
					cout << "Please enter the corresponding participant ID: ";
					cin >> id;
					getchar();
					Participant* participant = find_participant(id, found_participants);
					if (participant == nullptr)
					{
						cout << "Doesn't exist!";
					}
					else
					{
						cout << "Found!";
						result->part_id = participant->id;
						cout << "Result has been edited.";
					}
					_getch();
					break;
				}
				}
			}
			case '3':
			{
				system("cls");
				int points;
				cout << "Editing points" << endl;
				cout << "Enter points: ";
				cin >> points;
				result->points = points;
				cout << "Done.";
				_getch();
				break;
			}
			break;
			system("cls");
			} 
		}while (key != '1' && key != '2' && key != '3');
	} 
}

void System::edit_contest(Contest * contest)
{
	system("cls");
	if (contest != nullptr)
	{
		char key;
		do
		{
			cout << "Edit contest" << endl;
			cout << "1 - Edit name" << endl;
			cout << "2 - Edit date" << endl;
			key = _getch();
			switch (key)
			{
			case '1':
			{
				system("cls");
				string name;
				cout << "Enter new name: ";
				getline(cin, name);
				contest->name = name;
				cout << "Done.";
				_getch();
				break;
			}
			case '2':
			{
				system("cls");
				int day;
				int month;
				int year;
				cout << "Enter new date: " << endl;
				cout << "Day:" << endl;
				cin >> day;
				cout << "Month:" << endl;
				cin >> month;
				cout << "Year:" << endl;
				cin >> year;
				contest->day = day;
				contest->month = month;
				contest->year = year;
				cout << "Done.";
				_getch();
				break;
			}
			}
			system("cls");
		} while (key != '1' && key != '2');
	}
}

void System::edit_category(Category * category)
{
	system("cls");
	if (category != nullptr)
	{
		char key;
		do
		{
			cout << "Edit category" << endl;
			cout << "1 - Edit name" << endl;
			key = _getch();
			switch (key)
			{
			case '1':
			{
				system("cls");
				string name;
				cout << "Enter new name: ";
				getline(cin, name);
				category->name = name;
				cout << "Done.";
				_getch();
				break;
			}
			}
			system("cls");
		} while (key != '1');
	}
}

void System::edit_club(Club * club)
{
	system("cls");
	if (club != nullptr)
	{
		char key;
		do
		{
			cout << "Edit club" << endl;
			cout << "1 - Edit city" << endl;
			key = _getch();
			switch (key)
			{
			case '1':
			{
				system("cls");
				City* city;
				Country* country;
				string c_name;
				string p_name;
				cout << "Enter new city: ";
				getline(cin, c_name);
				cout << "Enter new country: ";
				getline(cin, p_name);
				club->city->c_name = c_name;
				cout << "Done.";
				_getch();
				break;
			}
			}
			system("cls");
		} while (key != '1');
	}
}

void System::delete_participant(Participant * participant)
{
	if (participant != nullptr) {
		vector<Participant*>::iterator it;
		for (it = participants.begin(); it != participants.end(); ++it) {
			if ((*it) == participant) {
				break;
			}
		}
		delete participant;
		participants.erase(it);
		cout << "Participant removed.";
	}
	_getch();
}

void System::delete_result(Result * result)
{
	if (result != nullptr) {
		vector<Result*>::iterator it;
		for (it = results.begin(); it != results.end(); ++it) {
			if ((*it) == result) {
				break;
			}
		}
		delete result;
		results.erase(it);
		cout << "Result removed.";
	}
	_getch();
}

void System::delete_contest(Contest * contest)
{
	if (contest != nullptr) {
		vector<Contest*>::iterator it;
		for (it = contests.begin(); it != contests.end(); ++it) {
			if ((*it) == contest) {
				break;
			}
		}
		delete contest;
		contests.erase(it);
		cout << "Contest removed.";
	}
	_getch();
}

void System::delete_category(Category * category)
{
	if (category != nullptr) {
		vector<Category*>::iterator it;
		for (it = categories.begin(); it != categories.end(); ++it) {
			if ((*it) == category) {
				break;
			}
		}
		delete category;
		categories.erase(it);
		cout << "Category removed.";
	}
	_getch();
}

void System::delete_club(Club * club)
{
	if (club != nullptr) {
		vector<Club*>::iterator it;
		for (it = clubs.begin(); it != clubs.end(); ++it) {
			if ((*it) == club) {
				break;
			}
		}
		delete club;
		clubs.erase(it);
		cout << "Club removed.";
	}
	_getch();
}

void System::show_participant(Participant * participant)
{
	if (participant != nullptr) {
		system("cls");
		participant->show_participant();
		_getch();
	}
}

void System::show_participants()
{
	if (participants.size() > 0) {
		for (int i = 0; i < participants.size(); i++)
		{
			system("cls");
			cout << i + 1 << ". " << endl;
			participants[i]->show_participant();
			_getch();
		}
	}
	else {
		system("cls");
		cout << "No participants.";
		_getch();
	}
}

void System::show_result(Result * result)
{
	if (result != nullptr) {
		system("cls");
		result->show_result();
		_getch();
	}
}

void System::show_results()
{
	if (results.size() > 0) {
		for (int i = 0; i < results.size(); i++)
		{
			system("cls");
			cout << i + 1 << ". " << endl;
			results[i]->show_result();
			_getch();
		}
	}
	else {
		system("cls");
		cout << "No results.";
		_getch();
	}
}

void System::show_contest(Contest * contest)
{
	if (contest != nullptr) {
		system("cls");
		contest->show_contest();
		_getch();
	}
}

void System::show_contests()
{
	if (contests.size() > 0) {
		for (int i = 0; i < contests.size(); i++)
		{
			system("cls");
			cout << i + 1 << ". " << endl;
			contests[i]->show_contest();
			_getch();
		}
	}
	else {
		system("cls");
		cout << "No contests.";
		_getch();
	}
}

void System::show_category(Category * category)
{
	if (category != nullptr) {
		system("cls");
		category->show_category();
		_getch();
	}
}

void System::show_categories()
{
	if (categories.size() > 0) {
		for (int i = 0; i < categories.size(); i++)
		{
			system("cls");
			cout << i + 1 << ". " << endl;
			categories[i]->show_category();
			_getch();
		}
	}
	else {
		system("cls");
		cout << "No categories.";
		_getch();
	}
}

void System::show_club(Club * club)
{
	if (club != nullptr) {
		system("cls");
		club->show_club();
		_getch();
	}
}

void System::show_clubs()
{
	if (clubs.size() > 0) {
		for (int i = 0; i < clubs.size(); i++)
		{
			system("cls");
			cout << i + 1 << ". " << endl;
			clubs[i]->show_club();
			_getch();
		}
	}
	else {
		system("cls");
		cout << "No clubs.";
		_getch();
	}
}

void System::menu()
{
		load_data();
		bool check;
		char key;
		do
		{
			cout << "Main menu" << endl << endl;
			cout << "1 - Admin login" << endl;
			cout << "2 - Participant login" << endl;
			cout << "\n\nPress ESC to quit.";
			key = _getch();
			switch (key)
			{
			case '1':
				system("cls");
				check = login();
				if (check = true)
					admin_menu();
				else {
					cout << "Wrong password!" << endl;
					_getch();
				}
				break;
			case '2':
				system("cls");
				Participant* participant;
				participant = search_participant();
				check=login(participant);
				if (check = true)
					participant_menu(participant->id);
				else {
					cout << "Wrong password!" << endl;
					_getch();
				}
				break;
			}
			system("cls");
		} while (key != 27);
		save_data();
}
