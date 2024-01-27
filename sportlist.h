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
		SkateNode(const char * & your_name, const char * & skill_level);	//takes in the user's name and skill level to help determine speed
		void display() const;	
		int energy();					//how much energy the skater has until exhausted
		int jump();					//jump to avoid obstacles

	private:
		SkateNode * next;
};

class SkiNode: public Ski
{
	public:
		SkiNode();
		SkiNode(const char * & your_name, const int & skill_level);	//inputs user's name and skill level
		void display() const;
		int energy();					//how much energy the skiier has until exhausted
		int do_flip();					//user flips to avoid obstacle and gain speed

	private:
		SkiNodeNode * next;
};

class BoardNode: public SnowBoard
{
	public:
		BoardNode();
		BoardNode(const char * & your_name, const int & skill_level);	//inputs user's name and skill level
		void display() const;
		int push();					//push the board to start
		int do_flip();					//flip to avoid objects and increase speed
		int jump();					//jump to avoid obstacles
		int stop_board();				//end the race

	private:
		BoardNode * next;
};

class SkateLLL: public SkateNode
{
	public:
		SkateLLL();
		~SkateLLL();
		void set_next(SkateLLL * add_next);

	private:
		SkateNode * head;
};

class SkiCLL: public SkiNode
{
	public:
		SkiCLL();
		~SkCLL();
		void set_next(SkiCLL * add_next);

	private:
		SkiNode * head;
};

class BoardVector: public BoardNode
{
	public:
		BoardVector();
		~BoardVector();
		void set_next(BoardList * add_next);

	private:
		vector<SnowBoard> BoardList;
		BoardNode * head;
};

