#pragma once
#include "Cheltuieli.h"
#include "cuAgenti.h"
#include "Aplicatie.h"

class Plati : public Cheltuieli, public CuAgenti
{
	string numarCont;
	string numarContTVA;
public:
	Plati() = delete;
	Plati(double);
	Plati(double, Data);
	void setNumarCont(string);
	void setNumarContTVA(string);
	string getNumarCont();
	string getNumarContTVA();
	string getExtra() const;

};

