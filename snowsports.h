//Molina Nhoung CS302 1/22/24
//
//Program 1
//
//This program allow users to race against others with three sport (ice skating, snowboarding, and skiing)
//For each sport, there are different methods that could determine who wins, such as who started faster,
//or if there was an obstacle in the way, or how much energy the racer has. The program will determine numbers
//based on these events, and in the end will give a score which determines who wins based on the higher score.


class SnowSport
{
	public:
		SnowSport();					//initializes data
		SnowSport(const char * & your_name);		//asks for the user's name
		void display() const;				//displays the name
		void start();					//start the race
		void stop();					//stop the race

	protected:
		char * their_name;
}

class IceSkate: public SnowSport
{
	public:
		IceSkate();					//initializes data
		IceSkate(const char * & your_name, const char * & skill_level);	//takes in the user's name and skill level to help determine speed
		void display() const;	
		int push();					//push the skates to start the race
		int energy();					//how much energy the skater has until exhausted
		int jump();					//jump to avoid obstacles
		int stop_skate();				//the end of the race
	
	protected:
		char * your_skill;
		int your_speed;
}

class Ski: public SnowSport
{
	public:
		Ski();
		Ski(const char * & your_name, const int & skill_level);	//inputs user's name and skill level
		void display() const;
		int push();					//push the skis to start the race
		int energy();					//how much energy the skiier has until exhausted
		int do_flip();					//user flips to avoid obstacle and gain speed
		int stop_ski();					//end of race

	protected:
		int your_skill;
		int your_speed;
}

class SnowBoard: public SnowSport
{
	public:
		SnowBoard();
		SnowBoard(const char * & your_name, const int & skill_level);	//inputs user's name and skill level
		void display() const;
		int push();					//push the board to start
		int do_flip();					//flip to avoid objects and increase speed
		int jump();					//jump to avoid obstacles
		int stop_board();				//end the race

	protected:
		int your_skill;
		int your_speed;
}

class SkateNode: public IceSkate
{
	public:
		SkateNode();
		SkateNode(const char * & your name, const char * & skill_level);
		void set_next(SkateNode * add_next);

	proteted:
		SkateNode * next;
}

class SkiNode: public Ski
{
	public:
		SkiNode();
		SkiNode(const char * & your name, const char * & skill_level);
		void set_next(SkiNode * add_next);

	proteted:
		SkiNode * next;
}

class BoardNode: public SnowBoard
{
	public:
		BoardNode();
		BoardNode(const char * & your name, const char * & skill_level);
		void set_next(BoardNode * add_next);

	proteted:
		BoardNode * next;
}
