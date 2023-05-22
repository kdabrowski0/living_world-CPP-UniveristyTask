#include "Animal.h"
#include "World.h"
#include "Position.h"
#include "Organism.h"

Animal::Animal( Position position) : Organism( position)
{
	setSpecies('A');
	
}

Animal::Animal() : Organism()
{
	setSpecies('A');
	
}
Animal::Animal(Organism &other, Position position, int turn) : Organism(other, position, turn){}
Animal::~Animal(){}
