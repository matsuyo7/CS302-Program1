//Molina Nhoung CS302 1/22/24
//
//Program 1
//
//This program allow users to race against others with three sport (ice skating, snowboarding, and skiing)
//For each sport, there are different methods that could determine who wins, such as who started faster,
//or if there was an obstacle in the way, or how much energy the racer has. The program will determine numbers
//based on these events, and in the end will give a score which determines who wins based on the higher score.

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;

const int SIZE {200};

class SnowSport
{
	public:
		SnowSport();					//default constructor
		SnowSport(char * new_name, int & your_skill);		//copy constructor
		~SnowSport();					//destructor
		//SnowSport & operator=(const SnowSport & src);	//assignment operator
		int racer_info(char * add_name, int & your_skill);
		int display() const;				//displays the name
		int startrace(int add_skill);				//start the race and add a timer
		int stoprace();					//stop the race

	protected:
		char * name;
		int skill;

};

class IceSkate: public SnowSport
{
	public:
		IceSkate();							//initializes data
		IceSkate(char * your_name, int & skill_level);	//takes in the user's name and skill level to help determine speed
		~IceSkate();
		int display() const;	
		int energy();							//how much energy the skater has until exhausted
		int jump();							//jump to avoid obstacles
		int slipped();					//takes points away if racer slipped
		int tallypoints();				//keep track of points

	
	protected:
		int points;
		int speed;

};

class Ski: public SnowSport
{
	public:
		Ski();							//constructor
		Ski(const char * & your_name, const int & skill_level);	//inputs user's name and skill level
		~Ski();							//destructor
		int display() const;						//displays information
		int energy();						//how much energy the skiier has until exhausted
		int do_flip();						//user flips to avoid obstacle and gain speed
		int lost_stick();
		int tallypoints();				//keep track of points

	protected:
		int points;
		int speed;

};

class SnowBoard: public SnowSport
{
	public:
		SnowBoard();
		SnowBoard(const char * & your_name, const int & skill_level);	//inputs user's name and skill level
		~SnowBoard();
		SnowBoard(const SnowBoard & to_copy);
		SnowBoard & operator=(const SnowBoard & src);
		int display() const;
		int push();					//push the board to start
		int do_flip();					//flip to avoid objects and increase speed
		int jump();					//jump to avoid obstacles
		int tallypoints();				//keep track of points

	protected:
		char * color;
		int points;
		int speed;
};


//Prototypes
int menu();
int racer_menu();
void add_racer_name(SkateLLL & to_add, char add_name[], int a_skill_level);
void display_racer(IceSkate & to_display);

