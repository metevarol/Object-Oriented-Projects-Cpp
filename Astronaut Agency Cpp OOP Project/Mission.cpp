#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <time.h>
#include "Mission.h"


	Mission::Mission(string name, int cost, int faultProbability){

		crewcount = 0;
		passcount = 0;

		setName(name);

		setCost(cost);

		setFaultProbability(faultProbability);

		numMissions++;

		setMissionNumber(numMissions);

		passengers = (Passenger*) malloc(100 * sizeof(Passenger));

		crew = (Astronaut*) malloc(100 * sizeof(Astronaut));

	}

	Mission::Mission(){

		crewcount = 0;
		passcount = 0;

		passengers = (Passenger*) malloc(100 * sizeof(Passenger));

		crew = (Astronaut*) malloc(100 * sizeof(Astronaut));
	}

	//-------------GETTERS-----------------
		
	string Mission::getName(){

		return name;
	}

	int Mission::getMissionNumber(){

		return missionNumber;
	}

	int Mission::getCost(){

		return cost;
	}

	int Mission::getFaultProbability(){

		return faultProbability;
	}

	bool Mission::getCompleted(){

		return completed;
	}

	int Mission::getNumMissions(){	return numMissions;}

	//-------------SETTERS------------------

	void Mission::setName(string name){

		int length;

		length = name.length();

		if((length==5) && (name[2]=='-')  && ((name[0]>=65) && (name[0]<=90)) 
		&&((name[1]>=65) && (name[1]<=90)) && ((name[3]>=48) && (name[3]<=57)) && ((name[4]>=48) && (name[4]<=57)) ){

		this->name = name;

		}else{

		cerr<<"Given name does not satisfy the mission naming convention. Please set a new name!"<<endl;

		this->name = "AA-00";	
		}
		
	}

	void Mission::setMissionNumber(int missionNumber){

		this -> missionNumber = missionNumber;
	}

	void Mission::setCost(int cost){

		this -> cost = cost;
	}

	void Mission::setFaultProbability(int faultProbability){

		this -> faultProbability = faultProbability;
	}

	void Mission::setCompleted(bool completed){

		this -> completed = completed;
	}


	//------------MEMBER FUNCTIONS-----------

	Mission& Mission::operator+=(Passenger *passenger){

		if(passenger->getTicket()){

			passengers[passcount] = *passenger;

			passcount++;

			return *this;
		}else

		cerr<<"Passenger "<<passenger->getName()<<" "<<passenger->getSurname()<<" does not have a valid ticket!";

			return *this;

		}

	Mission& Mission::operator+=(Astronaut *astronaut){

			crew[crewcount] = *astronaut;

			crewcount++;

			return *this;

		}

	bool Mission::executeMission(){

		int random;

		random = rand() %100;

		if(random > faultProbability){

			cout<<"MISSION "<<getName()<<" SUCCESSFUL!"<<endl;
			
			for(int i=0;i<crewcount;i++){

				crew[i].completeMission();

				cout<<"Astronaut "<<crew[i].getName()<<" "<<crew[i].getSurname()<<" successfully completed "<<
				crew[i].getNumMissions()<<" missions."<<endl;
			}

			setCompleted(true);
			return true;
		}else{
			cout<<"MISSION "<<getName()<<" FAILED!"<<endl;
			cout<<"Agency reschedules the mission."<<endl;
			setCompleted(false);
			return false;
		}
	}

	int Mission::calculateProfit(int ticketprice){

		int profit;
		int earnings=0;

		if(getCompleted()){

			earnings = ticketprice * passcount;

		}

		profit = earnings - cost;

		return profit;

	}

	//int Mission::numMissions= 0;
