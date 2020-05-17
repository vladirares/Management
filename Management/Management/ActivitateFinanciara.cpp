#include "ActivitateFinanciara.h"

//ActivitateFinanciara::ActivitateFinanciara(double suma, unsigned zi = 0, unsigned luna = 0, unsigned an = 0, unsigned ora = 0, unsigned minut = 0){
//	setData(zi,luna,an,ora,minut);
//	setSuma(suma);
//}

ActivitateFinanciara::ActivitateFinanciara(double suma) {
	
	time_t now = time(0);
	tm* ltm = localtime(&now);

	this->data.an = 1900 + ltm->tm_year;
	this->data.luna = 1 + ltm->tm_mon;
	this->data.zi =  ltm->tm_mday;
	this->data.ora =  ltm->tm_hour;
	this->data.minut =  ltm->tm_min;

	this->suma = suma;

}

void ActivitateFinanciara::setData(unsigned zi, unsigned luna, unsigned an, unsigned ora, unsigned minut) {
	this->data.zi = zi;
	this->data.luna = luna;
	this->data.an = an;
	this->data.ora = ora;
	this->data.minut = minut;
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