#include "Factory.h"
#include "Dandelion.h" 
#include "Grass.h"
#include "Sheep.h"
#include "Wolf.h"
#include "Toadstool.h"
#include <iostream>
using namespace std;

Organism* Factory::create(char species) {
    Organism* org = nullptr;
    switch (species) {
    case 'D':
        org = new Dandelion();
        break;
    case 'G':
        org = new Grass();
        break;
    case 'S':
        org = new Sheep();
        break;
    case 'W':
        org = new Wolf();
        break;
    case 'T':
        org = new Toadstool();
        break;
    }
    return org;
}