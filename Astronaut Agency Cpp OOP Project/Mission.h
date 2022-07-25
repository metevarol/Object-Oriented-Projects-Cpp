#ifndef MISSION_H
#define MISSION_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <time.h>
#include "Person.h"

using namespace std;

class Mission{

	public:

	int passcount;

	int crewcount;

	//-----------CONSTRUCTORS--------------

	Mission();

	Mission(string name, int cost, int faultProbability);	

	//-------------GETTERS-----------------
		
	string getName();

	int getMissionNumber();

	int getCost();

	int getFaultProbability();

	bool getCompleted();

	int getNumMissions();

	//-------------SETTERS------------------

	void setName(string name);

	void setMissionNumber(int missionNumber);

	void setCost(int cost);

	void setFaultProbability(int faultProbability);

	void setCompleted(bool completed);


	//------------MEMBER FUNCTIONS-----------

	Mission& operator+=(Passenger *passenger);

	Mission& operator+=(Astronaut *astronaut);

	bool executeMission();

	int calculateProfit(int ticketprice);



	private:

	string name;

	int missionNumber;

	int cost;

	int faultProbability;

	bool completed;

	static int numMissions;

	Passenger *passengers;

	Astronaut *crew;


};



#endif // end of header file