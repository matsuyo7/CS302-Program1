//Molina Nhoung CS302 1/22/24
//
//Program 1
//
//This program allow users to race against others with three sport (ice skating, snowboarding, and skiing)
//For each sport, there ae different methods that could determine who wins, such as who started faster,
//or if there was an obstacle in the way, or how much energy the racer has. The program will determine numbers
//based on these events, and in the end will give a score which determines who wins based on the higher score.

#include "snowsports.h"


class SkateNode: public IceSkate
{
	public:
		SkateNode();					//initializes data
//		SkateNode(const char * your_name, const int & skill_level);	//takes in the user's name and skill level to help determine speed
		SkateNode(const SkateNode & src);
		SkateNode(const IceSkate & new_skater);
		~SkateNode();
		int set_next(SkateNode * new_next);
		SkateNode * & get_next();

	private:
		SkateNode * next;
};

class SkiNode: public Ski
{
	public:
		SkiNode();
		SkiNode(const char * your_name, const int & skill_level);	//inputs user's name and skill level
		~SkiNode();
		int set_next(SkiNode * new_next);
		SkiNode * & get_next();

	private:
		SkiNode * next;
};

/*
class BoardNode: public SnowBoard
{
	public:
		BoardNode();
		BoardNode(const char * & your_name, const int & skill_level);	//inputs user's name and skill level
		~BoardNode();

	private:
		BoardNode * next;
};*/

class SkateLLL
{
	public:
		SkateLLL();
		~SkateLLL();
		SkateLLL(const SkateLLL & to_copy);
		SkateLLL & operator=(const SkateLLL & src);
		int display() const;
		int insert(const SkateNode & src);
		int remove();
		int find_skater(const char * to_find) const;
		int removeall();

	private:
		SkateNode * head;
		int copy(SkateNode * & dest, SkateNode * src);
		int find_skater(const char * to_find, SkateNode * head) const;
		int display(SkateNode * head) const;
};

class SkiCLL
{
	public:
		SkiCLL();
		~SkiCLL();
		SkiCLL(const SkiCLL & to_copy);
		SkiCLL & operator=(const SkiCLL & src);
		int display() const;
		int insert();
		int remove();
		int find_skier(const char * to_find) const;
		int removeall();

	private:
		SkiNode * head;
		int find_skier(const char * to_find, SkiNode * head) const;
		int display(SkiNode * head) const;
};
/*
class BoardVector
{
	public:
		BoardVector();
		~BoardVector();
		int display() const;

	private:
		vector<SnowBoard> BoardList;
		BoardNode * head;
};
*/
