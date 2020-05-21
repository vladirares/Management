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
{/*
    Investitie* invest = new Investitie(100);
    invest->setPerioadaAmortizare(4);
    invest->setDescriere("test test test");
    invest->setSursaBani(imprumut);

    cout << *invest;

    Aplicatie::getInstance()->insert(invest);*/

   // for (int i = 0; i < 1000; i++) {
       

        //cout << "mama";
       // if (system("CLS")) system("clear");
    //}

    Aplicatie::getInstance()->setState(Aplicatie::State::meniu);
    Aplicatie::getInstance()->display();



    return 0;
}
