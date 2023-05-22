#include "Wolf.h"
#include "World.h"
#include "Position.h"
#include "Organism.h"
#include "Animal.h"


Wolf::Wolf( Position position) : Animal( position)
{
    setSpecies('W');
    setPower(8);
    setPowerToReproduce(16);
    setLiveLength(20);
    setInitiative(5);
}

Wolf::Wolf() : Animal()
{
    setSpecies('W');
    setPower(8);
    setPowerToReproduce(16);    
    setLiveLength(20);
    setInitiative(5);
    
}

//copy constructor
Wolf::Wolf(Organism &wolf, Position position, int turn) : Animal(wolf, position, turn)
{
    setLiveLength(20);
    
}

Organism* Wolf::reproduce(Organism& org, int currentTurn, Position pos)
{
    Organism *newOrganism = new Wolf(org, pos, currentTurn);
    org.addChild(newOrganism);
    return newOrganism;
}