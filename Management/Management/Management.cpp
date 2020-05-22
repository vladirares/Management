#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include "ActivitateFinanciara.h"
#include "cuAgenti.h"
#include "Investitie.h"
#include "Plati.h"
#include "Aplicatie.h"
#include "Display.h"

using namespace std;

int main()
{
    Aplicatie::getInstance()->start();



    return 0;
}
