/*
 * tools.h
 *
 *  Created on: 5 oct. 2018
 *      Author: lucas
 */

#ifndef TOOLS_H_
#define TOOLS_H_

#include "Animal.h"
#include "Chaton.h"
#include "Corbeau.h"
#include "Creeper.h"
#include "Personnage.h"
#include "Guerrier.h"
#include "Kamikaze.h"
#include "Mage.h"

namespace std {

class Tools {
public:
	Tools();
	virtual ~Tools();
	void importer();
	void importerAnimaux();
	void importerChaton();
	void importerCreeper();
	void importerCorbeau();
	void importerPersonnage();
	void importerGuerrier();
	void importerMage();
	void importerKamikaze();
};

} /* namespace std */

#endif /* TOOLS_H_ */
