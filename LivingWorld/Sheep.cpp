#include "Sheep.h"
#include "World.h"
#include "Position.h"  
#include "Organism.h"
#include "Animal.h"


Sheep::Sheep( Position position) : Animal(position)
{
    setSpecies('S');
    setPower(3);
    setPowerToReproduce(6);
    setLiveLength(10);
    setInitiative(3);
    
}

Sheep::Sheep() : Animal()
{
    setSpecies('S');
    setPower(3);
    setPowerToReproduce(6);    
    setLiveLength(10);
    setInitiative(3);
}

Sheep::Sheep(Organism &sheep, Position position, int turn) : Animal(sheep, position, turn)
{
    setLiveLength(10);
}
Organism* Sheep::reproduce(Organism& org, int currentTurn, Position pos)
{
    Organism *newOrganism = new Sheep(org, pos, currentTurn);
    org.addChild(newOrganism);
    return newOrganism;
}
