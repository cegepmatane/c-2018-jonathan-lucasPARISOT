#include "Guerrier.h"

using namespace std;

	Guerrier::Guerrier(Animal& p_animal,string p_nom,int p_pv) {
		animal=p_animal;
		nom=p_nom;
		pv=p_pv;
	}

	Guerrier::Guerrier(string p_nom,int p_pv) {
		nom=p_nom;
		pv=p_pv;
	}
	void Guerrier::attaquer() {
		cout << "A l'attaque !" <<endl;
	}
	void Guerrier::avancer() {
		cout << "Allons vers l'ennemi !" <<endl;
	}


