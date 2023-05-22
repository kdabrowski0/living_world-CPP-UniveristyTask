#include "Toadstool.h"
#include "World.h"
#include "Position.h"
#include "Organism.h"
#include "Plant.h"


Toadstool::Toadstool( Position position) : Plant( position)
{
    setSpecies('T');
    setPower(0);
    setPowerToReproduce(6);
    setLiveLength(12);
    setInitiative(0);
    setIsPoisunous(true);

}

Toadstool::Toadstool() : Plant()
{
    setSpecies('T');
    setPower(0);
    setPowerToReproduce(6);
    setLiveLength(12);
    setInitiative(0);
    setIsPoisunous(true);

}

Toadstool::Toadstool(Organism &toadstool, Position position, int turn) : Plant(toadstool, position, turn)
{
    setLiveLength(12);
   
}
Organism* Toadstool::reproduce(Organism& org, int currentTurn, Position pos)
{
    Organism *newOrganism = new Toadstool(org, pos, currentTurn);
    org.addChild(newOrganism);
    return newOrganism;
}