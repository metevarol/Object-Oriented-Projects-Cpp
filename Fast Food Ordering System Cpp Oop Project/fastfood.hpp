#ifndef FASTFOOD_HPP
#define FASTFOOD_HPP


#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Meal{

private:

	string name;

	float price;

public:

	Meal(string name,float price);

	string getName();

	float getPrice();
};

class Restaurant{

private:

	string name;

	string address;

public:

	Restaurant(string name,string address);

	Restaurant();

	string getName();

	string getAdress();

};



class FastFood : public  Restaurant{

private:

	vector<Meal> meals;

public:

	FastFood(string name,string address);

	void addMeal(Meal meal);

	void printMeals();

	int get_size();

	float getMealPrice(int index);

	string getMealName(int index);


};

class KebabHouse : public  Restaurant{

private:

	vector<Meal> meals;

public:

	KebabHouse(string name,string address);

	void addMeal(Meal meal);

	void printMeals();

	int get_size();

	float getMealPrice(int index);

	string getMealName(int index);


};



#endif //FASTFOOD_HPP