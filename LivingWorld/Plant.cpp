#include "Plant.h"

Plant::Plant( Position position) : Organism(position)
{
	setSpecies('P');

}

Plant::Plant() : Organism()
{
	setSpecies('P');
}

void Plant::move(int dx, int dy)
{
	Organism::move(0, 0);
}


Plant::Plant(Organism &other, Position position, int turn) : Organism(other, position, turn)
{
}
Plant::~Plant()
{
}