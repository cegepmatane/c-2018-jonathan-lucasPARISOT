#include "Personnage.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;


	Personnage::Personnage() {
		importer();
	}

	Personnage::~Personnage() {

	}


	void Personnage::ajouterAnimal(Animal& p_animal) {
		this->animal = p_animal;
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

	void Personnage::direNom() {
		cout << nom << endl;
		// Pour tester
	}

	void Personnage::direAnimal() {
		cout << this->animal.nom << endl;
		// Pour tester
	}

	string Personnage::exporter(){
		// Exporte en formal XML
		stringstream xml;
		xml << "<Personnage><nom>" << this->nom << "</nom><pv>" << this->pv << "</pv><Animal>" << this->animal.nom << "</Animal></Personnage>";

		return xml.str();
	}

	void Personnage::importer() {

		ifstream sourcePersonnage;
		sourcePersonnage.open("data/personnage.csv");
		string ligne;

		while (!sourcePersonnage.eof()) {
			unsigned int positionDebut = 0;
			unsigned int positionFin = 0;

			int compteurMot = 0;

			getline(sourcePersonnage, ligne);

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
