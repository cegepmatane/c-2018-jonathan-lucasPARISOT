#ifndef PERSONNAGE_H_
#define PERSONNAGE_H_

#include <iostream>
#include "Animal.h"

namespace std{

	class Personnage{

	public:
		Personnage(Animal animal);
		virtual ~Personnage();
		virtual void attaquer();
		virtual void avancer();
		void rotationGauche();
		void rotationDroite();

	};
}

#endif
