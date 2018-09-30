#include "Chaton.h"

using namespace std;

	Chaton::Chaton(string p_nom) {
		nom=p_nom;
	}

	Chaton::~Chaton() {
	}

	void Chaton::crier(){
		cout << "Miaooooo !" <<endl;
	}

