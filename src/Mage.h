#ifndef MAGE_H_
#define MAGE_H_

#include <iostream>
#include "Personnage.h"

namespace std{

	class Mage:public Personnage {

	public:
		Mage();
		Mage(string,int);
		Mage(Animal& animal,string,int);
		void attaquer();
		void avancer();
	};
}

#endif
