#pragma once
#include<iostream>
#include<string>
#include "Venituri.h"

const bool card = 1;
const bool cash = 0;

class Directa : public Venituri
{

	static double serieBonCurent;

	double serieBon;
	struct Plata {
		bool tipPlata;
		string nrCard;
		string emitentCard;
	};
	Plata plata;

public:
	Directa() = delete;
	Directa(double);
	Directa(double, Data);

	void setPlata(bool, string, string);
	string getExtra()const;
	double getSerieBon()const;

};

