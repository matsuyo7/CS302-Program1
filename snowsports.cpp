//Molina Nhoung CS302 1/22/24
//
//Program 1
//
//This part of the program will implement the functions by gaining information from the client program
//and sending it here to be processed and know what to send back to the user. 


#include "sportlist.h"
//default constructor
SnowSport::SnowSport(): name(nullptr)
{
}
//copy constructor
SnowSport::SnowSport(const char * new_name)
{
	name = new char [strlen(new_name) + 1];
	strcpy(name, new_name);
}
//destructor
SnowSport::~SnowSport()
{
	if (name)
		delete[] name;
	name = nullptr;
}

//assignment operator
SnowSport & SnowSport::operator=(const SnowSport & src)
{
	if (this == &src)
	{
		delete[] name;
		name = new char [strlen(src.name) + 1];
		strcpy(name, src.name);
	}
	return *this;

}
//Get the name of the player
int SnowSport::racer_info(const char * add_name)
{
	if (!add_name)
		return 0;
	if (name)
		delete[] name;
	name = new char[strlen(add_name) + 1];
	strcpy(name, add_name);

	return 1;
}

//Displays a race
int SnowSport::display() const
{
	if (!name)
		return 0;
	cout << "\nPlayer: " << name << endl;
	return 1;
}

//generate a random number
int SnowSport::generate_num()
{
	srand(time(0));
	int random_num = rand();
	return random_num;
}

//default constructor
IceSkate::IceSkate()
{
	points = 0;
}

//takes in the user's name and skill level to help determine speed
IceSkate::IceSkate(const char * your_name): SnowSport(your_name)
{
}

IceSkate::~IceSkate()
{
	points = 0;
}

int IceSkate::display() const
{
	SnowSport::display();
	return 1;
}

//jump to avoid obstacles, add 10 points if success, -10 points if failed
int IceSkate::jump()
{
	//use current time to to use as a seed
	int random_num = generate_num();
	//if even number, then they jumped over
	if (random_num % 2 == 0)
	{
		cout << "\nRacer " << name << " jumped over a stump!" << endl;
		points = points + 10;
		cout << "\nPoints: " << points << endl;
		return 1;
	}
	cout << "\nRacer " << name << " tripped over a stump!" << endl;
	points = points - 10;
	cout << "\nPoints: " << points << endl;
	return 0;
}

//chance of the racer slipping, add 10 points if success, -10 if failed
int IceSkate::slipped()
{
	cout << "\nThere is a slippery spot!" << endl;
	int random_num = generate_num();
	//if even number, they did not slip
	if (random_num % 2 == 0)
	{
		cout << "\nRacer " << name << " did not slip!" << endl;
		points = points + 10;
		cout << "\nPoints: " << points << endl;
		return 1;
	}
	cout << "\nRacer " << name << " slipped and fell!" << endl;
	points = points - 10;
	cout << "\nPoints: " << points << endl;
	return 0;
}

//give out the current scores
int IceSkate::tallypoints()
{
	cout << "\nCurrent Scores:"
		"\nRacer " << name << ": " << points << endl;
	return 1;
}
