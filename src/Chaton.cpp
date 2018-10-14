#include "Chaton.h"
#include <sstream>

using namespace std;

	Chaton::Chaton(string p_nom) {
		nom=p_nom;
	}

	Chaton::~Chaton() {
	}

	void Chaton::crier(){
		cout << "Miaooooo !" <<endl;
	}

	string Chaton::exporter(){
		// Exporte en formal XML
		stringstream xml;
		xml << "<Chaton><nom>" << this->nom << "</nom></Chaton>";

		return xml.str();
	}

