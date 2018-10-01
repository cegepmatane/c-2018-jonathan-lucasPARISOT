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
#include <fstream>

int main() {
	
	Animal* referenceCorbeau = new Corbeau("croby");
	referenceCorbeau->crier();

	Animal* referenceChaton = new Chaton("maowy");
	referenceChaton->crier();

	Animal* referenceCreeper = new Creeper("tchyy");
	referenceCreeper->crier();

	Personnage* referencePersonnageGuerrier = new Guerrier("Bobby",20);
	referencePersonnageGuerrier->avancer();
	referencePersonnageGuerrier->attaquer();

	Personnage* referencePersonnageKamikaze = new Kamikaze("Morty",1);
	referencePersonnageKamikaze->avancer();
	referencePersonnageKamikaze->attaquer();

	Personnage* referencePersonnageMage = new Mage(*referenceChaton,"Gandalf",200);
	referencePersonnageMage->avancer();
	referencePersonnageMage->attaquer();
	referencePersonnageMage->direAnimal();

	referencePersonnageMage->rotationDroite();


	Personnage* referencePersonnage = new Personnage(*referenceCorbeau,"Peon",3);
	referencePersonnage->direAnimal();


	delete referencePersonnageGuerrier;
	delete referencePersonnageKamikaze;
	delete referencePersonnageMage;




	ifstream sourceAnimaux;
	sourceAnimaux.open("data/animaux.csv");
	string ligne;

	while(!sourceAnimaux.eof()) {
		unsigned int positionDebut=0;
		unsigned int positionFin=0;

		getline(sourceAnimaux,ligne);

		do{
			positionFin = ligne.find(";",positionDebut);
			string valeur = ligne.substr(positionDebut,positionFin-positionDebut);
			Animal* animal=new Animal(valeur);
			cout << valeur << endl;
			positionDebut=positionFin+1;
		}
		while(positionDebut!=0);

	}




	return 0;
}







