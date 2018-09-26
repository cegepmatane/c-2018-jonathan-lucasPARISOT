#ifndef GUERRIER_H_
#define GUERRIER_H_


#include <iostream>
#include "Personnage.h"

namespace std{

	class Guerrier:public Personnage{


	public:
		Guerrier();
		void attaquer();
		void avancer();
	};

}

#endif
