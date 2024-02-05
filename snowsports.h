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
#include <ctime>
using namespace std;

//10 racer names
inline vector<string> racer_names = {"Eevee", "Gengar", "Pikachu", "Mimikyu", "Snorlax", 
	"Mew", "Arceus", "Lugia", "Umbreon", "Espeon"};

//board colors
inline vector<string> b_colors = {"Red", "Orange", "Yellow", "Green", "Blue", "Purple", 
	"Pink", "White", "Black", "Brown"};

const int SIZE {200};

class SnowSport
{
	public:
		SnowSport();					//default constructor
		SnowSport(const char * new_name);		//initialization
		SnowSport(const SnowSport & to_copy);
		SnowSport & operator=(const SnowSport & src);	//assignment operator
		~SnowSport();					//destructor
		int display() const;				//displays the name
		int compare_names(char * to_compare);		//take in a name to find and return true if the same
		int generate_num();				//generates the random number
		int racer_info(const char * add_name);		//adds in the racer name coming from the client

	protected:
		char * name;					//racer name

};

class IceSkate: public SnowSport
{
	public:
		IceSkate();					//initializes data
		IceSkate(const char * your_name);		//takes in the user's name and skill level to help determine speed
		~IceSkate();					//destructor
		int display() const;				//displays iceskate's points
		int jump();					//jump to avoid obstacles, adds/subtracts points and returns success/failure
		int slipped();					//random chance for player to slip, add/subtracts points and returns success/failure
		int add_time();					//adds the time per second to the points

	
	protected:
		int points;					//racer points

};

class Ski: public SnowSport
{
	public:
		Ski();						//constructor
		Ski(const char * your_name);			//inputs user's name and skill level
		~Ski();						//destructor
		int display() const;				//displays points
		int flip();					//does a flip to avoid obstacle, add/subtract points, return success/failure
		int loss_stick();				//chance to lose sticks, add/subtract points, return success/failure
		int add_time();					//adds the time per second to the points

	protected:
		int points;					//race points

};

class SnowBoard: public SnowSport
{
	public:
		SnowBoard();						//default constructor
		SnowBoard(const char * your_name, char * your_color);	//initializes board color and points
		SnowBoard(const SnowBoard & to_copy);			//copy constructor
		SnowBoard & operator=(const SnowBoard & src);		//assignment operator
		~SnowBoard();						//destructor
		int insert(const char * a_name, char * a_color);	//insert a new racer
		int display() const;					//displays the board color and points
		int flip();						//flip to avoid objects, add/sub points, return success/failure
		int fall();						//fall off the board, add/sub points, return success/fail
		int add_time();						//adds the time per second to the points

	protected:
		char * color;						//color of the snow board
		int points;						//race points
};


//Prototypes
int menu();
int shuffle_name(vector<string> & r_names);
