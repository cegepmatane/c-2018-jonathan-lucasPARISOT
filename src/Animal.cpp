#include "Animal.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

	Animal::Animal() {
		importer();
	}

	Animal::~Animal() {
	}

	string Animal::crier(){
		return "crier !";
	}

	string Animal::nomAnimal(){
		return "Son nom est " + this->nom;
	}

	string Animal::exporter(){
		// Exporte en formal XML
		stringstream xml;
		xml << "<Animal><nom>" << this->nom << "</nom></Animal>";

		return xml.str();
	}

	void Animal::importer() {
		ifstream sourceAnimaux;
		sourceAnimaux.open("data/animaux.csv");
		string ligne;

		while (!sourceAnimaux.eof()) {
			unsigned int positionDebut = 0;
			unsigned int positionFin = 0;

			getline(sourceAnimaux, ligne);

			do {
				positionFin = ligne.find(";", positionDebut);
				string valeur = ligne.substr(positionDebut, positionFin - positionDebut);
				this->nom = valeur;
				cout << valeur << endl;
				positionDebut = positionFin + 1;
			} while (positionDebut != 0);

		}
		sourceAnimaux.close();
	}

