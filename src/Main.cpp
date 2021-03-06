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
	sf::RectangleShape shapeRectangle(sf::Vector2f(1200, 100));
	shapeRectangle.setFillColor(sf::Color::Black);

	sf::Texture textureBackground;
	sf::Texture textureGuerrier;
	sf::Texture textureKamikaze;
	sf::Texture textureMage;
	sf::Texture textureAnimal;
	sf::Texture textureCorbeau;
	sf::Texture textureCreeper;
	sf::Texture textureVide;
	textureVide.create(50, 50);

	if (!textureBackground.loadFromFile("./data/background.png"))
	{
		cout << "File not successfully loaded" << endl;
	}

	if (!textureGuerrier.loadFromFile("./data/guerrier.jpg"))
	{
		cout << "File not successfully loaded" << endl;
	}

	if (!textureKamikaze.loadFromFile("./data/kamikaze.jpg"))
	{
		cout << "File not successfully loaded" << endl;
	}

	if (!textureMage.loadFromFile("./data/mage.jpg"))
	{
		cout << "File not successfully loaded" << endl;
	}

	int position = 0;
	int positionAnimal = 0;

	vector<Personnage*> listePersonnage;
	vector<Animal*> listeAnimal;
	vector<sf::Texture> listeTexture;

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
	referenceMage->ajouterAnimal(referenceChaton);
	
	listePersonnage.push_back(referenceMage);
	listeTexture.push_back(textureGuerrier);
	listeTexture.push_back(textureKamikaze);
	listeTexture.push_back(textureMage);

	sf::Sprite spriteBackground;
	spriteBackground.scale(2.4f, 2.4f);
	spriteBackground.setTexture(textureBackground);

	sf::Sprite spriteJoueur;
	spriteJoueur.setTexture(listeTexture.at(position));
	spriteJoueur.setPosition(550.0f,600.0f);

	sf::Sprite spriteAnimal;
	spriteAnimal.setPosition(1000.0f, 25.0f);
	spriteAnimal.setTexture(textureVide);
	spriteAnimal.setColor(sf::Color::White);

	sf::Vector2f* vecteurHaut = new sf::Vector2f(0, -50);
	sf::Vector2f* vecteurBas = new sf::Vector2f(0, 50);
	sf::Vector2f* vecteurDroite = new sf::Vector2f(50, 0);
	sf::Vector2f* vecteurGauche = new sf::Vector2f(-50, 0);

	string chaineAffiche = "";
	sf::Font font;
	font.loadFromFile("./data/arialbd.ttf");

	int tour = 0;
	int touche;
	bool gameIsRunning = true;
	while (window.isOpen() && gameIsRunning)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		this_thread::sleep_for(chrono::milliseconds(1000 / 60));
		if (_kbhit())
		{
			touche = _getch();
			switch (touche)
			{
			case 27:
				gameIsRunning = false;
				break;

			case 'W':
			case 'w':
				cout << endl;
				chaineAffiche = listePersonnage.at(position)->avancer();
				cout << endl;
				spriteJoueur.move(*vecteurHaut);
				break;

			case 'A':
			case 'a':
				cout << endl;
				chaineAffiche = listePersonnage.at(position)->nom;
				chaineAffiche += " se decale sur la gauche !";
				spriteJoueur.move(*vecteurGauche);
				break;

			case 'S':
			case 's':
				cout << endl;
				chaineAffiche = listePersonnage.at(position)->nom;
				chaineAffiche += " recule !";
				spriteJoueur.move(*vecteurBas);
				break;

			case 'D':
			case 'd':
				cout << endl;
				chaineAffiche = listePersonnage.at(position)->nom;
				chaineAffiche += " se decale sur la droite !";
				spriteJoueur.move(*vecteurDroite);
				break;
			
			case 'G':
			case 'g':
				cout << endl;
				chaineAffiche = listePersonnage.at(position)->direNom();
				cout << endl;
				break;

			case 'R':
			case 'r':
				if (!listePersonnage.at(position)->animal == NULL) {
					chaineAffiche = listePersonnage.at(position)->animal->nom;
					chaineAffiche += ", mon fidele partenaire !";
				}
				else {
					chaineAffiche = "Mon compagnon n'est pas encore ici !";
					spriteAnimal.setTexture(textureVide);
				}
				break;

			case 'Q':
			case 'q':
				cout << endl;
				chaineAffiche = "L\'echauffement est fini ! \n";
				chaineAffiche += listePersonnage.at(position)->nom;
				chaineAffiche += " se recharge en energie !";
				++(*(listePersonnage.at(position)));
				break;

			case 'T':
			case 't':
				cout << endl;
				chaineAffiche = "tour numero ";
				chaineAffiche += to_string(tour);
				break;

			case 'F':
			case 'f':
				cout << endl;
				chaineAffiche = listePersonnage.at(position)->nom;
				chaineAffiche += " a ";
				chaineAffiche += to_string(listePersonnage.at(position)->pv);
				chaineAffiche += " pv !";
				break;

			case 'E':
			case 'e':
				cout << endl;
				chaineAffiche = listePersonnage.at(position)->attaquer();
				cout << endl;
				break;

			case 'Z':
			case 'z':
				if (!listePersonnage.at(position)->animal == NULL) {
					chaineAffiche = listePersonnage.at(position)->animal->crier();
				}
				else {
					spriteAnimal.setTexture(textureVide);
				}
				break;

			case 'C':
			case 'c':
				cout << endl;
				chaineAffiche = "Nouveau compagnon ! \n";
				positionAnimal++;
				if (positionAnimal > 2) {
					positionAnimal = 0;
				}
				listePersonnage.at(position)->ajouterAnimal(listeAnimal.at(positionAnimal));
				chaineAffiche += listeAnimal.at(positionAnimal)->nom;
				chaineAffiche += " entre en scene !";

				if (!listePersonnage.at(position)->animal == NULL) {

					if (!textureAnimal.loadFromFile("./data/" + listePersonnage.at(position)->animal->espece() + ".jpg"))
					{
						cout << "File not successfully loaded" << endl;
					}
					else {
						spriteAnimal.setTexture(textureAnimal);
					}

				}
				else {
					spriteAnimal.setTexture(textureVide);
				}
				
				break;

			case 32:
				cout << endl;
				chaineAffiche = "Changement de personnage ! \n";
				position++;
				if (position > 2) {
					position = 0;
				}
				chaineAffiche += listePersonnage.at(position)->direNom();
				chaineAffiche += " entre en scene !";
				spriteJoueur.setTexture(listeTexture.at(position));

				if (!listePersonnage.at(position)->animal == NULL) {

					if (!textureAnimal.loadFromFile("./data/" + listePersonnage.at(position)->animal->espece() + ".jpg"))
					{
						cout << "File not successfully loaded" << endl;
					}
					else {
						spriteAnimal.setTexture(textureAnimal);
					}

				}
				else {
					spriteAnimal.setTexture(textureVide);
				}
				break;

			default:
				cout << "" << endl;
			}

		}

		while (_kbhit()) {
			_getch();
		}
		tour++;

		sf::Text text(chaineAffiche, font);
		text.setCharacterSize(30);
		text.setStyle(sf::Text::Bold);
		text.setFillColor(sf::Color::White);

		sf::Text tour(to_string(tour), font);
		tour.setPosition(1100.0f, 25.0f);
		tour.setCharacterSize(30);
		tour.setStyle(sf::Text::Bold);
		tour.setFillColor(sf::Color::White);

		window.draw(spriteBackground);
		window.draw(spriteJoueur);
		window.draw(shapeRectangle);
		window.draw(text);
		window.draw(tour);
		window.draw(spriteAnimal);
		window.display();
	}

	ofstream fichierMonde;
	fichierMonde.open("data/monde.xml");
	fichierMonde << "<Monde>" << endl;
	fichierMonde << "<Animaux>" << endl;
	fichierMonde << referenceChaton->exporter() << endl;
	fichierMonde << referenceCorbeau->exporter() << endl;
	fichierMonde << referenceCreeper->exporter() << endl;
	fichierMonde << referenceCreeper->exporter() << endl;
	fichierMonde << "</Animaux>" << endl;
	fichierMonde << "<Personnages>" << endl;
	fichierMonde << listePersonnage.at(0)->exporter() << endl;
	fichierMonde << listePersonnage.at(1)->exporter() << endl;
	fichierMonde << listePersonnage.at(2)->exporter() << endl;
	fichierMonde << "</Personnages>" << endl;
	fichierMonde << "</Monde>" << endl;

	fichierMonde.close();
	listePersonnage.clear();

	delete referenceGuerrier;
	delete referenceKamikaze;
	delete referenceMage;

	delete referenceCorbeau;
	delete referenceChaton;
	delete referenceCreeper;


	return 0;
}