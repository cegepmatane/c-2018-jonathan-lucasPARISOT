#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <iostream>

namespace std {

	class Animal {
		public:
			Animal();
			virtual ~Animal();

			string nom;

			virtual string crier();
			string nomAnimal();
			virtual string exporter();
			void importer();
	};

}

#endif
