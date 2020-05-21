#pragma once
#include "Cheltuieli.h"
#include<iostream>
#include<string>
using namespace std;

const int imprumut = 0;
const int fonduri = 1;

class Investitie final : public Cheltuieli
{
	unsigned perioadaAmortizare;
	string descriere;
	bool sursaBani;
public:
	Investitie() = delete;
	Investitie(double);
	Investitie(double, Data);
	void setPerioadaAmortizare(unsigned);
	unsigned getPerioadaAmortizare() const;
	void setDescriere(string);
	string getDescriere()const ;
	void setSursaBani(bool) ;
	bool getSursaBani() const;
	string getExtra() const;
};

