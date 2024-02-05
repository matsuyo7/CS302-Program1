//Molina Nhoung CS302 2/3/2024
//
//Program 1
//This file implements the functions that deal with the node class and the list class for each
//sport. The lists will be using their parent class as the argument to insert into the list.
//When inserting, the information will be passed up to the classes that deal with them. This
//file will implement the skate LLL class.

#include "sportlist.h"

//ICESKATE NODE
//default constructor to initialize data
SkateNode::SkateNode(): next(nullptr)
{
}

//copy constructor
SkateNode::SkateNode(const SkateNode & src): IceSkate(src), next(nullptr)
{
}

//initialization list to initialize data members in the hiearchy
SkateNode::SkateNode(const IceSkate & new_skater): IceSkate(new_skater), next(nullptr)
{
}

//destructor
SkateNode::~SkateNode()
{
}

//set the next pointer to the incoming pointer
int SkateNode::set_next(SkateNode * new_next)
{
	next = new_next;
	return 1;
}

//return the next pointer
SkateNode * & SkateNode::get_next()
{
	return next;
}

//ICESKATE LLL
//default constructor
SkateLLL::SkateLLL(): head(nullptr)
{
}

//destructor
SkateLLL::~SkateLLL()
{
	if (!head)
		return;
	removeAll(head);
}

//copy constructor
SkateLLL::SkateLLL(const SkateLLL & to_copy): head(nullptr)
{
	copy(head, to_copy.head);
}

//function to copy from the incoming SkateNode class, returns the number of nodes copied
int SkateLLL::copy(SkateNode * & dest, SkateNode * src)
{
	if (!src)
	{
		dest = nullptr;
		return 0;
	}
	dest = new SkateNode(*src);
	return 1 + copy(dest->get_next(), src->get_next());
}

//assignment operator
SkateLLL & SkateLLL::operator=(const SkateLLL & src)
{
	if (this == &src)
		return *this;
	if (head)
		removeAll(head);
	copy(head, src.head);
	return *this;
}

//the iceskate LLL display that will also go up the hiearchy to display all in the LLL
int SkateLLL::display() const
{
	if (!head)
		return 0;
	return display(head);
}

int SkateLLL::display(SkateNode * head) const
{
	if (!head)
		return 0;
	head->display();
	return display(head->get_next());
}

//insert an ice skater into a LLL, return success/failure
int SkateLLL::insert(const IceSkate & src)
{
	if (!head)
	{
		head = new SkateNode(src);
		head->get_next();
		return 0;
	}
	SkateNode * hold = new SkateNode(src);
	hold->set_next(head);
	head = hold;
	return 1;
}

//find a racer
int SkateLLL::find(char * to_find)
{
	if (!head)
		return 0;
	return find(to_find, head);
}
int SkateLLL::find(char * to_find, SkateNode * head)
{
	if (!head)
		return 0;
	if (head->compare_names(to_find))
		return 1;
	return find(to_find, head->get_next());
}

//remove one racer if found
int SkateLLL::remove(char * to_remove)
{
	if (!head)
		return 0;
	return remove(to_remove, head);
}
int SkateLLL::remove(char * to_remove, SkateNode * & head)
{
	if (!head)
		return 0;
	if (head->compare_names(to_remove))
	{
		SkateNode * hold = head->get_next();
		delete head;
		head = hold;
		return 1;
	}
	return remove(to_remove, head->get_next());
}

//remove all ice skaters from the list
int SkateLLL::removeAll()
{
	if (!head)
		return 0;
	return removeAll(head);
}


int SkateLLL::removeAll(SkateNode * & head)
{
	if (!head)
		return 0;
	SkateNode * hold = head->get_next();
	delete head;
	head = nullptr;
	return removeAll(hold);
}

//starts the random events
int SkateLLL::start_race() const
{
	if (!head)
		return 0;
	return start_race(head);
}
int SkateLLL::start_race(SkateNode * head) const
{
	if (!head)
		return 0;
	head->add_time();
	head->jump();
	head->slipped();
	head->get_next();
	return start_race(head->get_next());
}

//Shows the scoreboard for all the players
int SkateLLL::score_board() const
{
	if (!head)
		return 0;
	cout << "\n***SCOREBOARD***";
	return score_board(head);
}
int SkateLLL::score_board(SkateNode * head) const
{
	if (!head)
		return 0;
	head->display();
	return score_board(head->get_next());
}

