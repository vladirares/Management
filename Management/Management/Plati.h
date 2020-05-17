#pragma once
#include "Cheltuieli.h"
#include "cuAgenti.h"

class Plati : public Cheltuieli, public CuAgenti
{
	string numarCont;
	string numarContTVA;
public:
	Plati() = delete;
	Plati(string, double, bool areRate = false, unsigned numarRate = 0);
	void setNumarCont(string);
	void setNumarContTVA(string);
	string getExtra() const;

};

