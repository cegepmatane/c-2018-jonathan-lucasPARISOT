#include "Chaton.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

	Chaton::Chaton() {
		importer();
	}

	Chaton::~Chaton() {
	}

	void Chaton::crier(){
		cout << "Miaooooo !";
	}

	string Chaton::exporter(){
		// Exporte en formal XML
		stringstream xml;
		xml << "<Chaton><nom>" << this->nom << "</nom></Chaton>";

		return xml.str();
	}

	void Chaton::importer() {
		ifstream sourceChaton;
		sourceChaton.open("data/chaton.csv");
		string ligne;

		while (!sourceChaton.eof()) {
			unsigned int positionDebut = 0;
			unsigned int positionFin = 0;

			int compteurMot = 0;

			getline(sourceChaton, ligne);

			do {
				positionFin = ligne.find(";", positionDebut);
				string valeur = ligne.substr(positionDebut, positionFin - positionDebut);
				this->nom = valeur;
				//cout << valeur << endl;
				positionDebut = positionFin + 1;
			} while (positionDebut != 0);

		}
		sourceChaton.close();
	}

