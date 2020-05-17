#pragma once
#include "ActivitateFinanciara.h"
#include<iostream>
#include<string>
using namespace std;

class CuAgenti :virtual public ActivitateFinanciara
{
protected:
	string nume;
	unsigned serie;
	static unsigned serieCurenta;

	struct Rate {
		bool areRate;
		unsigned numarRate;
		Data dataScadenta;
	};

	Rate rate;

public:
	CuAgenti() = delete;
	CuAgenti(string , double, bool areRate = false, unsigned numarRate = 0);		//constructor pentru data curenta
	//CuAgenti(string, double, bool areRate , unsigned numarRate , Data& data , unsigned, unsigned ,unsigned ,unsigned, unsigned);	//constructor pentru actiune trecuta
	void setNume(string);
	void setDataScadenta(unsigned, unsigned, unsigned, unsigned, unsigned);
	string getNume();
	//void setSerie();
	unsigned getSerie();
	string getExtra()const;
	virtual ~CuAgenti();
};

