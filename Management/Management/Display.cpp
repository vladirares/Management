#include "Display.h"


char Display::ecran[210][210];

void Display::moveCursor(int left, int up, int right, int down) {
	
	for (int i = 0; i < up; i++) {
		cout << "\x1b[A";
	}

	for (int i = 0; i < left; i++) {
		cout << "\b";
	}
	
	for (int i = 0; i < right; i++) {
		cout << "\t";
	}
	for (int i = 0; i < down; i++) {
		cout << "\n";
	}
	
}

void Display::display(unsigned xWidth, unsigned yWidth) {

	//afisare ecran
	for (unsigned i = 0; i <= yWidth; i++) {
		cout << endl;
		for (unsigned j = 0; j <= xWidth; j++) {
			cout << ecran[i][j];
		}
	}
}

void Display::displayButton(int startValueI, int startValueJ, int endValueI, int endValueJ, string buttonText) {


	for (int i = startValueI; i <= endValueI; i++) {
		for (int j = startValueJ; j <= endValueJ; j++) {
			if (i == startValueI || i == endValueI) {
				ecran[i][j] = char(254);
			}
			else if (j == startValueJ || j == endValueJ) {
				ecran[i][j] = char(219);
			}
		}
	}

	int contor = 0;
	int i = (startValueI + endValueI) / 2;
	int j = startValueJ + 4;

	while (contor < buttonText.length()) {
		ecran[i][j] = buttonText[contor];
		if (j >= endValueJ - 3) {
			j = (startValueJ + endValueJ) / 2;
			i++;
		}
		else {
			j++;
		}
		contor++;
	}



}

void Display::displayLogo() {
	//afisare logo
	string logo = R"( ________  __                                                           ______   _______   _______  *|        \|  \                                                         /      \ |       \ |       \ *| $$$$$$$$ \$$ _______    ______   _______    _______   ______        |  $$$$$$\| $$$$$$$\| $$$$$$$\*| $$__    |  \|       \  |      \ |       \  /       \ /      \       | $$__| $$| $$__/ $$| $$__/ $$*| $$  \   | $$| $$$$$$$\  \$$$$$$\| $$$$$$$\|  $$$$$$$|  $$$$$$\      | $$    $$| $$    $$| $$    $$*| $$$$$   | $$| $$  | $$ /      $$| $$  | $$| $$      | $$    $$      | $$$$$$$$| $$$$$$$ | $$$$$$$ *| $$      | $$| $$  | $$|  $$$$$$$| $$  | $$| $$_____ | $$$$$$$$      | $$  | $$| $$      | $$      *| $$      | $$| $$  | $$ \$$    $$| $$  | $$ \$$     \ \$$     \      | $$  | $$| $$      | $$      * \$$       \$$ \$$   \$$  \$$$$$$$ \$$   \$$  \$$$$$$$  \$$$$$$$       \$$   \$$ \$$       \$$      *                                                                                                    *                                                                                                     )";

	unsigned contor = 0;
	int i = 3, j = 9;

	while (contor < logo.length()) {
		if (logo[contor] != '*') {
			ecran[i][j] = logo[contor];
			j++;
		}
		else {
			i++;
			j = 9;
		}
		contor++;
	}
}

void Display::displayBorder(unsigned xWidth, unsigned yWidth) {

	for (unsigned i = 0; i <= yWidth; i++) {
		for (unsigned j = 0; j <= xWidth; j++) {

			if (i == 0 || i == yWidth) {
				ecran[i][j] = char(176);
			}
			else if (j == 0 || j == xWidth) {
				ecran[i][j] = char(176);
			}
			else {
				ecran[i][j] = ' ';
			}
		}
	}


}


void Display::displayMenu() {
	if (system("CLS")) system("clear");
	Display::displayBorder(xsize, ysize);
	Display::displayLogo();
	Display::displayButton(15, 9, 19, 30, "Add Action (a)");
	Display::displayButton(15, 34, 19, 53, "Installments (i)");
	Display::displayButton(15, 59, 19, 78, "Reports(r)");
	Display::displayButton(15, 84, 19, 103, "Dir income   (d)");
	Display::displayButton(20, 9, 23, 16, "");
	Display::displayButton(20, 34, 24, 78, ( Aplicatie::getInstance()->getMod()?" Mode (m): curent":" Mode (m): istoric") );

	Display::display(xsize, ysize);

	for (int i = 0; i < 17; i++) {
		cout << "\x1b[A";
	}
	cout << "\t    ";

	char answer;
	cin >> answer;
	switch (answer) {
	case 'a':
		Aplicatie::getInstance()->setState(Aplicatie::State::addAction);
		if (system("CLS")) system("clear");
		Aplicatie::getInstance()->display();
		break;
	case 'i':
		Aplicatie::getInstance()->setState(Aplicatie::State::installments);
		if (system("CLS")) system("clear");
		Aplicatie::getInstance()->display();
		break;
	case 'm':
		Aplicatie::getInstance()->setMod(!Aplicatie::getInstance()->getMod());
		if (system("CLS")) system("clear");
		Aplicatie::getInstance()->display();

	default:
		break;
	}
}

void Display::displayAddAction() {
	Display::displayBorder(xsize, ysize);
	Display::displayButton(4,9,8,40,"Investitie (i)");
	Display::displayButton(9, 9, 13, 40, "Plata (p)");
	Display::displayButton(14, 9, 18, 40, "Constract distributie (c)");
	Display::displayButton(19,9,23,40,"Vanzare directa (v)");
	Display::displayButton(24, 9, 28, 20, "Back (b)");
	Display::displayButton(24,20,28,27,"");

	Display::display(xsize,ysize);
	for (int i = 0; i < 4; i++) {
		cout << "\x1b[A";
	}
	for (int i = 0; i < 97; i++) {
		cout << "\b";
	}

	char answer;
	cin >> answer;
	switch (answer) {
	case 'b':
		Aplicatie::getInstance()->setState(Aplicatie::State::meniu);
		if (system("CLS")) system("clear");
		Aplicatie::getInstance()->display();
		break;
	case 'i':
		Aplicatie::getInstance()->setState(Aplicatie::State::addActionInvestition);
		if (system("CLS")) system("clear");
		Aplicatie::getInstance()->display();
	case 'p':
		Aplicatie::getInstance()->setState(Aplicatie::State::addActionPayment);
		if (system("CLS")) system("clear");
		Aplicatie::getInstance()->display();
		break;
	case 'c':
		Aplicatie::getInstance()->setState(Aplicatie::State::addActionContract);
		if (system("CLS")) system("clear");
		Aplicatie::getInstance()->display();
		break;
	case 'v':
		Aplicatie::getInstance()->setState(Aplicatie::State::addActionDirect);
		if (system("CLS")) system("clear");
		Aplicatie::getInstance()->display();
		break;
	default:
		break;
	}

}

void Display::displayAddActionInvestition() {
	Display::displayBorder(xsize, ysize);
	Display::displayButton(4, 9, 8, 70, "Suma .............. lei");
	Display::displayButton(9, 9, 13, 70, "Perioada amortizare ...... luni");
	Display::displayButton(14, 9, 18, 70, "Descriere: ");
	Display::displayButton(19, 9, 23, 70, "Sursa Banilor Imprumut(i)/ Fonduri(f) ...");
	Display::displayButton(24, 9, 28, 20, "Enter ");
	//Display::displayButton(24, 20, 28, 27, "");

	Display::display(xsize, ysize);

	for (int i = 0; i < 24; i++) {
		cout << "\x1b[A";
	}
	for (int i = 0; i < 100; i++) {
		cout << "\b";
	}

	//moveCursor(24, 120);

	double answer;
	cin >> answer;
	Investitie *investitie = new Investitie(answer);
	investitie->setSuma(answer);
	//moveCursor(0,0,8,3);
	for (int i = 0; i < 4; i++) {
		cout << "\n";
	}
	for (int i = 0; i < 5; i++) {
		cout << "\t";
	}
	cout << "\b\b\b\b";
	cin >> answer;

	investitie->setPerioadaAmortizare(answer);

	for (int i = 0; i < 4; i++) {
		cout << "\n";
	}
	for (int i = 0; i < 4; i++) {
		cout << "\t";
	}

	string descriere;
	cin >> descriere;

	investitie->setDescriere(descriere);

	for (int i = 0; i < 4; i++) {
		cout << "\n";
	}
	for (int i = 0; i < 7; i++) {
		cout << "\t";
	}
	cout << "\b\b\b";
	char sursa;
	cin >> sursa;
	investitie->setSursaBani(sursa == 'i' ? 0 : 1 );

	Aplicatie::getInstance()->insert(investitie);

	Aplicatie::getInstance()->setState(Aplicatie::State::addAction);
	Aplicatie::getInstance()->display();
	
	
}


void Display::displayAddActionPayment() {
	Display::displayBorder(xsize, ysize);
	Display::displayButton(4, 9, 8, 70, "Suma .............. lei");
	Display::displayButton(9, 9, 13, 70, "Numar cont  ........ ");
	Display::displayButton(14, 9, 18, 70, "Numar contTVA ....... ");
	Display::displayButton(19, 9, 23, 70, "Nume Agent..........");
	Display::displayButton(24, 9, 28, 20, "Enter ");

	Display::displayButton(4, 75, 8, 110, "numar rate ....");
	Display::displayButton(9, 75, 13, 110, "zi ....");
	Display::displayButton(14, 75, 18, 110, "luna ....");
	Display::displayButton(19, 75, 23, 110, "an ....");
	//Display::displayButton(24, 20, 28, 27, "");

	Display::display(xsize, ysize);

	for (int i = 0; i < 24; i++) {
		cout << "\x1b[A";
	}
	for (int i = 0; i < 100; i++) {
		cout << "\b";
	}

	//moveCursor(24, 120);

	double answer;
	cin >> answer;
	Plati* plata = new Plati(answer);
	plata->setSuma(answer);
	//moveCursor(0,0,8,3);
	for (int i = 0; i < 4; i++) {
		cout << "\n";
	}
	for (int i = 0; i < 5; i++) {
		cout << "\t";
	}
	cout << "\b\b\b\b\b\b\b\b\b\b";
	string nrCont;
	cin >> nrCont;

	plata ->setNumarCont(nrCont);

	for (int i = 0; i < 4; i++) {
		cout << "\n";
	}
	for (int i = 0; i < 4; i++) {
		cout << "\t";
	}

	cin >> nrCont;

	plata->setNumarContTVA(nrCont);

	for (int i = 0; i < 4; i++) {
		cout << "\n";
	}
	for (int i = 0; i < 7; i++) {
		cout << "\t";
	}
	for (int i = 0; i < 27; i++) {
		cout << "\b";
	}

	cin >> nrCont;
	plata->setNume(nrCont);	//setam numele

	for (int i = 0; i < 16; i++) {
		cout << "\x1b[A";
	}
	for (int i = 0; i < 12; i++) {
		cout << "\t";
	}
	cout << "\b\b\b\b\b";

	int nrRate;
	cin >> nrRate;
	if (nrRate > 0) {
		plata->setAreRate(true);
		plata->setNumarRate(nrRate);
		for (int i = 0; i < 4; i++) {
			cout << "\n";
		}
		for (int i = 0; i < 11; i++) {
			cout << "\t";
		}
		cout << "\b\b\b\b";

		int zi;
		cin >> zi;				// primim zi


		for (int i = 0; i < 4; i++) {
			cout << "\n";
		}
		for (int i = 0; i < 11; i++) {
			cout << "\t";
		}
		cout << "\b\b\b";

		int luna;
		cin >> luna;		//primim luna

		for (int i = 0; i < 4; i++) {
			cout << "\n";
		}
		for (int i = 0; i < 11; i++) {
			cout << "\t";
		}
		cout << "\b\b\b";

		int an;
		cin >> an;

		plata->setDataScadenta(zi, luna, an);

	}
	else {
		plata->setAreRate(false);
	}

	Aplicatie::getInstance()->insert(plata);

	Aplicatie::getInstance()->setState(Aplicatie::State::addAction);
	Aplicatie::getInstance()->display();


}


void Display::displayAddActionContract() {
	Display::displayBorder(xsize, ysize);
	Display::displayButton(4, 9, 8, 70, "Suma .............. lei");
	Display::displayButton(9, 9, 13, 70, "Nume Agent  ........ ");
	Display::displayButton(24, 9, 28, 20, "Enter ");

	Display::displayButton(4, 75, 8, 110, "numar rate ....");
	Display::displayButton(9, 75, 13, 110, "zi ....");
	Display::displayButton(14, 75, 18, 110, "luna ....");
	Display::displayButton(19, 75, 23, 110, "an ....");
	//Display::displayButton(24, 20, 28, 27, "");

	Display::display(xsize, ysize);

	for (int i = 0; i < 24; i++) {
		cout << "\x1b[A";
	}
	for (int i = 0; i < 100; i++) {
		cout << "\b";
	}

	//moveCursor(24, 120);

	double answer;
	cin >> answer;
	Contract* contract = new Contract(answer);
	contract->setSuma(answer);
	//moveCursor(0,0,8,3);
	for (int i = 0; i < 4; i++) {
		cout << "\n";
	}
	for (int i = 0; i < 5; i++) {
		cout << "\t";
	}
	cout << "\b\b\b\b\b\b\b\b\b\b";
	string numeAgent;
	cin >> numeAgent;

	contract->setNume(numeAgent);

	for (int i = 0; i < 6; i++) {
		cout << "\x1b[A";
	}
	for (int i = 0; i < 12; i++) {
		cout << "\t";
	}
	cout << "\b\b\b\b\b";

	int nrRate;
	cin >> nrRate;
	if (nrRate > 0) {
		contract->setAreRate(true);
		contract->setNumarRate(nrRate);
		for (int i = 0; i < 4; i++) {
			cout << "\n";
		}
		for (int i = 0; i < 11; i++) {
			cout << "\t";
		}
		cout << "\b\b\b\b";

		int zi;
		cin >> zi;				// primim zi


		for (int i = 0; i < 4; i++) {
			cout << "\n";
		}
		for (int i = 0; i < 11; i++) {
			cout << "\t";
		}
		cout << "\b\b\b";

		int luna;
		cin >> luna;		//primim luna

		for (int i = 0; i < 4; i++) {
			cout << "\n";
		}
		for (int i = 0; i < 11; i++) {
			cout << "\t";
		}
		cout << "\b\b\b";

		int an;
		cin >> an;

		contract->setDataScadenta(zi, luna, an);

	}
	else {
		contract->setAreRate(false);
	}

	Aplicatie::getInstance()->insert(contract);

	Aplicatie::getInstance()->setState(Aplicatie::State::addAction);
	Aplicatie::getInstance()->display();


}

void Display::displayAddActionDirect() {
	Display::displayBorder(xsize, ysize);
	Display::displayButton(4, 9, 8, 70, "Suma .............. lei");
	Display::displayButton(9, 9, 13, 70, "tipul platii : card(c) / cash(b) ....");
	Display::displayButton(14, 9, 18, 70, "numar card: ............");
	Display::displayButton(19, 9, 23, 70, "emitent card: .............");
	//Display::displayButton(24, 20, 28, 27, "");

	Display::display(xsize, ysize);

	for (int i = 0; i < 24; i++) {
		cout << "\x1b[A";
	}
	for (int i = 0; i < 100; i++) {
		cout << "\b";
	}

	//moveCursor(24, 120);

	double answer;
	cin >> answer;
	Directa* directa = new Directa(answer);
	directa->setSuma(answer);
	//moveCursor(0,0,8,3);
	for (int i = 0; i < 4; i++) {
		cout << "\n";
	}
	for (int i = 0; i < 7; i++) {
		cout << "\t";
	}
	cout << "\b\b\b\b\b\b\b";

	char tip;
	cin >> tip;

	if (tip == 'b') {
		directa->setPlata(cash,"","");
	}
	else {
		for (int i = 0; i < 4; i++) {
			cout << "\n";
		}
		for (int i = 0; i < 4; i++) {
			cout << "\t";
		}
		cout << "\b\b\b";

		string nrCard;
		cin >> nrCard;

		for (int i = 0; i < 4; i++) {
			cout << "\n";
		}
		for (int i = 0; i < 4; i++) {
			cout << "\t";
		}
		cout << "\b\b\b";

		string emitent;
		cin >> emitent;
		directa->setPlata(card, nrCard, emitent);

	}

	Aplicatie::getInstance()->insert(directa);

	Aplicatie::getInstance()->setState(Aplicatie::State::addAction);
	Aplicatie::getInstance()->display();


}

void Display::displayInstallments() {
	for (ActivitateFinanciara* act : Aplicatie::getInstance()->activitati) {
		/*if (typeid(act) == typeid(CuAgenti)) {
			cout << *act;
		}*/

		if (CuAgenti* v = dynamic_cast<CuAgenti*>(act)) {
			// old was safely casted to NewType
			if (v->getAreRate()) {
				cout << *v;
				cout << endl <<endl;
			}
		}
	}
	char x;
	cout << "press any button to get to the menu";
	cin >> x;
	displayMenu();
}