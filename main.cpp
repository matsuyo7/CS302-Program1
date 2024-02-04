//Molina Nhoung CS302 1/22/24
//
//Program 1
//
//This file will ask the user for information needed so that the information can be process and
//sent back to this file to know what information to give back to the user. This allows the user
//not interact with the backend of the program and only see what is needed.


#include "sportlist.h"



int main()
{
	//Variables
//	int option {0};
//	SnowSport player;
	IceSkate iceplayer;
	/*
	SkateLLL skate_racer;
	*/
/*	SkiCLL ski_player;
	BoardVector board_player;
	*/
	const char * add_name;
	char pause {' '};

	shuffle_name(racer_names);
	cout << "\nShuffled names: ";
	for (auto it = racer_names.begin(); it < racer_names.end(); ++it)
	{
		cout << *it << endl;
		add_name = (*it).c_str();
		cout << "\nChar:" << add_name << endl;
		iceplayer.racer_info(add_name);
		iceplayer.display();
		iceplayer.jump();
		iceplayer.slipped();
		iceplayer.tallypoints();
		cout << "\nPress a key for next sequence: ";
		cin >> pause;
		cin.ignore(100, '\n');

	}


	cout << "\n***Exiting program" << endl;


	return 0;
}

//Menu for the user to choose their sport from. Given three options for sports
int menu()
{
	int option;
	cout << "\n\n***SnowSports Racer***"
		"\nChoose a sport you want to race in:"
		"\n\t1. Ice Skating"
		"\n\t2. Skiing"
		"\n\t3. Snow Boarding"
		"\n\t4. Exit";
	do
	{
		cout << "\nPick an option: ";
		cin >> option;
		cin.ignore(100,'\n');
		if (option < 1 || option > 4)
			cout << "\nTry again" << endl;
	} while (option < 1 || option > 4);
	return option;
}

int racer_menu()
{
	int racer_option = 0;
	do
	{
		cout << "\n***RACER MENU***"
			"\n\t1. Add racer"
			"\n\t2. Display a racer"
			"\n\t3. Display all racers"
			"\n\t4. Remove a racer"
			"\n\t5. Remove all racers"
			"\n\t6. Start race"
			"\n\t7. Exit"
			"\nPick option: ";
		cin >> racer_option;
		cin.ignore(100, '\n');
		if (racer_option < 1 || racer_option > 8)
			cout << "\nTry again" << endl;
	} while (racer_option < 1 || racer_option > 8);
	return racer_option;
}
/*
int add_racer_name(IceSkate & to_add, SkateLLL & to_insert, char add_name[], int a_skill_level)
{

	cout << "\nName: ";
	cin.get(add_name, SIZE, '\n');
	cin.ignore(100, '\n');
	cout << "\nSkill level (1 = new, 10 = pro): ";
	cin >> a_skill_level;
	to_add.racer_info(add_name, a_skill_level);
	//to_insert.insert(to_add);
	return 1;

}

*/
int shuffle_name(vector<string> & r_names)
{
	//seed a random number from the time
	srand(time(0));
	//size of the vector
	size_t size = r_names.size();
	for (size_t i = 0; i < size; ++i)
	{
		size_t r = rand() % size;
		swap(r_names[i], r_names[r]);
	}
	return 1;
}
