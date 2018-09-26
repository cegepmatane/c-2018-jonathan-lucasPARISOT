#ifndef PERSONNAGE_H_
#define PERSONNAGE_H_

#include <iostream>

namespace std{

	class Personnage{

	public:
		Personnage();
		virtual ~Personnage();
		virtual void attaquer();
		virtual void avancer();
		void rotationGauche();
		void rotationDroite();

	};
}

#endif
