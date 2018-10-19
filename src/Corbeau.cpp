#include "Corbeau.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

	Corbeau::Corbeau() {
		importer();
	}

	Corbeau::~Corbeau() {
	}

	void Corbeau::crier(){
		cout << "Croaaa !" <<endl;
	}

	string Corbeau::exporter(){
		// Exporte en formal XML
		stringstream xml;
		xml << "<Corbeau><nom>" << this->nom << "</nom></Corbeau>";

		return xml.str();
	}

	void Corbeau::importer() {

		ifstream sourceCorbeau;
		sourceCorbeau.open("data/corbeau.csv");
		string ligne;

		while (!sourceCorbeau.eof()) {
			unsigned int positionDebut = 0;
			unsigned int positionFin = 0;

			int compteurMot = 0;

			getline(sourceCorbeau, ligne);

			do {
				positionFin = ligne.find(";", positionDebut);
				string valeur = ligne.substr(positionDebut, positionFin - positionDebut);
				this->nom = valeur;
				cout << valeur << endl;
				positionDebut = positionFin + 1;
			} while (positionDebut != 0);

		}

		cout << endl;

	}

