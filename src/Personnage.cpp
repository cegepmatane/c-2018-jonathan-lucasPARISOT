using namespace std;
#include "Personnage.h"
#include <iostream>
#include <vector>


	vector <Animal> listeAnimal;

	Personnage::Personnage(Animal animal) {

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