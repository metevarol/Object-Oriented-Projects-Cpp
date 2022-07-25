#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <time.h>
#include "Person.h"

//------------- PERSON CLASS MEMBER FUNCTIONS-----------------------

Person::Person(string name, string surname){

	setSurname(surname);
	setName(name);
	}
Person::Person(){}

string Person::getSurname() {

	return surname;
	}
string Person::getName(){

	return name;
	}

void Person::setSurname(string surname){

	this->surname = surname;
	}
void Person::setName(string name){
	
	this->name = name;

	}


//------------- PASSENGER CLASS MEMBER FUNCTIONS-----------------------

Passenger::Passenger(string name, string surname,int cash) : Person(name,surname){

		setCash(cash);

	}

Passenger::Passenger(string name, string surname) : Person(name,surname){}
Passenger::Passenger(){}

int Passenger::getCash(){

		return cash;
	}
bool Passenger::getTicket() {

		return ticket;
	}

void Passenger::setCash(int cash){

		if(cash<0){

		this->cash = 0;

		cerr<<"Cash can't be negative. It is set to 0."<<endl;
		}
		else

		this->cash = cash;
	}

void Passenger::setTicket(bool ticket){

		this->ticket = ticket;
	}

bool Passenger::buyTicket(int price){

		if(cash>=price){

			setCash(cash-price);
			setTicket(true);

			return true;
		}
		return false;
	}

//--------------ASTRONAUT CLASS MEMBER PRİCE----------------------

Astronaut::Astronaut(string name, string surname, int numMissions) : Person(name,surname){

	setNumMissions(numMissions);
	}
Astronaut::Astronaut(){}

Astronaut::Astronaut(string name, string surname):Person(name,surname){}

int Astronaut::getNumMissions(){

	return numMissions;
	}

void Astronaut::setNumMissions(int numMissions){

	if(numMissions<0){
	cerr<<"Number of missions that astronaut completed can't be negative. It is set to 0."<<endl;
	this-> numMissions = 0;
	}else

	this-> numMissions = numMissions;
	}

void Astronaut::completeMission(){

	setNumMissions(getNumMissions()+1);

	}




