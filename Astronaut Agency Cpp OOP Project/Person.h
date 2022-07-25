#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <time.h>


using namespace std;

class Person{

	public:

	Person();
	Person(string name, string surname);

	string getSurname() ;
	string getName() ;

	void setSurname(string surname);
	void setName(string name);

	private:

	string name;

	string surname;

};

class Passenger : public Person{

	public:

	Passenger();
	Passenger(string name, string surname);
	Passenger(string name, string surname,int cash);

	int getCash();
	bool getTicket();

	void setCash(int cash);
	void setTicket(bool ticket);

	bool buyTicket(int price);

	private:

	int cash;
	bool ticket;

};


class Astronaut : public Person{

	public:

	Astronaut();
	Astronaut(string name, string surname);
	Astronaut(string name, string surname, int numMissions);

	int getNumMissions();

	void setNumMissions(int numMissions);

	void completeMission();

	private:

	int numMissions;

};


#endif  // en of header file