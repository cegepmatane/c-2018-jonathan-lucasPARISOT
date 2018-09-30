#include "Creeper.h"

namespace std {

	Creeper::Creeper(string p_nom) {
		nom=p_nom;
	}

	Creeper::~Creeper() {
	}

	void Creeper::crier(){
			cout << "Tchhhhhhh !" <<endl;
	}
}
