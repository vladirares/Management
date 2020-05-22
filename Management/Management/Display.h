#pragma once
#include<iostream>
#include <stdlib.h>
#include"Aplicatie.h"
#include "Plati.h"
#include "Contract.h"
#include "Directa.h"
#include "cuAgenti.h"
#include <typeinfo>
using namespace std;

class Display
{
	static const int xsize = 120, ysize = 30;
	
public:
	static char ecran[210][210];
	static void moveCursor(int left = 0, int up = 0, int right = 0, int down = 0);
	static void display(unsigned xWidth, unsigned yWidth);
	static void displayButton(int startValueI, int startValueJ, int endValueI, int endValueJ, string buttonText);
	static void displayLogo();
	static void displayBorder(unsigned xWidth, unsigned yWidth);

	static void displayIstoric();

	static void displayMenu();
	static void displayAddAction();
	static void displayAddActionInvestition();
	static void displayAddActionPayment();
	static void displayAddActionContract();
	static void displayAddActionDirect();
	
	static void displayInstallments();

	static void displayReports();

	static void displayDirect();

	static void start();
};

