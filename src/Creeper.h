#ifndef CREEPER_H_
#define CREEPER_H_

#include <iostream>
#include "Animal.h"

namespace std {

	class Creeper {
		public:
			Creeper();
			virtual ~Creeper();
			void crier();
	};

}

#endif
