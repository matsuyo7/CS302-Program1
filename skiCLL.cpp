//Molina Nhoung CS302 2/3/2024
//
//Program 1
//This file implements the functions that deal with the node class and the list class for each
//sport. The lists will be using their parent class as the argument to insert into the list.
//When inserting, the information will be passed up to the classes that deal with them. This
//file will be specifically for the ski CLL class.


#include "sportlist.h"

//SKI NODE
//default constructor
SkiNode::SkiNode(): next(nullptr)
{
}

//copy constructor
SkiNode::SkiNode(const SkiNode & src): Ski(src), next(nullptr)
{
}

//initialization
SkiNode::SkiNode(const Ski & new_skier): Ski(new_skier), next(nullptr)
{
}

//destructor
SkiNode::~SkiNode()
{
}

//set next pointer
int SkiNode::set_next(SkiNode * new_next)
{
	next = new_next;
	return 1;
}

//return the next pointer
SkiNode * & SkiNode::get_next()
{
	return next;
}


//SKI CLL
//default constructor
SkiCLL::SkiCLL(): rear(nullptr)
{
}

//destructor
SkiCLL::~SkiCLL()
{
	if (!rear)
		return;
	SkiNode * head = rear->get_next();
	rear->set_next(nullptr);
	removeAll(head);
}

//copy constructor
SkiCLL::SkiCLL(const SkiCLL & to_copy): rear(nullptr)
{
	copy(rear, to_copy.rear->get_next(), to_copy.rear);
}
int SkiCLL::copy(SkiNode * & dest, SkiNode * src, SkiNode * src_rear)
{
	if (!src)
		return 0;
	SkiNode * temp = new SkiNode(*src);
	if (!dest)
	{
		temp->set_next(temp);
		dest = temp;
	}
	else
	{
		temp->set_next(dest->get_next());
		dest = temp;
	}
	if (src == src_rear)
	{
		rear = dest;
		return 1;
	}
	return copy(dest->get_next(), src->get_next(), src_rear);
}

//asignment operator
SkiCLL & SkiCLL::operator=(const SkiCLL & src)
{
	if (this == &src)
		return *this;
	removeAll(rear);
	copy(rear, src.rear->get_next(), src.rear);
	return *this;
}

//displays the racer
int SkiCLL::display() const
{
	if (!rear)
		return 0;
	return display(rear->get_next());
}
int SkiCLL::display(SkiNode * rear) const
{
	if (this->rear == rear)
	{
		rear->display();
		return 0;
	}
	rear->display();
	return display(rear->get_next());
}

//inserts a racer
int SkiCLL::insert(const Ski & src)
{
	if (!rear)
	{
		rear = new SkiNode(src);
		rear->set_next(rear);
		return 0;
	}
	SkiNode * hold = new SkiNode(src);
	hold->set_next(rear->get_next());
	rear->set_next(hold);
	return 1;

}

//removes all racers
int SkiCLL::removeAll()
{
	if (!rear)
		return 0;
	SkiNode * head = rear->get_next();
	rear->set_next(nullptr);
	return removeAll(head);
}
int SkiCLL::removeAll(SkiNode * & rear)
{
	if (!rear)
		return 0;
	SkiNode * hold = rear->get_next();
	delete rear;
	rear = hold;
	return removeAll(rear->get_next());
}

//starts the race and random events
int SkiCLL::start_race() const
{
	if (!rear)
		return 0;
	return start_race(rear->get_next());
}
int SkiCLL::start_race(SkiNode * rear) const
{
	if (rear == this->rear)
		return 0;
	rear->add_time();
	rear->flip();
	rear->loss_stick();
	rear->get_next();
	return start_race(rear->get_next());
}

//shows the scores
int SkiCLL::score_board() const
{
	if (!rear)
		return 0;
	cout << "\n***SCOREBOARD***";
	return score_board(rear->get_next());
}
int SkiCLL::score_board(SkiNode * rear) const
{
	if (rear == this->rear)
		return 0;
	rear->display();
	return score_board(rear->get_next());
}
