using namespace std;

#include "Guerrier.h"
#include "Kamikaze.h"
#include "Mage.h"
#include "Corbeau.h"
#include "Chaton.h"
#include "Creeper.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <conio.h>
#include <chrono>
#include <thread>
#include <vector>
#include <SFML/Graphics.hpp>

int main()
{

	sf::RenderWindow window(sf::VideoMode(1200, 800), "Jeu !");
	//sf::RectangleShape shapeRectangle(sf::Vector2f(800, 600));

	sf::Texture texture;

	if (!texture.loadFromFile("./data/background.png"))
	{
		cout << "File not successfully loaded" << endl;
	}

	sf::Sprite sprite;
	sprite.scale(2.4f, 2.4f);
	sprite.setTexture(texture);

	vector<Personnage*> listePersonnage;
	vector<Animal*> listeAnimal;

	int position = 0;

	Animal* referenceCorbeau = new Corbeau();
	listeAnimal.push_back(referenceCorbeau);

	Animal* referenceChaton = new Chaton();
	listeAnimal.push_back(referenceChaton);

	Animal* referenceCreeper = new Creeper();
	listeAnimal.push_back(referenceCreeper);

	Personnage* referenceGuerrier = new Guerrier();
	listePersonnage.push_back(referenceGuerrier);

	Personnage* referenceKamikaze = new Kamikaze();
	listePersonnage.push_back(referenceKamikaze);

	Personnage* referenceMage = new Mage();
	referenceMage->ajouterAnimal(*referenceChaton);
	listePersonnage.push_back(referenceMage);

	// listeAnimal.at(0)->crier(); TEST METHODE SUR UN ELEMENT

	int tour = 0;
	int touche; // Ou int
	bool gameIsRunning = true;

	string chaineAffiche = "";
	sf::Font font;
	font.loadFromFile("./data/arialbd.ttf");

	//shapeRectangle.setTextureRect(sf::IntRect(0, 0, 600, 600));

	while (window.isOpen() && gameIsRunning)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}






		// premier probleme-solution : dormir sans occuper les ressources
		this_thread::sleep_for(chrono::milliseconds(1000 / 60)); // 60 fps
		// second probleme-solution : lire les entrées sans bloquer la boucle
		if (_kbhit())
		{
			touche = _getch(); // touche 1, défile de la liste
			switch (touche)
			{
			case 27:
				window.clear();
				gameIsRunning = false;
				break;

			case 'w':
				window.clear();
				//cout << tour << endl;
				cout << endl;
				chaineAffiche = listePersonnage.at(position)->avancer();
				cout << endl;
				break;

			case 'a':
				window.clear();
				//cout << tour << endl;
				cout << endl;
				chaineAffiche = listePersonnage.at(position)->nom;
				chaineAffiche += " se decale sur la gauche !";
				break;

			case 's':
				window.clear();
				//cout << tour << endl;
				cout << endl;
				chaineAffiche = listePersonnage.at(position)->nom;
				chaineAffiche += " recule !";
				break;

			case 'd':
				window.clear();
				//cout << tour << endl;
				cout << endl;
				chaineAffiche = listePersonnage.at(position)->nom;
				chaineAffiche += " se decale sur la droite !";
				break;

			case 'e':
				window.clear();
				//cout << tour << endl;
				cout << endl;
				chaineAffiche = listePersonnage.at(position)->direNom();
				cout << endl;
				break;

			case 'r':
				window.clear();
				//cout << tour << endl;
				cout << endl;
				chaineAffiche = listePersonnage.at(position)->direAnimal();
				chaineAffiche += ", mon fidele partenaire !";
				break;

			case 'q':
				window.clear();
				//cout << tour << endl;
				cout << endl;
				chaineAffiche = "L\'echauffement est fini ! \n";
				chaineAffiche += listePersonnage.at(position)->nom;
				chaineAffiche += " se recharge en energie !";
				++(*(listePersonnage.at(position)));
				break;

			case 't':
				window.clear();
				cout << endl;
				chaineAffiche = "tour numero ";
				chaineAffiche += tour;
				break;

			case 'f':
				window.clear();
				//cout << tour << endl;
				cout << endl;
				chaineAffiche = listePersonnage.at(position)->nom;
				chaineAffiche += " a ";
				chaineAffiche += listePersonnage.at(position)->pv;
				chaineAffiche += " pv !";
				break;

			case 32: // Space
				window.clear();
				cout << endl;
				//cout << tour << endl;
				chaineAffiche = "Changement de personnage ! \n";
				position++;
				if (position > 2) {
					position = 0;
				}
				chaineAffiche += listePersonnage.at(position)->direNom();
				chaineAffiche += " entre en scene !";
				break;

			default:
				cout << "" << endl;
			}

		}
		//cout << "tour " << tour << endl;

		while (_kbhit()) {
			_getch();
		}
		tour++;

		sf::Text text(chaineAffiche, font);
		text.setCharacterSize(30);
		text.setStyle(sf::Text::Bold);
		text.setFillColor(sf::Color::White);

		window.draw(sprite);
		window.draw(text);
		//window.draw(shapeCircle);
		//window.draw(shapeRectangle);
		window.display();
	}

	ofstream fichierMonde;
	fichierMonde.open("data/monde.xml");
	fichierMonde << "<Monde>" << endl;
	fichierMonde << "<Animaux>" << endl;
	fichierMonde << listeAnimal.at(0)->exporter() << endl;
	fichierMonde << listeAnimal.at(1)->exporter() << endl;
	fichierMonde << listeAnimal.at(2)->exporter() << endl;
	fichierMonde << referenceCreeper->exporter() << endl;
	fichierMonde << "</Animaux>" << endl;
	fichierMonde << "<Personnages>" << endl;
	fichierMonde << listePersonnage.at(0)->exporter() << endl;
	fichierMonde << listePersonnage.at(1)->exporter() << endl;
	fichierMonde << listePersonnage.at(2)->exporter() << endl;
	fichierMonde << "</Personnages>" << endl;
	fichierMonde << "</Monde>" << endl;

	fichierMonde.close();

	listeAnimal.clear();
	listePersonnage.clear();

	delete referenceGuerrier;
	delete referenceKamikaze;
	delete referenceMage;

	delete referenceCorbeau;
	delete referenceChaton;
	delete referenceCreeper;


	return 0;
}