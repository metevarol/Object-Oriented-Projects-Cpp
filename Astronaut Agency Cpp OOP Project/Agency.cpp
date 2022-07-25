#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <time.h>
#include "Agency.h"
#include "Mission.h"

	ostream & operator << (ostream &out,Agency a){
	

	    out<<"Agency name: "<<a.getName()<<", Total cash: "<<a.getCash()<<", Ticket Price: "<<a.getTicketPrice()<<endl;

		out<<"Next Missions:"<<endl;
		if(a.nextmissioncount==0)
		out<<"No missions available."<<endl;
		else{
		for(int i=0;i<a.nextmissioncount;i++)
		out<<"Mission number: "<<a.nextMissions[i].getMissionNumber()<<" Mission name: "<<a.nextMissions[i].getName()<<" Cost: "<<
		a.nextMissions[i].getCost()<<endl;
		}
		

		out<<"Completed Missions:"<<endl;
		if(a.compmissioncount==0)
		out<<"No missions completed before."<<endl;
		else{
		for(int i=0;i<a.compmissioncount;i++)
		out<<"Mission number: "<<a.completedMissions[i].getMissionNumber()<<" Mission name: "<<a.completedMissions[i].getName()<<" Cost: "<<
		a.completedMissions[i].getCost()<<endl;
		}

	    return out;

	}
	

	Agency::Agency(){

		nextmissioncount = 0;
		compmissioncount = 0;

		nextMissions = (Mission*) malloc(100 * sizeof(Mission));

		completedMissions = (Mission*) malloc(100 * sizeof(Mission));

		crew = (Astronaut*) malloc(100 * sizeof(Astronaut));
	}
	Agency::Agency(string name, int cash, int ticketPrice){

		setName(name);
		setCash(cash);
		setTicketPrice(ticketPrice);

		nextmissioncount = 0;
		compmissioncount = 0;

		nextMissions = (Mission*) malloc(100 * sizeof(Mission));

		completedMissions = (Mission*) malloc(100 * sizeof(Mission));

		crew = (Astronaut*) malloc(100 * sizeof(Astronaut));
	}

	string Agency::getName(){

		return name;
	}

	void Agency::setName(string name){

		this->name = name;
	}

	int Agency::getCash(){

		return cash;
	}

	void Agency::setCash(int cash){

		this->cash = cash;
	}

	int Agency::getTicketPrice(){

		return ticketPrice;
	}

	void Agency::setTicketPrice(int ticketPrice){

		if(ticketPrice>0)

		this-> ticketPrice = ticketPrice;

		else{
		cerr<<"Ticket price can't be negative. It is set to 0."<<endl;
		this-> ticketPrice = 0;

		}

	}

	void Agency::addMission(Mission m){

		nextMissions[nextmissioncount] = m;

		nextmissioncount++;
	}

	void Agency::executeNextMission(){

		if(nextmissioncount==0){

		cerr<<"No available mission to execute!"<<endl;
		return;

		}

		nextMissions[0].executeMission();

		if(nextMissions[0].getCompleted()){

			completedMissions[compmissioncount] = nextMissions[0];

			

			compmissioncount++;

			setCash(cash + nextMissions[0].calculateProfit(getTicketPrice()));


			for(int i=0;i<nextmissioncount-1;i++){

				nextMissions[i] = nextMissions[i+1];
			}

			nextmissioncount--;

		}else{

			//cerr<<"No available mission to execute!"<<endl;
			nextMissions[nextmissioncount] = nextMissions[0];

			for(int i=0;i<nextmissioncount;i++){

				nextMissions[i] = nextMissions[i+1];
			}
		}


	}

	

