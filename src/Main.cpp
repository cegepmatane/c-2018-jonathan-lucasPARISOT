using namespace std;


#include "Guerrier.h"
#include "Kamikaze.h"
#include "Mage.h"
#include "Corbeau.h"
#include "Chaton.h"
#include "Creeper.h"
#include "Tools.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <conio.h>
#include <chrono>
#include <thread>


int main() {

	Tools* tools = new Tools();
	tools->importer();

	Animal* referenceCorbeau = new Corbeau("croby");

	Animal* referenceChaton = new Chaton("maowy");

	Animal* referenceCreeper = new Creeper("tchyy");

	Personnage* referencePersonnageGuerrier = new Guerrier("Bobby", 20);

	Personnage* referencePersonnageKamikaze = new Kamikaze("Morty", 1);

	Personnage* referencePersonnageMage = new Mage(*referenceChaton, "Gandalf", 200);

	//Personnage* referencePersonnage = new Personnage(*referenceCorbeau, "Peon", 3); Test ajout personnage avec animal dans le xml: r�ussi

	int tour = 0;
	int touche; // Ou int
	bool gameIsRunning = true;
	while (gameIsRunning)
	{
		// premier probleme-solution : dormir sans occuper les ressources
		this_thread::sleep_for(chrono::milliseconds(1000 / 60)); // 60 fps
		// second probleme-solution : lire les entr�es sans bloquer la boucle
		if (_kbhit())
		{
			touche = _getch(); // touche 1, d�file de la liste
			cout << "touche " << touche << " " << tour << endl;
			switch (touche)
			{
			case 27:
				gameIsRunning = false;
				break;
			case 'w':
				cout << "up" << endl;
				break;
			case 'a':
				cout << "left" << endl;
				break;
			case 's':
				cout << "down" << endl;
				break;
			case 'd':
				cout << "right" << endl;
				break;
			}
		}
		//cout << "tour " << tour << endl;

		while (_kbhit()) {
			_getch();
		}
		tour++;
	}

	ofstream fichierMonde;
	fichierMonde.open("data/monde.xml");
	fichierMonde << "<Monde>" << endl;
	fichierMonde << "<Animaux>" << endl;
	fichierMonde << referenceCorbeau->exporter() << endl;
	fichierMonde << referenceChaton->exporter() << endl;
	fichierMonde << referenceCreeper->exporter() << endl;
	fichierMonde << "</Animaux>" << endl;
	fichierMonde << "<Personnages>" << endl;
	fichierMonde << referencePersonnageGuerrier->exporter() << endl;
	fichierMonde << referencePersonnageKamikaze->exporter() << endl;
	fichierMonde << referencePersonnageMage->exporter() << endl;
	fichierMonde << "</Personnages>" << endl;
	fichierMonde << "</Monde>" << endl;

	fichierMonde.close();

	delete referencePersonnageGuerrier;
	delete referencePersonnageKamikaze;
	delete referencePersonnageMage;

	delete referenceCorbeau;
	delete referenceChaton;
	delete referenceCreeper;


	return 0;
}
