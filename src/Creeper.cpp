#include "Creeper.h"
#include <sstream>

namespace std {

	Creeper::Creeper(string p_nom) {
		nom=p_nom;
	}

	Creeper::~Creeper() {
	}

	void Creeper::crier(){
			cout << "Tchhhhhhh !" <<endl;
	}

	string Creeper::exporter(){
		// Exporte en formal XML
		stringstream xml;
		xml << "<Creeper><nom>" << this->nom << "</nom></Creeper>";

		return xml.str();
	}
}
