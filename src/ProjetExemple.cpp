//============================================================================
// Name        : ProjetExemple.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

using namespace std;
#include "Personnage.h"
#include "Guerrier.h"
#include "Kamikaze.h"
#include "Mage.h"
#include <iostream>

int main() {
	

	Personnage personnage;

	personnage.rotationGauche();
	personnage.rotationDroite();

	Guerrier guerrier;

	guerrier.avancer();
	guerrier.attaquer();

	Kamikaze kamikaze;
	kamikaze.avancer();
	kamikaze.attaquer();



	Mage mage;
	mage.avancer();
	mage.attaquer();






	return 0;
}
