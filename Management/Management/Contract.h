#pragma once
#include"cuAgenti.h"
#include"Venituri.h"
#include "Aplicatie.h"

class Contract : public CuAgenti, public Venituri
{
public:
	Contract(double = 0);
	string getExtra()const;
};

