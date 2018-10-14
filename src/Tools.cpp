#include "Tools.h"

#include <iostream>
#include <fstream>

namespace std {

Tools::Tools() {
	// TODO Auto-generated constructor stub

}

Tools::~Tools() {
	// TODO Auto-generated destructor stub
}

void Tools::importer(){
	ifstream sourceAnimaux;
	sourceAnimaux.open("data/animaux.csv");
	string ligne;

	while(!sourceAnimaux.eof()) {
		unsigned int positionDebut=0;
		unsigned int positionFin=0;

		getline(sourceAnimaux,ligne);

		do{
			positionFin = ligne.find(";",positionDebut);
			string valeur = ligne.substr(positionDebut,positionFin-positionDebut);
			Animal* animal=new Animal(valeur);
			cout << valeur << endl;
			positionDebut=positionFin+1;
		}
		while(positionDebut!=0);

	}

}

} /* namespace std */
