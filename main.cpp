//Molina Nhoung CS302 2/3/2024
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
	int option {0};
	IceSkate iceplayer;
	SkateLLL skate_racer;
	Ski skiplayer;
	SkiCLL ski_racer;;
	//BoardVector board_player;
	const char * add_name;
	char pause {' '};
	char start {'n'};
	
	//create a seed for random number
	srand(time(0));
	
	do
	{
		//menu option to pick sport
		option = menu();
		if (option == 1)
		{
			//shuffle the name around
			shuffle_name(racer_names);
			for (auto it = racer_names.begin(); it < racer_names.end(); ++it)
			{
				add_name = (*it).c_str();
				iceplayer.racer_info(add_name);
				skate_racer.insert(iceplayer);

			}
			//displays all the racers
			cout << "\n***RACERS*** ";
			skate_racer.display();
			//starts the race
			cout << "\n\nStart race? (Y/N): ";
			cin >> start;
			cin.ignore(100, '\n');
			if (toupper(start) == 'Y')
			{
				for (int i = 0; i < 5; ++i)
				{
					skate_racer.start_race();
					cout << "\n\nPress a key for next sequence: ";
					cin >> pause;
					cin.ignore(100, '\n');
				}
				skate_racer.display();
			}
			skate_racer.removeAll();
		}
		else if (option == 2)
		{
			//shuffle the name around
			shuffle_name(racer_names);
			for (auto it = racer_names.begin(); it < racer_names.end(); ++it)
			{
				add_name = (*it).c_str();
				skiplayer.racer_info(add_name);
				ski_racer.insert(skiplayer);

			}
			//displays all the racers
			cout << "\n***RACERS*** ";
			ski_racer.display();
			//starts the race
			cout << "\n\nStart race? (Y/N): ";
			cin >> start;
			cin.ignore(100, '\n');
			if (toupper(start) == 'Y')
			{
				for (int i = 0; i < 5; ++i)
				{
					ski_racer.start_race();
					cout << "\n\nPress a key for next sequence: ";
					cin >> pause;
					cin.ignore(100, '\n');
				}
				ski_racer.display();
			}
			ski_racer.removeAll();
		}
		else if (option == 3)
		{
		}
	} while (option != 4);

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
