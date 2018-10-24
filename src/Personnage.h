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

		virtual string attaquer();
		virtual string avancer();
		virtual string rotationGauche();
		virtual string rotationDroite();
		virtual string direNom();
		virtual string direAnimal();
		virtual string exporter();
		virtual void importer();
		virtual void ajouterAnimal(Animal& p_animal);
		virtual Personnage& operator++();
	};
}

#endif
