#pragma warning(disable : 4996)
#pragma once
#include <ctime>
#include <iostream>
using namespace std;

class ActivitateFinanciara
{
protected:
	struct Data {
		unsigned zi;
		unsigned luna;
		unsigned an;
		unsigned ora;
		unsigned minut;
	};

	Data data;
	double suma;

public:
	ActivitateFinanciara(double = 0 );
	ActivitateFinanciara(double, Data&);
	void setData(unsigned, unsigned, unsigned);
	Data getData();
	void setSuma(double);
	double getSuma();
	virtual string getExtra() const = 0;


	friend ostream& operator << (ostream&, const ActivitateFinanciara&);

	virtual ~ActivitateFinanciara();
};

