using namespace std;

#include <sstream>
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

	string Kamikaze::exporter(){
		// Exporte en formal XML
		stringstream xml;
		xml << "<Kamikaze><nom>" << this->nom << "</nom><pv>" << this->pv << "</pv><Animal>" << this->animal.nom << "</Animal></Kamikaze>";

		return xml.str();
	}
