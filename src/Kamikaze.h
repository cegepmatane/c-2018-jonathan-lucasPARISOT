#ifndef KAMIKAZE_H_
#define KAMIKAZE_H_

#include <iostream>
#include "Personnage.h"

namespace std{

	class Kamikaze:public Personnage {

	public:
		Kamikaze();
		Kamikaze(Animal& animal,string,int);
		Kamikaze(string,int);
		void attaquer();
		void avancer();
	};

}

#endif
