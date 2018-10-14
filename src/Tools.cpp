#include "Tools.h"

#include <iostream>
#include <fstream>

namespace std {

Tools::Tools() {
	// TODO Auto-generated constructor stub

}

Tools::~Tools() {
	// TODO Auto-generated destructor stub
}

void Tools::importer(){

	importerAnimaux();
	importerChaton();
	importerCorbeau();
	importerCreeper();
	importerPersonnage();
	importerGuerrier();
	importerKamikaze();
	importerMage();


	}

void Tools::importerAnimaux(){

	ifstream sourceAnimaux;
	sourceAnimaux.open("data/animaux.csv");
	string ligne;

	while(!sourceAnimaux.eof()) {
		unsigned int positionDebut=0;
		unsigned int positionFin=0;

		getline(sourceAnimaux,ligne);

		do{
			positionFin = ligne.find(";",positionDebut);
			string valeur = ligne.substr(positionDebut,positionFin-positionDebut);
			Animal* animal=new Animal(valeur);
			cout << valeur << endl;
			positionDebut=positionFin+1;
		}
		while(positionDebut!=0);

	}

	cout << endl;

}

void Tools::importerChaton(){

	ifstream sourceChaton;
	sourceChaton.open("data/chaton.csv");
	string ligne;

	while(!sourceChaton.eof()) {
		unsigned int positionDebut=0;
		unsigned int positionFin=0;

		string valeurNom;
		int pv;
		int compteurMot=0;

		getline(sourceChaton,ligne);

		do{
			positionFin = ligne.find(";",positionDebut);
			string valeur = ligne.substr(positionDebut,positionFin-positionDebut);
			Chaton* chaton=new Chaton(valeur);
			cout << valeur << endl;
			positionDebut=positionFin+1;
		}
		while(positionDebut!=0);

	}

	cout << endl;

}

void Tools::importerCorbeau(){

	ifstream sourceCorbeau;
	sourceCorbeau.open("data/corbeau.csv");
	string ligne;

	while(!sourceCorbeau.eof()) {
		unsigned int positionDebut=0;
		unsigned int positionFin=0;

		string valeurNom;
		int pv;
		int compteurMot=0;

		getline(sourceCorbeau,ligne);

		do{
			positionFin = ligne.find(";",positionDebut);
			string valeur = ligne.substr(positionDebut,positionFin-positionDebut);
			Corbeau* corbeau=new Corbeau(valeur);
			cout << valeur << endl;
			positionDebut=positionFin+1;
		}
		while(positionDebut!=0);

	}

	cout << endl;

}

void Tools::importerCreeper(){

	ifstream sourceCreeper;
	sourceCreeper.open("data/creeper.csv");
	string ligne;

	while(!sourceCreeper.eof()) {
		unsigned int positionDebut=0;
		unsigned int positionFin=0;

		string valeurNom;
		int pv;
		int compteurMot=0;

		getline(sourceCreeper,ligne);

		do{
			positionFin = ligne.find(";",positionDebut);
			string valeur = ligne.substr(positionDebut,positionFin-positionDebut);
			Creeper* creeper=new Creeper(valeur);
			cout << valeur << endl;
			positionDebut=positionFin+1;
		}
		while(positionDebut!=0);

		}

	cout << endl;

}

void Tools::importerPersonnage(){

	ifstream sourcePersonnage;
	sourcePersonnage.open("data/personnage.csv");
	string ligne;

	while(!sourcePersonnage.eof()) {
		unsigned int positionDebut=0;
		unsigned int positionFin=0;

		string valeurNom;
		int pv;
		int compteurMot=0;

		getline(sourcePersonnage,ligne);

		do{
			positionFin = ligne.find(";",positionDebut);
			string valeur = ligne.substr(positionDebut,positionFin-positionDebut);
			compteurMot++;
			if(compteurMot==1){
				valeurNom=valeur;
			}
			else if(compteurMot==2){
				pv=stoi(valeur);
				Personnage* personnage = new Personnage(valeurNom,pv);
			}
			cout << valeur << endl;
			positionDebut=positionFin+1;
		}
		while(positionDebut!=0);
		}

	cout << endl;

}

void Tools::importerGuerrier(){

	ifstream sourceGuerrier;
	sourceGuerrier.open("data/guerrier.csv");
	string ligne;

	while(!sourceGuerrier.eof()) {
		unsigned int positionDebut=0;
		unsigned int positionFin=0;

		string valeurNom;
		int pv;
		int compteurMot=0;

		getline(sourceGuerrier,ligne);

		do{
			positionFin = ligne.find(";",positionDebut);
			string valeur = ligne.substr(positionDebut,positionFin-positionDebut);
			compteurMot++;
			if(compteurMot==1){
				valeurNom=valeur;
			}
			else if(compteurMot==2){
				pv=stoi(valeur);
				Guerrier* guerrier = new Guerrier(valeurNom,pv);
			}
			cout << valeur << endl;
			positionDebut=positionFin+1;
		}
		while(positionDebut!=0);
		}

cout << endl;

}

void Tools::importerKamikaze(){

	ifstream sourceKamikaze;
	sourceKamikaze.open("data/kamikaze.csv");
	string ligne;

	while(!sourceKamikaze.eof()) {
		unsigned int positionDebut=0;
		unsigned int positionFin=0;

		string valeurNom;
		int pv;
		int compteurMot=0;

		getline(sourceKamikaze,ligne);

		do{
			positionFin = ligne.find(";",positionDebut);
			string valeur = ligne.substr(positionDebut,positionFin-positionDebut);
			compteurMot++;
			if(compteurMot==1){
				valeurNom=valeur;
			}
			else if(compteurMot==2){
				pv=stoi(valeur);
				Kamikaze* kamikaze = new Kamikaze(valeurNom,pv);
			}
			cout << valeur << endl;
			positionDebut=positionFin+1;
			}
		while(positionDebut!=0);
		}

	cout << endl;

}

void Tools::importerMage(){

	ifstream sourceMage;
	sourceMage.open("data/mage.csv");
	string ligne;

	while(!sourceMage.eof()) {
		unsigned int positionDebut=0;
		unsigned int positionFin=0;

		string valeurNom;
		int pv;
		int compteurMot=0;

		getline(sourceMage,ligne);

		do{
			positionFin = ligne.find(";",positionDebut);
			string valeur = ligne.substr(positionDebut,positionFin-positionDebut);
			compteurMot++;
			if(compteurMot==1){
				valeurNom=valeur;
			}
			else if(compteurMot==2){
				pv=stoi(valeur);
				Guerrier* guerrier = new Guerrier(valeurNom,pv);
			}
			cout << valeur << endl;
			positionDebut=positionFin+1;
			}
		while(positionDebut!=0);
		}

}


} /* namespace std */
