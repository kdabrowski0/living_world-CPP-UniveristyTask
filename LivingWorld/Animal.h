#pragma once
#include "Organism.h"
#include "World.h"
using namespace std;

class Animal : public Organism
{
	public:
		Animal( Position position);
		Animal();
		Animal(Organism &other, Position position, int turn);
		virtual ~Animal() = 0;
};
