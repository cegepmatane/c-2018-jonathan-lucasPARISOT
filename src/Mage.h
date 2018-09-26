#ifndef MAGE_H_
#define MAGE_H_

#include <iostream>
#include "Personnage.h"

namespace std{

	class Mage:public Personnage {

	public:
		Mage();
		void attaquer();
		void avancer();
	};
}

#endif
