#include "Guerrier.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Guerrier::Guerrier() {
	importer();
}

Guerrier::Guerrier(string nom, int pv, Animal animal) {
	this-> nom = nom;
	this-> pv = pv;
	this->animal = animal;
}

string Guerrier::attaquer() {
	return "A l'attaque !";
}

string Guerrier::avancer() {
	return "Allons vers l'ennemi !";
}

string Guerrier::exporter(){
	// Exporte en formal XML
	stringstream xml;
	xml << "<Guerrier><nom>" << this->nom << "</nom><pv>" << this->pv << "</pv><Animal>" << this->animal.nom << "</Animal></Guerrier>";

	return xml.str();
}

void Guerrier::ajouterAnimal(Animal& p_animal) {
	this->animal = p_animal;
}

void Guerrier::importer() {

	ifstream sourceGuerrier;
	sourceGuerrier.open("data/guerrier.csv");
	string ligne;

	while (!sourceGuerrier.eof()) {
		unsigned int positionDebut = 0;
		unsigned int positionFin = 0;

		int compteurMot = 0;

		getline(sourceGuerrier, ligne);

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
	sourceGuerrier.close();

}

Personnage& Guerrier::operator++()
{
	this->pv = this->pv + 40;
	return (*this);
}
