#include "Aplicatie.h"

Aplicatie::Aplicatie() {
	this->mod = curent;
}

Aplicatie* Aplicatie::instance;

Aplicatie* Aplicatie::getInstance() {
	if ( !instance ) {
		instance = new Aplicatie();
	}
	return instance;
}

void Aplicatie::insert(ActivitateFinanciara* activitate) {
	activitati.push_back(activitate);
}

void Aplicatie::display() {
	if (system("CLS")) system("clear");
	switch (state) {
		
	case(meniu):
		Display::displayMenu();
		break;

	case (addAction):
		Display::displayAddAction();
		break;

	case (addActionInvestition):
		Display::displayAddActionInvestition();
		break;
	case (addActionPayment):
		Display::displayAddActionPayment();
		break;
	case (addActionContract):
		Display::displayAddActionContract();
		break;
	case (addActionDirect):
		Display::displayAddActionDirect();
		break;
	case (installments):
		Display::displayInstallments();
		break;
	default:
		Display::displayMenu();
		break;

	}
}

Aplicatie::State Aplicatie::getState() const{
	return this->state;
}

void Aplicatie::setState(State state) {
	this->state = state;
}

int Aplicatie::timeDif(unsigned zi2, unsigned luna2, unsigned an2, unsigned zi1, unsigned luna1 , unsigned an1) {
	int zile;
	/*if (an2 < an1) {
		toReturn = "data scadenta depasita";
		return toReturn;
	}
	else if(an2 > an1){
		toReturn += "pana la data scadenta mai " + (an2 - an1 == 1) ? " este  un " : "sunt" +   to_string(an2-an1) + ((an2-an1 > 1) ? " ani " : " an ");
	}
	
	if (luna2 < luna1 && an2 == an1) {
		toReturn = "data scadenta depasita";
		return toReturn;
	}
	else if(luna2 >luna1){
		toReturn += "pana la data scadenta mai " + (an2 - an1 == 1) ? " este  un " : "sunt" + to_string(an2 - an1) + ((an2 - an1 > 1) ? " ani " : " an ");
	}*/


	tm data2 = { 0 }, data1 = {0};
	data2.tm_wday = zi2;
	data2.tm_mon = luna2-1;
	data2.tm_year = an2-1900;

	data1.tm_wday = zi1;
	data1.tm_mon = luna1;
	data1.tm_year = an1;

	int dif = difftime(mktime(&data2), mktime(&data1));

	if (dif < 0) {
		return -1;
	}
	else {
		
		zile = dif / 86400;
	}

	return zile;

}

int Aplicatie::timeDif2(unsigned day, unsigned month, unsigned year) {
	time_t now;
	struct tm dataScadenta;
	double seconds;

	time(&now);  /* get current time; same as: now = time(NULL)  */

	dataScadenta = *localtime(&now);

	dataScadenta.tm_hour = 0; dataScadenta.tm_min = 0; dataScadenta.tm_sec = 0;
	dataScadenta.tm_mon = month;  dataScadenta.tm_mday = day + 1; dataScadenta.tm_year = year - 1900;

	seconds = difftime(mktime(&dataScadenta),now);
	return int(seconds)/86400;
}

int Aplicatie::getCurrentDay() {
	time_t now = time(0);
	tm* ltm = localtime(&now);

	return (ltm->tm_mday);
}

int Aplicatie::getCurrentMonth() {
	time_t now = time(0);
	tm* ltm = localtime(&now);

	return (1 + ltm->tm_mon);
}

int Aplicatie::getCurrentYear() {
	time_t now = time(0);
	tm* ltm = localtime(&now);

	return (1900 + ltm->tm_year);
}

void Aplicatie::setMod(bool mod) {
	this->mod = mod;
}

bool Aplicatie::getMod() const{
	return this->mod;
}