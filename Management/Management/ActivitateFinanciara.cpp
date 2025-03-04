#include "ActivitateFinanciara.h"

ActivitateFinanciara::ActivitateFinanciara(double suma ) {
	
	time_t now = time(0);
	tm* ltm = localtime(&now);

	this->data.an = 1900 + ltm->tm_year;
	this->data.luna = 1 + ltm->tm_mon;
	this->data.zi =  ltm->tm_mday;
	this->data.ora =  ltm->tm_hour;
	this->data.minut =  ltm->tm_min;

	this->suma = suma;

}

ActivitateFinanciara::ActivitateFinanciara(double suma, Data &data) {

	time_t now = time(0);
	tm* ltm = localtime(&now);

	this->data.an = data.an;
	this->data.luna = data.luna;
	this->data.zi = data.zi;
	this->data.ora = data.ora;
	this->data.minut = data.minut;

	this->suma = suma;

}

void ActivitateFinanciara::setData(unsigned zi, unsigned luna, unsigned an) {
	this->data.zi = zi;
	this->data.luna = luna;
	this->data.an = an;
}

ActivitateFinanciara::Data ActivitateFinanciara::getData() {
	return data;
}

void ActivitateFinanciara::setSuma(double suma) {
	this->suma = suma;
}

double ActivitateFinanciara::getSuma() {
	return suma;
}

string ActivitateFinanciara::getExtra() const{
	return "";
}

ostream& operator << (ostream& out, const ActivitateFinanciara &act) {
	out << "data: " << act.data.zi << "." << act.data.luna << "." << act.data.an << endl;
	out << "ora: " << act.data.ora << ":" << act.data.minut<<endl;
	out << "suma: " << act.suma;
	out << act.getExtra();
	return out;
}

ActivitateFinanciara::~ActivitateFinanciara() {

}