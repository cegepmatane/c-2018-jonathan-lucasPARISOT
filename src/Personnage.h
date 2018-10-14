#ifndef PERSONNAGE_H_
#define PERSONNAGE_H_

#include <iostream>
#include "Animal.h"

namespace std{

	class Personnage{



	public:

		Personnage();
		Personnage(Animal& animal,string nom,int pv);
		Personnage(string nom,int pv);
		virtual ~Personnage();

		string nom;
		int pv;
		Animal animal;

		virtual void attaquer();
		virtual void avancer();
		void rotationGauche();
		void rotationDroite();
		void direNom();
		void direAnimal();
		virtual string exporter();

	};
}

#endif
