#pragma once
#include "Organism.h"

class Plant : public Organism
{	

	public:
		Plant( Position position);
		Plant();
		Plant(Organism& other, Position position, int turn);
		virtual ~Plant() = 0;
		void move(int dx, int dy);
};