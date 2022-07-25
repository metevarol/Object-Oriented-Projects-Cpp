#include <iostream>
#include <stdlib.h>
#include <string>
#include "Ogrenci.h"

using namespace std;


int main(){

	Ogrenci s1 = Ogrenci("ali",133,90.3);
	Ogrenci s2 = Ogrenci("mehmet",456,80.5);
	Ogrenci s3 = Ogrenci("melisa",780,67);
	Ogrenci s4 = Ogrenci("ali",133,90.3);


	cout<<"Ad\tNumara\tPuan\n"<<endl;

	s1.yazdir();
	s2.yazdir();
	s3.yazdir();
	s4.yazdir();


	cout<<"\n->> (+) operatoru cagirildi:\n"<<endl;

	Ogrenci s5 = s1 + s2;

	cout<<"s1 ve s2 ogrencilerinin puanlari toplami(s5 te tutuluyor): ";
	cout<<s5.getPuan()<<endl<<endl;

	cout<<"\n->> (==) operatoru s1 ve s2 ogrencisi icin cagirildi:\n"<<endl;

	if(s1 == s2)
		cout<<"Ogrenci s1 ve s2 esit"<<endl;
	else
		cout<<"Ogrenci s1 ve s2 esit degil"<<endl;

	cout<<"\n->> (==) operatoru s1 ve s4 ogrencisi icin cagirildi:\n"<<endl;

	if(s1 == s4)
		cout<<"Ogrenci s1 ve s4 esit"<<endl;
	else
		cout<<"Ogrenci s1 ve s4 esit degil"<<endl;



	return 0;
}