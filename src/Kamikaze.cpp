using namespace std;

#include <iostream>
#include <fstream>
#include <sstream>
#include "Kamikaze.h"

	Kamikaze::Kamikaze() {
		importer();
	}

	void Kamikaze::attaquer() {
		cout << "Tenno heika banzai !" <<endl;
	}
	void Kamikaze::avancer() {
		cout << "Allons vers notre devoir !" <<endl;
	}

	void Kamikaze::ajouterAnimal(Animal& p_animal) {
		this->animal = p_animal;
	}

	string Kamikaze::exporter(){
		// Exporte en formal XML
		stringstream xml;
		xml << "<Kamikaze><nom>" << this->nom << "</nom><pv>" << this->pv << "</pv><Animal>" << this->animal.nom << "</Animal></Kamikaze>";

		return xml.str();
	}

	void Kamikaze::importer() {

		ifstream sourceKamikaze;
		sourceKamikaze.open("data/kamikaze.csv");
		string ligne;

		while (!sourceKamikaze.eof()) {
			unsigned int positionDebut = 0;
			unsigned int positionFin = 0;

			int compteurMot = 0;

			getline(sourceKamikaze, ligne);

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

		cout << endl;

	}
