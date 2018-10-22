#ifndef PERSONNAGE_H_
#define PERSONNAGE_H_

#include <iostream>
#include "Animal.h"

namespace std{

	class Personnage{

	public:

		Personnage();
		virtual ~Personnage();

		string nom;
		int pv;
		Animal animal;

		virtual void attaquer();
		virtual void avancer();
		virtual void rotationGauche();
		virtual void rotationDroite();
		virtual void direNom();
		virtual void direAnimal();
		virtual string exporter();
		virtual void importer();
		virtual void ajouterAnimal(Animal& p_animal);
		virtual Personnage& operator++();
	};
}

#endif
