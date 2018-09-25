using namespace std;
#include <iostream>

class Personnage{

public:
	Personnage();
	virtual void attaquer();
	virtual void avancer();
	void rotationGauche();
	void rotationDroite();

};
