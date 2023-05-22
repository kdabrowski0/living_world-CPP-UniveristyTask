#pragma once
#include "Organism.h"
#include "World.h"
#include "Plant.h"
using namespace std;

class Dandelion : public Plant
{
    public:
        Dandelion( Position position);
        Dandelion();
        Dandelion(Organism &dandelion,Position position, int turn);
        Organism* reproduce(Organism& org, int currentTurn, Position newPosition) override;
};  

