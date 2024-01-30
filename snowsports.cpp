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
SnowSport::SnowSport(const SnowSport & to_copy)
{
	name = new char [strlen(to_copy.name) + 1];
	strcpy(name, to_copy.name);
}

//destructor
SnowSport::~SnowSport()
{
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
//Get the name of the plauer
int SnowSport::get_name(char * & add_name)
{
	if (!add_name)
		return 0;
	strcpy(name, add_name);
	return 1;
}

//Displays a race
int SnowSport::display() const
{
	cout << name << endl;
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
