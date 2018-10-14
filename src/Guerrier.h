#ifndef GUERRIER_H_
#define GUERRIER_H_


#include <iostream>
#include "Personnage.h"

namespace std{

	class Guerrier:public Personnage{


	public:
		Guerrier();
		Guerrier(Animal& animal,string,int);
		Guerrier(string,int);
		void attaquer();
		void avancer();
		string exporter();
	};

}

#endif
