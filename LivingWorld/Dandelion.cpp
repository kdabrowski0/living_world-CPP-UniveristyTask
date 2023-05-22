#include "Dandelion.h"
#include "World.h"
#include "Position.h"
#include "Organism.h"
#include "Plant.h"


Dandelion::Dandelion(Position position) : Plant(position)
{
    setSpecies('D');
    setPower(0);
    setPowerToReproduce(4);
    setLiveLength(6);
    setInitiative(0);

}

Dandelion::Dandelion() : Plant()
{
    setSpecies('D');
    setPower(0);
    setPowerToReproduce(4);
    setLiveLength(6);
    setInitiative(0);

}

Dandelion::Dandelion(Organism &dandelion, Position positon, int turn) : Plant(dandelion, positon, turn)
{
    setLiveLength(6);
}
Organism* Dandelion::reproduce(Organism& org, int currentTurn, Position pos)
{
    Organism *newOrganism = new Dandelion(org, pos, currentTurn);
    org.addChild(newOrganism);
    return newOrganism;
}