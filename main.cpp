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
	int option {0};
	SnowSport player;
	IceSkate iceplayer;
	SkateLLL skate_racer;
/*	SkiCLL ski_player;
	BoardVector board_player;
	*/
	char add_name[SIZE];
	int a_skill_level {0};
	int racer_option {0};





	do
	{
		option = menu();
		if (option == 1)
		{
			do
			{	racer_option = racer_menu();
				if (racer_option == 1)
				{
					add_racer_name(skate_racer, add_name, a_skill_level);
					display_racer(skate_racer);
				}
				else if (racer_option == 2)
				{
				}
				else if (racer_option == 3)
				{
				}
				else if (racer_option == 4)
				{
				}
				else if (racer_option == 5)
				{
				}
				else if (racer_option == 6)
				{
				}
			} while (racer_option != 7);

		}
		else if (option == 2)
		{/*
			do
			{	racer_option = racer_menu();
				if (racer_option == 1)
				{
					add_racer_name(iceplayer, add_name, a_skill_level);
					display_racer(iceplayer);
				}
				else if (racer_option == 2)
				{
				}
				else if (racer_option == 3)
				{
				}
				else if (racer_option == 4)
				{
				}
				else if (racer_option == 5)
				{
				}
				else if (racer_option == 6)
				{
				}
			} while (racer_option != 7);*/
		}
		else if (option == 3)
		{
/*			do
			{	racer_option = racer_menu();
				if (racer_option == 1)
				{
					add_racer_name(iceplayer, add_name, a_skill_level);
					display_racer(iceplayer);
				}
				else if (racer_option == 2)
				{
				}
				else if (racer_option == 3)
				{
				}
				else if (racer_option == 4)
				{
				}
				else if (racer_option == 5)
				{
				}
				else if (racer_option == 6)
				{
				}
			} while (racer_option != 7);
			*/
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

void add_racer_name(SkateLLL & to_add, char add_name[], int a_skill_level)
{

	cout << "\nName: ";
	cin.get(add_name, SIZE, '\n');
	cin.ignore(100, '\n');
	cout << "\nSkill level (1 = new, 10 = pro): ";
	cin >> a_skill_level;
	to_add.insert(add_name, a_skill_level);

}

void display_racer(IceSkate & to_display)
{
	to_display.display();
}

