//Molina Nhoung CS302 1/22/24
//
//Program 1
//
//This file will ask the user for information needed so that the information can be process and
//sent back to this file to know what information to give back to the user. This allows the user
//not interact with the backend of the program and only see what is needed.


#include "snowsports.h"

int main()
{
	//Variables
	int option {0};
	SnowSport player;
/*	SkateLLL skate_player;
	SkiCLL ski_player;
	BoardVector board_player;
	*/
	char add_name[SIZE];


	option = menu();
	do
	{
		if (option == 1)
		{
			add_racer_name(player, add_name);

		}
		else if (option == 2)
		{
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

void add_racer_name(SnowSport & to_add, char add_name[])
{
	cout << "\nName: ";
	cin.get(add_name, SIZE, '\n');
	SnowSport * sport = new SnowSport(add_name);
}

void display_racer(SnowSport & to_display)
{
	to_display.display();
}

