#ifndef GUERRIER_H_
#define GUERRIER_H_


#include <iostream>
#include "Personnage.h"

namespace std{

	class Guerrier:public Personnage{


	public:
		Guerrier();
		Guerrier(string, int, Animal);
		string attaquer();
		string avancer();
		void ajouterAnimal(Animal& p_animal);
		string exporter();
		void importer();
		Personnage& operator++();
	};

}

#endif
