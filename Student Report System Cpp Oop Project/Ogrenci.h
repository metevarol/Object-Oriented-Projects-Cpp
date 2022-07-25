#ifndef Ogrenci_H
#define Ogrenci_H

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class Ogrenci{

	private:

		int OgrenciNumarasi;
		string Ad;
		float Puan;

	public:

		Ogrenci(string Ad,int OgrenciNumarasi,float Puan);

		Ogrenci();

		int getOgrenciNumarasi();
		string getAd();
		float getPuan();


		void setOgrenciNumarasi(int OgrenciNumarasi);
		void setAd(string Ad);
		void setPuan(float Puan);
		void yazdir();

		Ogrenci operator + (Ogrenci const &obj);

		friend bool operator== (const Ogrenci &s1, const Ogrenci &s2);

};



#endif  // en of header file