using namespace std;

#include <iostream>
#include <fstream>
#include <sstream>
#include "Kamikaze.h"

Kamikaze::Kamikaze() {
	importer();
}

Kamikaze::Kamikaze(string nom, int pv, Animal animal) {
	this->nom = nom;
	this->pv = pv;
	this->animal = animal;
}

void Kamikaze::attaquer() {
	cout << "Tenno heika banzai !";
}

void Kamikaze::avancer() {
	cout << "Allons vers notre devoir !";
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
			//cout << valeur << endl;
			positionDebut = positionFin + 1;
		} while (positionDebut != 0);
	}
	sourceKamikaze.close();
}

Kamikaze& Kamikaze::operator++()
{
	this->pv = this->pv + 20;
	return (*this);
}
