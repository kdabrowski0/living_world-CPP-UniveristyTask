#pragma once
#include "Organism.h"
#include "World.h"
#include "Plant.h"
using namespace std;


class Toadstool : public Plant
{
    public:
        Toadstool( Position position);
        Toadstool();
        Toadstool(Organism &toadstool,Position position, int turn);
        Organism* reproduce(Organism& org, int currentTurn, Position newPosition) override;
};