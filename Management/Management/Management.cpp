#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include "ActivitateFinanciara.h"
#include "cuAgenti.h"
#include "Plati.h"

using namespace std;

int main()
{
    ActivitateFinanciara *act2 = new CuAgenti("mama",100,true,4);
    
    cout << *act2<<endl;


    ActivitateFinanciara* act = new Plati("mama", 100, true, 4);
    cout << *act;

    cout << endl;

    return 0;
}
