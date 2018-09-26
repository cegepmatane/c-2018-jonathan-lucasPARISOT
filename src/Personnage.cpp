using namespace std;
#include "Personnage.h"
#include <iostream>


	Personnage::Personnage() {

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
