#include "Directa.h"

double Directa::serieBonCurent = 0 ;

Directa::Directa(double suma) : Venituri(suma){
	this->serieBon = Directa::serieBonCurent;
	Directa::serieBonCurent++;
}

Directa::Directa(double suma, Data data) : Venituri(suma, data) {
	this->serieBon = Directa::serieBonCurent;
	Directa::serieBonCurent++;
}

void Directa::setPlata(bool tipPlata, string nrCard, string emitentCard) {
	plata.tipPlata = tipPlata;
	plata.nrCard = nrCard;
	plata.emitentCard = emitentCard;
}

double Directa::getSerieBon()const {
	return this->serieBon;
}

string Directa::getExtra()const {
	string toReturn = "\n";
	toReturn += "serie bon: " + to_string(serieBon) + "\n" + "tipul platii: ";
	if (this->plata.tipPlata == card) {
		toReturn += "card cu nr " + this->plata.nrCard;
	}
	else {
		toReturn += "cash";
	}
	return toReturn;
}
