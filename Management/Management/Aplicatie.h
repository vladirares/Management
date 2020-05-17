#pragma once
#include "ActivitateFinanciara.h"
#include <vector>

extern const bool istoric = false;
extern const bool curent = true;

class Aplicatie
{
	Aplicatie& instance;
	vector<ActivitateFinanciara*> activitati;
	bool mod;
	Aplicatie();

public:
	void insert(ActivitateFinanciara* activitate) {
		activitati.push_back(activitate);
	}
	Aplicatie& getInstance();
};

