#include <iostream>
#include "Position.h"
#include "Organism.h"
#include "Plant.h"
#include "Animal.h"
#include "World.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Grass.h"
#include "Dandelion.h"
#include "Toadstool.h"


using namespace std;

int main()
{
	
	// World test
	World world;
	Position posP1{ 4, 5 };
	Grass plantW1{ posP1 };
	Position posP2{ 5, 4 };
	Toadstool plantW2{ posP2 };
	Position posP3{ 1, 4 };
	Dandelion plantW3{ posP3 };

	Position posA1{ 2, 0 };
	Sheep animalW1{ posA1 };
	Position posA2{ 2, 3 };
	Wolf animalW2{ posA2 };


	world.addOrganism(&plantW1);
	world.addOrganism(&plantW2);
	world.addOrganism(&plantW3);
	world.addOrganism(&animalW1);
	world.addOrganism(&animalW2);

	
	cout << world.toString() << endl;
	cout << world.getOrganisms() << endl;
	for (int i = 0; i < 14; i++) {
		world.makeTurn();
        cout << world.toString() << endl;  
		cout << world.getOrganisms() << endl;
  
	}


	return 0;
}