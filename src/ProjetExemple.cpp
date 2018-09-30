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
#include "Corbeau.h"
#include "Chaton.h"
#include "Creeper.h"
#include <iostream>

int main() {
	
	Animal* referenceCorbeau = new Corbeau("croby");
	referenceCorbeau->crier();

	Animal* referenceChaton = new Chaton("maowy");
	referenceChaton->crier();

	Animal* referenceCreeper = new Creeper("tchyy");
	referenceCreeper->crier();

	Personnage* referencePersonnageGuerrier = new Guerrier();
	referencePersonnageGuerrier->avancer();
	referencePersonnageGuerrier->attaquer();

	Personnage* referencePersonnageKamikaze = new Kamikaze();
	referencePersonnageKamikaze->avancer();
	referencePersonnageKamikaze->attaquer();

	Personnage* referencePersonnageMage = new Mage();
	referencePersonnageMage->avancer();
	referencePersonnageMage->attaquer();

	referencePersonnageMage->rotationDroite();


	Personnage* referencePersonnage = new Personnage(*referenceCorbeau);
	referencePersonnage->direAnimal();

	delete referencePersonnageGuerrier;
	delete referencePersonnageKamikaze;
	delete referencePersonnageMage;
	return 0;
}
