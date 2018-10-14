#ifndef CHATON_H_
#define CHATON_H_

#include <iostream>
#include "Animal.h"

namespace std {

	class Chaton:public Animal {
		public:
			Chaton(string);
			virtual ~Chaton();
			void crier();
			string exporter();
	};

	}

#endif
