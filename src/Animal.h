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
			virtual string exporter();
			void importer();
			virtual string espece();
	};

}

#endif
