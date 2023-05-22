#pragma once
#include "Organism.h"
#include "World.h"
#include "Animal.h"
using namespace std;

class Sheep : public Animal
{
    public:
        Sheep( Position position);
        Sheep();
        Sheep(Organism &sheep,Position position, int turn);
        Organism* reproduce(Organism& org, int currentTurn, Position newPosition) override;
};