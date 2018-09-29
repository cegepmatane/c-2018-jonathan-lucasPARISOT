#ifndef PERSONNAGE_H_
#define PERSONNAGE_H_

#include <iostream>
#include "Animal.h"

namespace std{

	class Personnage{



	public:

		Personnage();
		Personnage(Animal* animal);
		Personnage(string nom);
		virtual ~Personnage();

		string nom;
		Animal animal;

		virtual void attaquer();
		virtual void avancer();
		void rotationGauche();
		void rotationDroite();
		void direNom();
		void direAnimal();

	};
}

#endif
