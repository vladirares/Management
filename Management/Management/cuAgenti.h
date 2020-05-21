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
	CuAgenti(double);
	CuAgenti(double, Data&);
	void setNume(string);
	void setAreRate(bool);
	void setNumarRate(unsigned);
	void setDataScadenta(unsigned zi, unsigned luna, unsigned an);
	string getNume();
	//void setSerie();
	bool getAreRate();
	unsigned getNumarRate();
	unsigned getSerie();
	string getExtra()const;
	virtual ~CuAgenti();
};

