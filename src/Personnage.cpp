#include "Personnage.h"
#include <iostream>
#include <vector>

using namespace std;


	Personnage::Personnage() {

	}

	Personnage::Personnage(Animal* animal) {

	}

	Personnage::Personnage(string nom) {

	}

	Personnage::~Personnage() {

	}



	void Personnage::attaquer() {
		cout << "Le personnage attaque" << endl;
	}
	void Personnage::avancer() {
		cout << "Le personnage avance" << endl;
	}
	void Personnage::rotationGauche() {
		cout << "Gauche !" << endl;
		// Pour tester
	}
	void Personnage::rotationDroite() {
		cout << "Droite !" << endl;
		// Pour tester
	}

	void Personnage::direNom() {
		cout << nom << endl;
		// Pour tester
	}

	void Personnage::direAnimal() {
		cout << this->animal.nom << endl;
		// Pour tester
	}
