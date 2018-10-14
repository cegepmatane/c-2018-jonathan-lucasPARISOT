#include "Animal.h"
#include <sstream>

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

	string Animal::exporter(){
		// Exporte en formal XML
		stringstream xml;
		xml << "<Animal><nom>" << this->nom << "</nom></Animal>";

		return xml.str();
	}

