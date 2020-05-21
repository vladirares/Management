#include "Investitie.h"

Investitie::Investitie(double suma) : Cheltuieli(suma) , ActivitateFinanciara(suma) {
	this->perioadaAmortizare = NULL;
	this->descriere = "";
	this->sursaBani = imprumut;
}

Investitie::Investitie(double suma, Data data) : Cheltuieli(suma, data) {
	this->perioadaAmortizare = NULL;
	this->descriere = "";
	this->sursaBani = imprumut;
}

void Investitie::setPerioadaAmortizare(unsigned perioada) {
	this->perioadaAmortizare = perioada;
}

unsigned Investitie::getPerioadaAmortizare() const {
	return this->perioadaAmortizare;
}

void Investitie::setDescriere(string descriere) {
	this->descriere = descriere;
}

string Investitie::getDescriere() const {
	return this->descriere;
}

void Investitie::setSursaBani(bool sursa)  {
	this->sursaBani = sursa;
}

bool Investitie::getSursaBani() const {
	return this->sursaBani;
}

string Investitie::getExtra()const {
	string toReturn = "\n";
	toReturn += "Actiunea are o perioada de amortizare de :" +
		to_string(this->perioadaAmortizare) + " luni\n" +
		"sursa banilor este din" + (sursaBani ? " fonduri\n" : " imprumut\n") +
		( (descriere.length()>0) ? ("descriere : "+descriere) : "") ;
	return toReturn;
}