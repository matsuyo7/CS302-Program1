//Molina Nhoung CS302 1/22/24
//
//Program 1
//
//This program allow users to race against others with three sport (ice skating, snowboarding, and skiing)
//For each sport, there are different methods that could determine who wins, such as who started faster,
//or if there was an obstacle in the way, or how much energy the racer has. The program will determine numbers
//based on these events, and in the end will give a score which determines who wins based on the higher score.

#include "snowsports.h"


class SkateList: public IceSkate
{
	public:
		SkateList();
		~SkateList();
		void set_next(SkateList * add_next);

	private:
		IceSkate * head;
};

class SkiList: public Ski
{
	public:
		SkiList();
		~SkiList();
		void set_next(SkiList * add_next);

	private:
		Ski * head;
};

class BoardList: public SnowBoard
{
	public:
		BoardList();
		~BoardList();
		void set_next(BoardList * add_next);

	private:
		vector<SnowBoard> 
		SnowBoard * head;
};

