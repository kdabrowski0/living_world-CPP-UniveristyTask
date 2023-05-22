#pragma once
#include "Organism.h"
#include "World.h"
#include "Plant.h"
using namespace std;

class Grass : public Plant
{
    public:
        Grass( Position position);
        Grass();
        Grass(Organism &grass,Position position, int turn);
        Organism* reproduce(Organism& org, int currentTurn, Position newPosition) override;
};