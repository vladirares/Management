#include "Contract.h"

Contract::Contract(double suma) :CuAgenti(suma),Venituri(suma), ActivitateFinanciara(suma){

}

string Contract::getExtra()const {
	string toReturn = "\n";
	if (rate.areRate) {
		toReturn += ("activitatea are " + to_string(rate.numarRate) + " rate\n" +
			"cu data scadenta :" + to_string(rate.dataScadenta.zi) + "." +
			to_string(rate.dataScadenta.luna) + "." + to_string(rate.dataScadenta.an)) + "\n";

	}
	else {
		toReturn += "activitatea nu are rate\n";
	}

	toReturn += "contractul a fost incheiat cu " + this->nume + "\nseria facturii este " +
				to_string(this->serie)+"\n";

	int zile = Aplicatie::timeDif2(this->rate.dataScadenta.zi, this->rate.dataScadenta.luna, this->rate.dataScadenta.an);
	int zileTotal = Aplicatie::timeDif(this->rate.dataScadenta.zi, this->rate.dataScadenta.luna, this->rate.dataScadenta.an, this->data.zi, this->data.luna, this->data.an);
	//int nrRate = this->rate.numarRate * ((double)zile / (zile + zileTotal));
	int nrRate = ((double)this->rate.numarRate / zileTotal) * zile;

	if (nrRate >0 && zile>0) {
		toReturn += "mai sunt " + to_string(zile) + " zile pana la data scadenta\n";
		toReturn += "au ramas de achitat " + to_string(nrRate) + " rate";
	}
	else {
		toReturn += "a fost achitat";
	}

	return toReturn;

}