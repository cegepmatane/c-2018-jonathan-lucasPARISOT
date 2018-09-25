//============================================================================
// Name        : ProjetExemple.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

using namespace std;
#include "Personnage"
#include "Guerrier"
#include "Kamikaze"
#include "Mage"
#include <iostream>

int main() {
	

	Personnage personnage = new Personnage();

	personnage.rotationGauche();
	personnage.rotationDroite();

	personnage = new Guerrier();
	personnage.attaque();
	personnage.avance();

	Kamikaze kamikaze = new Kamikaze();
	kamikaze.attaque();
	kamikaze.avance();

	Mage mage = new Mage();
	mage.attaque();
	mage.avance();





	return 0;
}
