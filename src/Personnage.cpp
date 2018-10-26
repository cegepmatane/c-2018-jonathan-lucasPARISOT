#include "Personnage.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;


Personnage::Personnage() {
	importer();
	this->nom = "ALED";
}

Personnage::~Personnage() {

}


void Personnage::ajouterAnimal(Animal* p_animal) {
	this->animal = p_animal;
}

Personnage & std::Personnage::operator++()
{
	return *this;
}


string Personnage::attaquer() {
	return "Le personnage attaque";
}
string Personnage::avancer() {
	return "Le personnage avance";
}
string Personnage::rotationGauche() {
	return "Gauche !";
	// Pour tester
}
string Personnage::rotationDroite() {
	return "Droite !";
	// Pour tester
}

string Personnage::direNom() {
	return "Mon nom est " + this->nom;
	// Pour tester
}

string Personnage::exporter(){
	// Exporte en formal XML
	stringstream xml;
	xml << "<Personnage><nom>" << this->nom << "</nom><pv>" << this->pv << "</pv><Animal>" << this->animal->nom << "</Animal></Personnage>";

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
			//cout << valeur << endl;
			positionDebut = positionFin + 1;
		} while (positionDebut != 0);
	}
	sourcePersonnage.close();
}