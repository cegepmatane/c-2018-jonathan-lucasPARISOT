#include "Corbeau.h"

using namespace std;

	Corbeau::Corbeau(string p_nom) {
		nom=p_nom;
	}

	Corbeau::~Corbeau() {
	}

	void Corbeau::crier(){
		cout << "Croaaa !" <<endl;
	}

