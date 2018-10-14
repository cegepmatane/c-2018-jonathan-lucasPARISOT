#include "Corbeau.h"
#include <sstream>

using namespace std;

	Corbeau::Corbeau(string p_nom) {
		nom=p_nom;
	}

	Corbeau::~Corbeau() {
	}

	void Corbeau::crier(){
		cout << "Croaaa !" <<endl;
	}

	string Corbeau::exporter(){
		// Exporte en formal XML
		stringstream xml;
		xml << "<Corbeau><nom>" << this->nom << "</nom></Corbeau>";

		return xml.str();
	}

