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

string CuAgenti::getNume() const{
	return nume;
}

bool CuAgenti::getAreRate() const{
	return this->rate.areRate;
}

unsigned CuAgenti::getNumarRate() const{
	return this->rate.numarRate;
}

unsigned CuAgenti::getSerie() const {
	return serie;
}


CuAgenti::~CuAgenti() {

}