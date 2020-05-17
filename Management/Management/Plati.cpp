#include "Plati.h"

Plati::Plati(string nume, double suma, bool areRate , unsigned numarRate ) : CuAgenti(nume,suma,areRate,numarRate){
	this->nume = nume;
	this->suma = suma;

	//Data *x = new Data();

	this->rate.areRate = areRate;
	this->rate.numarRate = numarRate;
	this->rate.dataScadenta = data;

	this->serie = serieCurenta;
	this->serieCurenta++;
	//this->setNume(nume);
	//this->setSuma(suma);
}

string Plati::getExtra() const{
	string toReturn = "\n";
	if (rate.areRate) {
		toReturn += ("activitatea are " + to_string(rate.numarRate) + " rate\n");
		toReturn += "cu data scadenta :" + to_string(rate.dataScadenta.zi) + "." + to_string(rate.dataScadenta.luna) + "." + to_string(rate.dataScadenta.an);

	}
	return toReturn;
}