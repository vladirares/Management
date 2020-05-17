#pragma once
#include "Venituri.h"

class Directa : public Venituri
{
	double serieBon;
	static double serieBonCurent;
	struct Plata {
		bool tipPlata;
		string nrCard;
		string emitentCard;
	};
	Plata plata;
public:
	Directa() = delete;
	Directa(double);
};

