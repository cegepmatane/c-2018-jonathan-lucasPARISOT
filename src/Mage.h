#ifndef MAGE_H_
#define MAGE_H_

#include <iostream>
#include "Personnage.h"

namespace std{

	class Mage:public Personnage {

	public:
		Mage();
		Mage(string, int, Animal);
		void attaquer();
		void avancer();
		string exporter();
		void importer();
		void ajouterAnimal(Animal& p_animal);
		Mage& operator++();
	};
}

#endif
