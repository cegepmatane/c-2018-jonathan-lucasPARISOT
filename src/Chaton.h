#ifndef CHATON_H_
#define CHATON_H_

#include <iostream>
#include "Animal.h"

namespace std {

	class Chaton:public Animal {
		public:
			Chaton();
			virtual ~Chaton();
			string crier();
			string exporter();
			void importer();
	};

	}

#endif
