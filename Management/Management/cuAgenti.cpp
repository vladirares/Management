#include "cuAgenti.h"

unsigned CuAgenti::serieCurenta = 0;

CuAgenti::CuAgenti(string nume, double suma, bool areRate , unsigned numarRate) : ActivitateFinanciara(suma) {
	this->nume = nume;

	this->rate.areRate = areRate;
	this->rate.numarRate = numarRate;
	this->rate.dataScadenta = data;

	this->serie = serieCurenta;
	this->serieCurenta++;
}

void CuAgenti::setDataScadenta(unsigned an, unsigned luna, unsigned zi, unsigned ora, unsigned minut) {
	this->rate.dataScadenta.an = an;
	this->rate.dataScadenta.luna = luna;
	this->rate.dataScadenta.zi = zi;
	this->rate.dataScadenta.ora = ora;
	this->rate.dataScadenta.minut = minut;

}

//CuAgenti::CuAgenti(string nume, double suma,unsigned , unsigned , unsigned , unsigned  bool areRate = 0, unsigned numarRate = 0 , Data& data = *new Data()) : ActivitateFinanciara(suma) {
//	this->nume = nume;
//	this->rate.areRate = areRate;
//	this->rate.numarRate = numarRate;
//	this->data = data;
//	this->serie = serieCurenta;
//	this->serieCurenta++;
//}

void CuAgenti::setNume(string nume) {
	this->nume = nume;
}

string CuAgenti::getNume() {
	return nume;
}

//void CuAgenti::setSerie() {
//	this->serie = CuAgenti::serieCurenta;
//}

unsigned CuAgenti::getSerie() {
	return serie;
}

string CuAgenti::getExtra()const {
	string toReturn = "\n";
	if (rate.areRate) {
		toReturn += ("activitatea are " + to_string(rate.numarRate) + " rate\n") ;
		toReturn += "cu data scadenta :" + to_string(rate.dataScadenta.zi) + "." + to_string(rate.dataScadenta.luna) + "." + to_string(rate.dataScadenta.an);
	
	}
	return toReturn;
}

CuAgenti::~CuAgenti() {

}