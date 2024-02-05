//Molina Nhoung CS302 2/3/2024
//
//Program 1
//This file implements the functions that deal with the node class and the list class for each
//sport. The lists will be using their parent class as the argument to insert into the list.
//When inserting, the information will be passed up to the classes that deal with them. This
//file will implement the vector class list for snow boarding

#include "sportlist.h"

//VECTOR
//default constructor
BoardVector::BoardVector()
{
	/*
	BoardList.resize(size);
	list_size = size;*/
}

//destructor
BoardVector::~BoardVector()
{
}

//displays the racer
int BoardVector::display() const
{
	if (BoardList.empty())
		return 0;
	for (auto it = BoardList.begin(); it < BoardList.end(); ++it)
	{
		it->display();
	}
	return 1;
}

//inserts a racer
int BoardVector::insert(const SnowBoard & src)
{
	BoardList.push_back(src);
	return 1;
}

//removes all racers
int BoardVector::removeAll()
{
	BoardList.clear();
	return 1;
}

//starts the race and random events
int BoardVector::start_race()
{
	if (BoardList.empty())
		return 0;
	for (auto it = BoardList.begin(); it < BoardList.end(); ++it)
	{
		it->flip();
		it->fall();
	}
	return 1;
}

/*
//shows the scores
int BoardVector::score_board() const
{
}*/
