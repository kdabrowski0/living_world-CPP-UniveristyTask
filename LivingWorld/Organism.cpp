#include "Organism.h"
#include <list>
#include <tuple>
#include <iostream>
#include <fstream>
#include <vector>

Organism::Organism(Position position)
{
	setPower(0);
	setPosition(position);
	setSpecies('O');
	setPowerToReproduce(0);
	setInitiative(0);
	setLiveLength(0);
	setHistory(list<tuple<int, int>>());
	setTurnOfDeath(-1);
	setTurnOfBorn(0);
	setParent(nullptr);
	setChildren(vector<Organism*>());
	setIsPoisunous(false);
}

int Organism::getPowerToReproduce()
{
	return this->powerToReproduce;
}

void Organism::setPowerToReproduce(int powerToReproduce)
{
	this->powerToReproduce = powerToReproduce;
}
int Organism::getLiveLength()
{
	return this->liveLength;
}

void Organism::setLiveLength(int liveLength)
{
	this->liveLength = liveLength;
}

int Organism::getPower()
{
	return this->power;
}

int Organism::getInitiative()
{
	return this->initiative;
}

void Organism::setInitiative(int initiative)
{
	this->initiative = initiative;
}

void Organism::setPower(int power)
{
	this->power = power;
}

bool Organism::ifReproduce()
{
	if (getPower() >= getPowerToReproduce())
		return true;
	else
		return false;
}

Position Organism::getPosition()
{
	return this->position;
}

void Organism::setPosition(Position position)
{
	this->position = position;
}

string Organism::toString()
{	
	string species_str(1, getSpecies());
	return "{ species: " + species_str + 
		", power: " + to_string(getPower()) + 
		", powerToReproduce: " + to_string(getPowerToReproduce()) +
		", liveLength: " + to_string(getLiveLength()) +
		", history: " + historyToString() +
		", turnOfBorn: " + to_string(getTurnOfBorn()) +
		", position: " + getPosition().toString() + "}";
}

void Organism::move(int dx, int dy)
{
	position.move(dx, dy);
}

void Organism::addChild(Organism* child) {
  children.push_back(child);
}

char Organism::getSpecies()
{
	return this->species;
}

void Organism::setSpecies(char spec)
{
	this->species = spec;
}

void Organism::setHistory(list<tuple<int, int>> history)
{
	this->history = history;
}

void Organism::addHistory(int turn, int turnOfDeath)
{
	history.push_back(make_tuple(turn, turnOfDeath));
}

void Organism::updateHistory(int turn, int turnOfDeath)
{

	for (auto it = history.begin(); it != history.end(); ++it)
	{
		if (get<0>(*it) == turn && get<1>(*it) == -1)
		{
			get<1>(*it) = turnOfDeath;
		}
	}
}


list<tuple<int, int>> Organism::getHistory()
{
	return this->history;
}

int Organism::getTurnOfDeath()
{
	return this->turnOfDeath;
}

void Organism::setTurnOfDeath(int turnOfDeath)
{
	this->turnOfDeath = turnOfDeath;
}

int Organism::getTurnOfBorn()
{
	return this->turnOfBorn;
}

void Organism::setTurnOfBorn(int turnOfBorn)
{
	this->turnOfBorn = turnOfBorn;
}

string Organism::historyToString()
{
	string result = "";
	for (auto it = history.begin(); it != history.end(); ++it)
	{
		result += to_string(get<0>(*it)) + " " + to_string(get<1>(*it)) + "\n";
	}
	return result;
}

Organism* Organism::getParent() {
	return this->parent;
}

void Organism::setParent(Organism* parent) {
	this->parent = parent;
}

vector<Organism*> Organism::getChildren() {
  return children;
}

void Organism::setChildren(vector<Organism*> children) {
  this->children = children;
}

void Organism::setIsPoisunous(bool isPoisunous) {
	this->isPoisunous = isPoisunous;
}

bool Organism::getIsPoisunous() {
	return this->isPoisunous;
}

Organism::Organism(Organism &org, Position position, int turn ) {
    setPower(org.power);
    setPowerToReproduce(org.powerToReproduce);
    setSpecies(org.species);
	setInitiative(org.initiative);
	setLiveLength(org.liveLength);	
	setHistory(org.history);
	setIsPoisunous(org.isPoisunous);
	setPosition(position);
	setTurnOfBorn(turn);
	setTurnOfDeath(-1);
	setParent(&org);
	setChildren(vector<Organism*>());
}


Organism* Organism::reproduce(Organism& org,int currentTurn, Position newPosition) {
	return nullptr;
}

void Organism::serialize(std::ofstream& ofs) {
    ofs.write((char*)&power, sizeof(int));
    ofs.write((char*)&liveLength, sizeof(int));
	ofs.write((char*)&species, sizeof(char));
	ofs.write((char*)&initiative, sizeof(int));
    ofs.write((char*)&powerToReproduce, sizeof(int));
    ofs.write((char*)&history, sizeof(int));
	ofs.write((char*)&children, sizeof(int));
	ofs.write((char*)&parent, sizeof(int));
	ofs.write((char*)&isPoisunous, sizeof(bool));
    ofs.write((char*)&position, sizeof(Position));
	ofs.write((char*)&turnOfDeath, sizeof(int));
	ofs.write((char*)&turnOfBorn, sizeof(int));
}

void Organism::deserialize(std::ifstream& ifs) {
    ifs.read((char*)&power, sizeof(int));
    ifs.read((char*)&liveLength, sizeof(int));
	ifs.read((char*)&species, sizeof(char));
	ifs.read((char*)&initiative, sizeof(int));
    ifs.read((char*)&powerToReproduce, sizeof(int));
    ifs.read((char*)&history, sizeof(int));
	ifs.read((char*)&parent, sizeof(int));
	ifs.read((char*)&isPoisunous, sizeof(bool));
    ifs.read((char*)&position, sizeof(Position));
	ifs.read((char*)&children, sizeof(int));
	ifs.read((char*)&turnOfDeath, sizeof(int));
	ifs.read((char*)&turnOfBorn, sizeof(int));
}

bool Organism::colision(Organism* other) {
	if (this->getSpecies() != other->getSpecies()) {
		return true;
	}
	else {
		return false;
	}
}

Organism::~Organism(){}