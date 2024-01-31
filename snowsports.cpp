//Molina Nhoung CS302 1/22/24
//
//Program 1
//
//This part of the program will implement the functions by gaining information from the client program
//and sending it here to be processed and know what to send back to the user. 


#include "snowsports.h"

//default constructor
SnowSport::SnowSport()
{
}

//copy constructor
SnowSport::SnowSport(char * new_name, int & your_skill): name(nullptr), skill(your_skill)
{
	skill = 0;
	name = new char [strlen(new_name) + 1];
	strcpy(name, new_name);
	point = 0;
}

//destructor
SnowSport::~SnowSport()
{
	if (name)
		delete[] name;
	name = nullptr;
	skill = 0;
}

//assignment operator
/*SnowSport & SnowSport::operator=(const SnowSport & src)
{
	if (this == &src)
	{
		delete[] name;
		name = new char [strlen(src.name) + 1];
		strcpy(name, src.name);
	}
	return *this;

}*/
//Get the name of the plauer
int SnowSport::racer_info(char * add_name, int & your_skill)
{
	if (!add_name)
		return 0;
	name = new char[strlen(add_name) + 1];
	strcpy(name, add_name);
	skill = your_skill;

	return 1;
}

//Displays a race
int SnowSport::display() const
{
	if (!name || !skill)
		return 0;
	cout << "\nPlayer: " << name << endl;
	cout << "\nSkill level: " << skill << endl;
	return 1;
}
/*
//start the race
int SnowSport::startrace()
{
}

//stops the race and ends the points
int SnowSport::stoprace()
{
}

//Calculates the points in the end
int SnowSport::tallypoints()
{
}
*/

IceSkate::IceSkate()
{
}
//takes in the user's name and skill level to help determine speed
IceSkate::IceSkate(char * your_name, const int & skill_level): SnowSport(your_name, skill_level)
{
}

int IceSkate::display() const
{
	SnowSport::display();
	return 1;
}

