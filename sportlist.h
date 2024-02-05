//Molina Nhoung CS302 2/3/2024
//
//Program 1
//
//This program allow users to race against others with three sport (ice skating, snowboarding, and skiing)
//For each sport, there ae different methods that could determine who wins, such as who started faster,
//or if there was an obstacle in the way, or how much energy the racer has. The program will determine numbers
//based on these events, and in the end will give a score which determines who wins based on the higher score.

#include "snowsports.h"


//NODES
class SkateNode: public IceSkate
{
	public:
		SkateNode();					//default constructor
		SkateNode(const SkateNode & src);		//copy constructor
		SkateNode(const IceSkate & new_skater);		//initialization
		~SkateNode();					//destructor
		int set_next(SkateNode * new_next);		//set next pointer
		SkateNode * & get_next();			//return the next pointer

	private:
		SkateNode * next;
};

class SkiNode: public Ski
{
	public:
		SkiNode();					//default constructor
		SkiNode(const SkiNode & src);			//copy constructor
		SkiNode(const Ski & new_skier);			//initialization
		~SkiNode();					//destructor
		int set_next(SkiNode * new_next);		//set next pointer
		SkiNode * & get_next();				//return the next pointer

	private:
		SkiNode * next;
};


//LISTS
class SkateLLL
{
	public:
		SkateLLL();					//default constructor
		~SkateLLL();					//destructor
		SkateLLL(const SkateLLL & to_copy);		//copy constructor
		SkateLLL & operator=(const SkateLLL & src);	//assignment operator
		int display() const;				//display the racer
		int insert(const IceSkate & src);		//insert a racer into the list
		int find(char * to_find);			//find a racer
		int remove(char * to_remove);			//remove one racer
		int removeAll();				//removes all racers
		int start_race() const;				//starts the race and random events
		int score_board() const;			//shows the scores

	private:
		SkateNode * head;
		int copy(SkateNode * & dest, SkateNode * src);
		int display(SkateNode * head) const;
		int find(char * to_find, SkateNode * head);
		int remove(char * to_remove, SkateNode * & head);
		int removeAll(SkateNode * & head);
		int start_race(SkateNode * head) const;
		int score_board(SkateNode * head) const;
};

class SkiCLL
{
	public:
		SkiCLL();					//default constructor
		~SkiCLL();					//destructor
		SkiCLL(const SkiCLL & to_copy);			//copy constructor
		SkiCLL & operator=(const SkiCLL & src);		//assignment operator
		int display() const;				//displays the racer
		int insert(const Ski & src);			//inserts a racer
		int find(char * to_find);			//find a racer
		int remove(char * to_remove);			//remove one racer
		int removeAll();				//removes all racers
		int start_race() const;				//starts the race and random events
		int score_board() const;			//shows the scores

	private:
		SkiNode * rear;
		int copy(SkiNode * & dest, SkiNode * src, SkiNode * src_rear);
		int display(SkiNode * rear) const;
		int find(char * to_find, SkiNode * rear);
		int remove(char * to_remove, SkiNode * & rear);
		int removeAll(SkiNode * & rear);
		int start_race(SkiNode * rear) const;
		int score_board(SkiNode * rear) const;
};

class BoardVector
{
	public:
		BoardVector();			//default constructor
		~BoardVector();					//destructor
		int display() const;				//displays the racer
		int insert(const SnowBoard & src);		//inserts a racer
		int removeAll();				//removes all racers
		int start_race();				//starts the race and random events

	private:
		vector<SnowBoard> BoardList;
};
