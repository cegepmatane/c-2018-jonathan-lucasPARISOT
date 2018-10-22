#ifndef KAMIKAZE_H_
#define KAMIKAZE_H_

#include <iostream>
#include "Personnage.h"

namespace std{

	class Kamikaze:public Personnage {

	public:
		Kamikaze();
		Kamikaze(string, int, Animal);
		void attaquer();
		void avancer();
		string exporter();
		void importer();
		void ajouterAnimal(Animal& p_animal);
		Kamikaze& operator++();
	};

}

#endif
