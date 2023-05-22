#pragma once
#include "Organism.h"
#include "World.h"
#include "Plant.h"
using namespace std;

class Factory {
public:
    static Organism* create(char species);
};