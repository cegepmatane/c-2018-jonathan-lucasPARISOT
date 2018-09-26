#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <iostream>

namespace std {

	class Animal {
		public:
			Animal();
			virtual ~Animal();
			virtual void crier();
	};

}

#endif
