#include "Animal.h"

using namespace std;

	Animal::Animal() {
		nom="";
	}

	Animal::Animal(string p_nom) {
		nom=p_nom;
	}

	Animal::~Animal() {
	}

	void Animal::crier(){
		cout << "crier !" <<endl;
	}

	void Animal::nomAnimal(){
		cout << nom <<endl;
	}

