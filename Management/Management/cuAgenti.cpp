#include "cuAgenti.h"

unsigned CuAgenti::serieCurenta = 0;

CuAgenti::CuAgenti(double suma) : ActivitateFinanciara(suma) {
	this->nume = "";
	this->rate.areRate = false;
	this->serie = CuAgenti::serieCurenta;
	CuAgenti::serieCurenta++;
}

CuAgenti::CuAgenti(double suma, Data &data) : ActivitateFinanciara(suma, data) {
	this->nume = "";
	this->rate.areRate = false;
	this->serie = CuAgenti::serieCurenta;
	CuAgenti::serieCurenta++;
}


void CuAgenti::setNume(string nume) {
	this->nume = nume;
}

void CuAgenti::setAreRate(bool rate) {
	this->rate.areRate = rate;
}

void CuAgenti::setNumarRate(unsigned rate) {
	this->rate.numarRate = rate;
}

void CuAgenti::setDataScadenta(unsigned zi, unsigned luna, unsigned an) {
	this->rate.dataScadenta.an = an;
	this->rate.dataScadenta.luna = luna;
	this->rate.dataScadenta.zi = zi;

}

string CuAgenti::getNume() {
	return nume;
}

bool CuAgenti::getAreRate() {
	return this->rate.areRate;
}

unsigned CuAgenti::getNumarRate() {
	return this->rate.numarRate;
}

unsigned CuAgenti::getSerie() {
	return serie;
}


////poate stergem de aici !!!!
string CuAgenti::getExtra()const {
	string toReturn = "\n";
	if (rate.areRate) {
		toReturn += ("activitatea are " + to_string(rate.numarRate) + " rate\n" +
					"cu data scadenta :" + to_string(rate.dataScadenta.zi) + "." +
					to_string(rate.dataScadenta.luna) + "." + to_string(rate.dataScadenta.an)) + "\n";
	
	}
	else {
		toReturn += "activitatea nu are rate\n";
	}
	return toReturn;
}

CuAgenti::~CuAgenti() {

}