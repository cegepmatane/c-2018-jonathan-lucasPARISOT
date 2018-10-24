#include "Creeper.h"
#include <iostream>
#include <fstream>
#include <sstream>

namespace std {

	Creeper::Creeper() {
		importer();
	}

	Creeper::~Creeper() {
	}

	string Creeper::crier(){
			return "Tchhhhhhh !";
	}

	string Creeper::exporter(){
		// Exporte en formal XML
		stringstream xml;
		xml << "<Creeper><nom>" << this->nom << "</nom></Creeper>";

		return xml.str();
	}

	void Creeper::importer() {

		ifstream sourceCreeper;
		sourceCreeper.open("data/creeper.csv");
		string ligne;

		while (!sourceCreeper.eof()) {
			unsigned int positionDebut = 0;
			unsigned int positionFin = 0;

			int compteurMot = 0;

			getline(sourceCreeper, ligne);

			do {
				positionFin = ligne.find(";", positionDebut);
				string valeur = ligne.substr(positionDebut, positionFin - positionDebut);
				this->nom = valeur;
				//cout << valeur << endl;
				positionDebut = positionFin + 1;
			} while (positionDebut != 0);

		}
		sourceCreeper.close();
	}
}
