#ifndef CORBEAU_H_
#define CORBEAU_H_

#include <iostream>
#include "Animal.h"

namespace std {

	class Corbeau:public Animal {
		public:
			Corbeau();
			virtual ~Corbeau();
			string crier();
			string exporter();
			void importer();
			string espece();
	};

}

#endif
