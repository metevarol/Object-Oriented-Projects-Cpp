#include <iostream>
#include <stdlib.h>
#include <string>
#include "Ogrenci.h"

using namespace std;
//--------------------------------------------------------EQUALITY OPERATOR OVERLOADING--------------------------------------------------------


bool operator== (const Ogrenci &s1, const Ogrenci &s2)
{
    return (s1.Ad == s2.Ad && s1.OgrenciNumarasi == s2.OgrenciNumarasi);
}
//--------------------------------------------------------Ogrenci CLASS MEMBER FUNCTIONS--------------------------------------------------------
Ogrenci Ogrenci::operator + (Ogrenci const &obj) {
         Ogrenci o1;
         o1.Puan = Puan + obj.Puan;

         return o1;
   }


Ogrenci::Ogrenci(string Ad,int OgrenciNumarasi,float Puan){

	this->OgrenciNumarasi = OgrenciNumarasi;
	this->Ad = Ad;
	this->Puan = Puan;
}

Ogrenci::Ogrenci(){
	
	this->OgrenciNumarasi = 0;
	this->Ad = Ad = "object for sum of Puan";
	this->Puan = 0;

}

int Ogrenci::getOgrenciNumarasi(){

	return OgrenciNumarasi;
}

string Ogrenci::getAd(){

	return Ad;
}

float Ogrenci::getPuan(){

	return Puan;
}

void Ogrenci::setOgrenciNumarasi(int OgrenciNumarasi){

	this->OgrenciNumarasi = OgrenciNumarasi;
}
void Ogrenci::setAd(string Ad){

	this->Ad = Ad;
}
void Ogrenci::setPuan(float Puan){

	this->Puan = Puan;
}


void Ogrenci::yazdir(){

	cout<<getAd()<<"\t"<<getOgrenciNumarasi()<<"\t"<<getPuan()<<endl;
}



