#pragma once
#include "ActivitateFinanciara.h"
#include "Display.h"
#include "Investitie.h"
#include <vector>

const bool istoric = false;
const bool curent = true;

class Aplicatie
{
public: 
	enum State { meniu, addAction, addActionInvestition, addActionPayment, addActionContract, addActionDirect, installments, reports, direct };
	State state;

private:
	static Aplicatie* instance;
	vector<ActivitateFinanciara*> activitati;
	bool mod;
	Aplicatie();
	friend class Display;

	unsigned zi, luna, an;
	bool hasStarted;

public:
	void insert(ActivitateFinanciara* activitate);
	static Aplicatie* getInstance();
	void display();
	State getState()const;
	void setState(State);
	static int timeDif(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
	static int timeDif2(unsigned, unsigned, unsigned);
	static int getCurrentDay();
	static int getCurrentMonth();
	static int getCurrentYear();
	void setMod(bool);
	bool getMod() const;
	void start();
};

