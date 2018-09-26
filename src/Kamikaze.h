#ifndef KAMIKAZE_H_
#define KAMIKAZE_H_

#include <iostream>
#include "Personnage.h"

namespace std{

	class Kamikaze:public Personnage {

	public:
		Kamikaze();
		void attaquer();
		void avancer();
	};

}

#endif
