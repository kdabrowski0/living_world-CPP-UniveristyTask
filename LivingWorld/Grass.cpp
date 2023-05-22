#include "Grass.h"
#include "World.h"
#include "Position.h"
#include "Organism.h"
#include "Plant.h"

Grass::Grass(Position position) : Plant(position)
{
    setSpecies('G');
    setPower(0);
    setPowerToReproduce(4);
    setLiveLength(6);
    setInitiative(0);

}

Grass::Grass() : Plant()
{
    setSpecies('G');
    setPower(0);
    setPowerToReproduce(4);
    setLiveLength(6);
    setInitiative(0);

}

Grass::Grass(Organism &grass, Position position, int turn) : Plant(grass, position, turn)
{
    setLiveLength(6);
}
Organism* Grass::reproduce(Organism& org, int currentTurn, Position pos)
{
    Organism *newOrganism = new Grass(org, pos, currentTurn);
    org.addChild(newOrganism);
    return newOrganism;
}