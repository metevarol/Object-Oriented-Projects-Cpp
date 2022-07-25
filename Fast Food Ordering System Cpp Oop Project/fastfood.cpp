#include <iostream>
#include <stdlib.h>
#include<vector>
#include "fastfood.hpp"



//-------------------------------------------------RESTAURANT CLASS----------------------------------------------


Restaurant::Restaurant(string name,string address){

	this->name = name;
	this->address = address;
}

Restaurant::Restaurant(){}

string Restaurant::getName(){

	return name;
}

string Restaurant::getAdress(){

	return address;
}

//-------------------------------------------------FASTFOOD CLASS------------------------------------------------

FastFood::FastFood(string name,string address) : Restaurant(name,address){}

void FastFood::addMeal(Meal meal){

	meals.push_back(meal);

}

void FastFood::printMeals(){
	

	cout<<"Meal\t\tPrice"<<endl<<endl;
	for(int i=0;i<meals.size();i++){

		if(i<3)
		cout<<i+1<<"."<<meals[i].getName()<<"\t"<<meals[i].getPrice()<<endl;
		else
		cout<<i+1<<"."<<meals[i].getName()<<"\t\t"<<meals[i].getPrice()<<endl;

	}

}

int FastFood::get_size(){

    return meals.size();
    
	}

float FastFood::getMealPrice(int index){

	return meals[index].getPrice();
}

string FastFood::getMealName(int index){ 

	return meals[index].getName();
}


//-------------------------------------------------KEBABHOUSE CLASS------------------------------------------------

KebabHouse::KebabHouse(string name,string address) : Restaurant(name,address){}

void KebabHouse::addMeal(Meal meal){

	meals.push_back(meal);

}


void KebabHouse::printMeals(){
	
	cout<<"Meal\t\tPrice"<<endl<<endl;
	for(int i=0;i<meals.size();i++){

		if(i<4)
		cout<<i+1<<"."<<meals[i].getName()<<"\t"<<meals[i].getPrice()<<endl;
		else
		cout<<i+1<<"."<<meals[i].getName()<<"\t\t"<<meals[i].getPrice()<<endl;

	}

}

int KebabHouse::get_size(){

    return meals.size();
    
	}

float KebabHouse::getMealPrice(int index){

	return meals[index].getPrice();
}

string KebabHouse::getMealName(int index){ 

	return meals[index].getName(); 

}


//-------------------------------------------------MEAL CLASS------------------------------------------------

Meal::Meal(string name,float price){

	this->name = name;
	this->price = price;
}

string Meal::getName(){

	return name;
}

float Meal::getPrice(){

	return price;
}

int main(){

	Meal ham1 = Meal("Hamburger",15.6);
	Meal ham2 = Meal("Cheeseburger",17.6);
	Meal ham3 = Meal("Tavuk Burger",14.55);

	Meal kebap1 = Meal("Adana Kebap",17.9);
	Meal kebap2 = Meal("Urfa Kebap",17.9);
	Meal kebap3 = Meal("Beyti Kebap",23.5);
	Meal kebap4 = Meal("Lahmacun",10);

	Meal icecek1 = Meal("Kola",4.5);
	Meal icecek2 = Meal("Gazoz",4.5);
	Meal icecek3 = Meal("Ayran",2.5);
	Meal icecek4 = Meal("Su",1.5);


	FastFood res1 = FastFood("Kardesler Hamburger","Kadikoy,Caferaga");

	KebabHouse res2 = KebabHouse("Kardesler Kebap","Kadikoy,Osmanaga");



	res1.addMeal(ham1);
	res1.addMeal(ham2);
	res1.addMeal(ham3);
	res1.addMeal(icecek1);
	res1.addMeal(icecek2);
	res1.addMeal(icecek3);
	res1.addMeal(icecek4);


	res2.addMeal(kebap1);
	res2.addMeal(kebap2);
	res2.addMeal(kebap3);
	res2.addMeal(kebap4);
	res2.addMeal(icecek1);
	res2.addMeal(icecek2);
	res2.addMeal(icecek3);
	res2.addMeal(icecek4);

	int selection;

	cout<<"************* ONLINE SIPARIS EKRANINA HOSGELDINIZ *************"<<endl<<endl;


	cout<<"1. FastFood"<<endl;
	cout<<"2. KebabHouse"<<endl;
	cout<<"\nLutfen siparis vermek istediginiz restaurantimizi seciniz : "<<endl;
	
	while(1){

	cin>>selection;

	if(selection!=1 && selection!=2)
		cout<<"Yanlis secim lutfen 1 veya 2 seciniz.."<<endl;		
	else
		break;

	}

	int input;
	float total_price=0;
	string orderAddress;
	long int phoneNumber;
	vector<int> mealIndexs;

	if(selection==1){
		
		cout<<endl;

		cout<<res1.getName()<<"'a Hosgeldiniz"<<"   Bulundugunuz Sube: "<<res1.getAdress()<<endl<<endl;

		cout<<"Menu:"<<endl;

		res1.printMeals();

		cout<<"\nSepetinize eklemek istediginiz urunleri seciniz: (her defasinda bir urun)"<<endl;

		cout<<"Cikmak icin 0 seciniz."<<endl<<endl;

		while(1){
			
			cin>>input;
			if(input>0 && input<=res1.get_size()){

				total_price += res1.getMealPrice(input-1);

				mealIndexs.push_back(input-1);
			}
			else
				break;
		}

		cout<<"\nTelefon numarinizi giriniz:";
		cin>>phoneNumber;

		cout<<endl;

		cout<<"Adresinizi giriniz:";
		cin>>orderAddress;

		cout<<endl;

		cout<<"FATURA : "<<endl;

		cout<<"\n\tUrunler:"<<endl<<endl;

		for(int i=0;i<mealIndexs.size();i++){

			cout<<"\t    "<<res1.getMealName(mealIndexs[i])<<"\t"<<res1.getMealPrice(mealIndexs[i])<<endl;
		}

		cout<<"\n\tFiyat:"<<total_price<<endl;

		cout<<"\tGönderi Adresi:"<<orderAddress<<endl;

		cout<<"\tTelefon No:"<<phoneNumber<<endl;

		cout<<"\n\t** AFIYET OLSUN **"<<endl<<endl;

	}

	if(selection==2){

		cout<<endl;

		cout<<res2.getName()<<"'a Hosgeldiniz"<<"   Bulundugunuz Sube: "<<res2.getAdress()<<endl<<endl;

		cout<<"Menu:"<<endl;

		res2.printMeals();

		cout<<"\nSepetinize eklemek istediginiz urunleri seciniz: (her defasinda bir urun)"<<endl;

		cout<<"Cikmak icin 0 seciniz."<<endl<<endl;

		while(1){
			
			cin>>input;
			if(input>0 && input<=res2.get_size()){

				total_price += res2.getMealPrice(input-1);

				mealIndexs.push_back(input-1);
			}
			else
				break;
		}

		cout<<"\nTelefon numarinizi giriniz:";
		cin>>phoneNumber;

		cout<<endl;

		cout<<"Adresinizi giriniz:";
		cin>>orderAddress;

		cout<<endl;

		cout<<"FATURA : "<<endl;

		cout<<"\n\tUrunler:"<<endl<<endl;

		for(int i=0;i<mealIndexs.size();i++){

			cout<<"\t    "<<res2.getMealName(mealIndexs[i])<<"\t"<<res2.getMealPrice(mealIndexs[i])<<endl;
		}

		cout<<"\n\tFiyat:"<<total_price<<endl;

		cout<<"\tGönderi Adresi:"<<orderAddress<<endl;

		cout<<"\tTelefon No:"<<phoneNumber<<endl;

		cout<<"\n\t** AFIYET OLSUN **"<<endl<<endl;

	}


	return 0;
}




