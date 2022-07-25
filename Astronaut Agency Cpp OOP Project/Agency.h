#ifndef AGENCY_H
#define AGENCY_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <time.h>
#include "Mission.h"


using namespace std;


class Agency{

	public:

	int nextmissioncount;

	int compmissioncount;

	int crewcount;

	Agency();

	Agency(string name, int cash, int ticketPrice);

	string getName();

	void setName(string name);

	int getCash();

	void setCash(int cash);

	int getTicketPrice();

	void setTicketPrice(int ticketPrice);

	void addMission(Mission mission);

	void executeNextMission();

	friend ostream & operator << (ostream &out,Agency a);

	private:

	string name;

	int cash;

	int ticketPrice;

	Astronaut *crew;

	Mission *completedMissions;

	Mission *nextMissions;


};


#endif // en of header file.