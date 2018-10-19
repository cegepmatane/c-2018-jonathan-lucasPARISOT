#include "Mage.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

	Mage::Mage() {
		importer();
	}

	void Mage::attaquer() {
		cout << "Abracadabra !" <<endl;
	}
	void Mage::avancer() {
		cout << "Velocitas Maximum !" <<endl;
	}

	string Mage::exporter(){
		// Exporte en formal XML
		stringstream xml;
		xml << "<Mage><nom>" << this->nom << "</nom><pv>" << this->pv << "</pv><Animal>" << this->animal.nom << "</Animal></Mage>";

		return xml.str();
	}

	void Mage::ajouterAnimal(Animal& p_animal) {
		this->animal = p_animal;
	}

	void Mage::importer() {

		ifstream sourceMage;
		sourceMage.open("data/mage.csv");
		string ligne;

		while (!sourceMage.eof()) {
			unsigned int positionDebut = 0;
			unsigned int positionFin = 0;

			int compteurMot = 0;

			getline(sourceMage, ligne);

			do {
				positionFin = ligne.find(";", positionDebut);
				string valeur = ligne.substr(positionDebut, positionFin - positionDebut);
				compteurMot++;
				if (compteurMot == 1) {
					this->nom = valeur;
				}
				else if (compteurMot == 2) {
					this->pv = stoi(valeur);
				}
				cout << valeur << endl;
				positionDebut = positionFin + 1;
			} while (positionDebut != 0);
		}

	}

