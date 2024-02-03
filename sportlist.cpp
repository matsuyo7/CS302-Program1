//Molina Nhoung CS302 1/22/24
//
//Program 1
//This file implements the functions that deal with the node class and the list class for each
//sport. The lists will be using their parent class as the argument to insert into the list.


//ICESKATE NODE
//default constructor to initialize data
SkateNode::SkateNode(): next(nullptr)
{
}

//initialization list to initialize data members in the hiearchy
SkateNode::SkateNode(const SkateNode & src): IceSkate(src), next(nullptr);
{
}
SkateNode::SkateNode(const IceSkate & new_skater): IceSkate(new_skater), next(nullptr);
{
}
/*SkateNode::SkateNode(const char * your_name, const int & skill_level): IceSkate(your_name, skill_level), next(nullptr)
{
}
*/
SkateNode::~SkateNode()
{
}

//set the next pointer to the incoming pointer
int SkateNode::set_next(SkateNode * new_next)
{
	next = new_next;
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
SkateLLL::SkateLLL & operator=(const SkateLLL & src)
{
	if (this == &src)
		return *this;
	if (head)
		removeAll(head);
	copy(head, src.head);
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
int SkateLLL::insert(const SkateNode & src)
{
	SkateNode * hold = new SkateNode(src);
	hold->set_next(head);
	head = hold;
	return 1;
}

/*
//remove one ice skater, return success/failure
int SkateLLL::remove()
{
}

//wrapper function to find if the player is in the list
int SkateLLL::find_skater(const char * to_find)
{
}

//recursive function to find if the player is in the list
int SkateLLL::find_skater(const char * to_find, SkateNode * head) const
{
}

//remove all ice skaters from the list
int SkateLLL::removeall()
{
}

*/
