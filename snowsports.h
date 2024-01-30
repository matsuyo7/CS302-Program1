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
using namespace std;

const int SIZE {200};

class SnowSport
{
	public:
		SnowSport();					//default constructor
		SnowSport(const SnowSport & to_copy);		//copy constructor
		~SnowSport();					//destructor
		SnowSport & operator=(const SnowSport & src);	//assignment operator
		int get_name(char * & add_name);
		int display() const;				//displays the name
		int startrace();				//start the race
		int stoprace();					//stop the race
		int tallypoints();				//keep track of points

	protected:
		char * name;
};

class IceSkate: public SnowSport
{
	public:
		IceSkate();							//initializes data
		IceSkate(const char * & your_name, const int & skill_level);	//takes in the user's name and skill level to help determine speed
		~IceSkate();
		int display() const;	
		int energy();							//how much energy the skater has until exhausted
		int jump();							//jump to avoid obstacles

	
	protected:
		char * your_skill;
		int your_speed;

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

	protected:
		int skill;
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
		int stop_board();				//end the race

	protected:
		char * color;
		int skill;
		int speed;
};


//Prototypes
int menu();
void add_racer_name(SnowSport & to_add, char add_name[]);
void display_racer(SnowSport & to_display);
