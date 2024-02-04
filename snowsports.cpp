//Molina Nhoung CS302 2/3/24
//
//Program 1
//
//This part of the program will implement the functions by gaining information from the client program
//and sending it here to be processed and know what to send back to the user. These classes use
//inherincy to divide the work amongst different classes.


#include "sportlist.h"

//SNOWSPORTS
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
SnowSport::SnowSport(const SnowSport & to_copy)
{
	name = new char [strlen(to_copy.name) + 1];
	strcpy(name, to_copy.name);
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
	cout << "\nPlayer: " << name;
	return 1;
}

//generate a random number
int SnowSport::generate_num()
{
	int random_num = rand() % 10;
	return random_num;
}


//ICESKATE
//default constructor
IceSkate::IceSkate()
{
	points = 0;
}

//takes in the user's name and skill level to help determine speed
IceSkate::IceSkate(const char * your_name): SnowSport(your_name)
{
}

//destructor
IceSkate::~IceSkate()
{
	points = 0;
}

//displays points
int IceSkate::display() const
{
	SnowSport::display();
	cout << " Points: " << points;
	return 1;
}

//jump to avoid obstacles, add 10 points if success, -10 points if failed
int IceSkate::jump()
{
	int random_num = generate_num();
	if (random_num % 2 == 0)
	{
		//use current time to to use as a seed
		random_num = generate_num();
		//if even number, then they jumped over
		if (random_num % 2 == 0)
		{
			cout << "\nRacer " << name << " jumped over a stump!";
			points = points + 2;
			cout << "\n+2 points";
			return 1;
		}
		cout << "\nRacer " << name << " tripped over a stump!";
		--points;
		cout << "\n-1 point";
	}
	return 0;
}

//chance of the racer slipping, add 10 points if success, -10 if failed
int IceSkate::slipped()
{
	int random_num = generate_num();
	if (random_num % 2 == 0)
	{
		random_num = generate_num();
		//if even number, they slipped
		if (random_num % 2 == 0)
		{
			cout << "\nRacer " << name << " avoided a puddle!";
			points = points + 2;
			cout << "\n+2 points";
			return 1;
		}
		cout << "\nRacer " << name << " slipped and fell!";
		--points;
		cout << "\nLoss 1 point";
	}
	return 0;
}

//adds a point for every second
int IceSkate::add_time()
{
	++points;
	return 1;
}


//SKI
//default constructor
Ski::Ski()
{
	points = 0;
}

//inputs user's name and skill level
Ski::Ski(const char * your_name): SnowSport(your_name)
{
}

//destructor
Ski::~Ski()
{
	points = 0;
}

//displays points
int Ski::display() const
{
	SnowSport::display();
	cout << " Points: " << points;
	return 1;
}

//does a flip to avoid obstacle, add/subtract points, return success/failure
int Ski::flip()
{
	int random_num = generate_num();
	if (random_num % 2 == 0)
	{
		//use current time to to use as a seed
		random_num = generate_num();
		//if even number, then they flip
		if (random_num % 2 == 0)
		{
			cout << "\nRacer " << name << " flipped to jump over the ledge!";
			points = points + 2;
			cout << "\n+2 points";
			return 1;
		}
		cout << "\nRacer " << name << " fell off the ledge!";
		--points;
		cout << "\n-1 point";
	}
	return 0;
}

//chance to lose sticks, add/subtract points, return success/failure
int Ski::loss_stick()
{
	int random_num = generate_num();
	if (random_num % 2 == 0)
	{
		//use current time to to use as a seed
		random_num = generate_num();
		//if even number, then they don't lose their ski sticks
		if (random_num % 2 == 0)
		{
			cout << "\nRacer " << name << " almost loss their sticks!";
			points = points + 2;
			cout << "\n+2 points";
			return 1;
		}
		cout << "\nRacer " << name << " loss their sticks!";
		--points;
		cout << "\n-1 point";
	}
	return 0;
}

//adds a point for every second
int Ski::add_time()
{
	++points;
	return 1;
}
