#pragma once
#include "Organism.h"
#include "World.h"
#include "Animal.h"
using namespace std;

class Wolf : public Animal
{
    public:
        Wolf( Position position);
        Wolf();
        Wolf(Organism &other,Position position, int turn);
        Organism* reproduce(Organism& org, int currentTurn, Position newPosition) override;
};