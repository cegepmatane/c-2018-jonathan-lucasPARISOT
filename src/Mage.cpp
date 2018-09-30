#include "Mage.h"

using namespace std;

	Mage::Mage(Animal& p_animal,string p_nom,int p_pv) {
		animal=p_animal;
		nom=p_nom;
		pv=p_pv;
	}

	Mage::Mage(string p_nom,int p_pv) {
		nom=p_nom;
		pv=p_pv;
	}

	void Mage::attaquer() {
		cout << "Abracadabra !" <<endl;
	}
	void Mage::avancer() {
		cout << "Velocitas Maximum !" <<endl;
	}

