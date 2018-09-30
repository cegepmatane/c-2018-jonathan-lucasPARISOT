using namespace std;
#include "Kamikaze.h"

	Kamikaze::Kamikaze(Animal& p_animal,string p_nom,int p_pv) {
		animal=p_animal;
		nom=p_nom;
		pv=p_pv;
	}

	Kamikaze::Kamikaze(string p_nom,int p_pv) {
		nom=p_nom;
		pv=p_pv;
	}

	void Kamikaze::attaquer() {
		cout << "Tenno heika banzai !" <<endl;
	}
	void Kamikaze::avancer() {
		cout << "Allons vers notre devoir !" <<endl;
	}
