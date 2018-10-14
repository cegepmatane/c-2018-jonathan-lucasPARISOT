#include "Personnage.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;


	Personnage::Personnage() {
		nom="";
		pv=0;
	}

	Personnage::Personnage(Animal& p_animal,string p_nom,int p_pv) {
		animal=p_animal;
		nom=p_nom;
		pv=p_pv;
	}

	Personnage::Personnage(string p_nom,int p_pv) {
		nom=p_nom;
		pv=p_pv;
	}

	Personnage::~Personnage() {

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
