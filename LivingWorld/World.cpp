#include "World.h"
#include "Factory.h"
#include <fstream>
#include <bits/stdc++.h>


Organism* World::getOrganismFromPosition(int x, int y)
{	
	for (auto org : organisms)
		if (org->getPosition().getX() == x && org->getPosition().getY() == y)
			return org;
	return nullptr;
}

bool World::isPositionOnWorld(int x, int y)
{
	return (x >= 0 && y >= 0 && x < getWorldX() && y < getWorldY());
}


bool World::isPositionFree(Position position) {
	return getOrganismFromPosition(position.getX(), position.getY()) == nullptr;
}


vector<Position> World::getVectorOfFreePositionsAround(Position position)
{	
	int pos_x = position.getX(), pos_y = position.getY();
	vector<Position> result;
	for(int x = -1; x < 2; ++x)
		for (int y = -1; y < 2; ++y)
			if ((x != 0 || y != 0) && 
				isPositionOnWorld(pos_x + x, pos_y + y)) {
				result.push_back(Position(pos_x + x, pos_y + y));
			}
	auto iter = remove_if(result.begin(), result.end(),
		[this](Position pos) {return !isPositionFree(pos); });
	result.erase(iter, result.end());

	return result;
}

vector<Position> World::getVectorOfPositionAround(Position position){
	int pos_x = position.getX(), pos_y = position.getY();
	vector<Position> result;
	for(int x = -1; x < 2; ++x)
		for (int y = -1; y < 2; ++y)
			if ((x != 0 || y != 0) && 
				isPositionOnWorld(pos_x + x, pos_y + y)) {
				result.push_back(Position(pos_x + x, pos_y + y));
			}
	return result;
}


World::World(int worldX, int worldY)
{
	setWorldX(worldX);
	setWorldY(worldY);
}

int World::getWorldX()
{
	return this->worldX;
}

void World::setWorldX(int worldX)
{
	this->worldX = worldX;
}

int World::getWorldY()
{
	return this->worldY;
}

void World::setWorldY(int worldY)
{
	this->worldY = worldY;
}

int World::getTurn()
{
	return this->turn;
}

void World::removeOrganism(Organism* organism)
{
	auto it = std::find(organisms.begin(), organisms.end(), organism);
	if (it != organisms.end()) {
		organisms.erase(it);
	}
}


void World::addOrganism(Organism* organism)
{
	this->organisms.push_back(organism);
}

string World::getOrganisms(){
	string result = "";
	for (auto org : organisms) {
		result += org->toString() + "\n";
	}
	return result;
}

void World::historyUpdates(Organism* org)
{
	for (auto &org2 : organisms) {
		if (org2->getParent() == org || std::find(org->getChildren().begin(), org->getChildren().end(), org2) != org->getChildren().end()) {
			org2->updateHistory(org->getTurnOfBorn(), org->getTurnOfDeath());
		}
	}
}

void World::reproduceOrganism(Organism *organism, std::vector<Organism *> *organismAdded)
{
	std::vector<Position> positionsAround = getVectorOfFreePositionsAround(organism->getPosition());
	if(positionsAround.size()>0)
	{
		int randomIndex = rand() % positionsAround.size();
		Position newPosition = positionsAround[randomIndex];
		Organism *newOrg = organism->reproduce(*organism, turn, newPosition);
		if(newOrg != nullptr)
		{
			std :: cout << "Organism "<< organism->getSpecies() << " reproduces and creates "<< newOrg->getSpecies() <<  " born at " << newPosition.getX() << " " << newPosition.getY() << std :: endl;
			organismAdded->push_back(newOrg);
			newOrg->addHistory(organism->getTurnOfBorn(), -1);
		}
	}
}

Organism *World::findNearestEnemy(Position position)
{
	std :: vector<Position> posAround = getVectorOfPositionAround(position);
	for(auto pos : posAround){
		Organism* orgAround = getOrganismFromPosition(pos.getX(), pos.getY());
		Organism* org = getOrganismFromPosition(position.getX(), position.getY());
		if(orgAround != nullptr && orgAround->getSpecies() != org->getSpecies()){
			return orgAround;
		}
			
	}
	return nullptr;
}

void World::fightOrganisms(Organism* attacker, Organism* defender) {
    cout << attacker->getSpecies() << " form position " << attacker->getPosition().getX() << " " << attacker->getPosition().getY() << " fights with " << defender->getSpecies() << " from position " << defender->getPosition().getX() << " " << defender->getPosition().getY() << endl;
	if(defender->getIsPoisunous() == true){
		defender->setTurnOfDeath(turn);
		attacker->setTurnOfDeath(turn);
		historyUpdates(defender);
		historyUpdates(attacker);
		removeOrganism(defender);
		removeOrganism(attacker);
		cout << defender->getSpecies() << " died at " << defender->getPosition().getX() << " " << defender->getPosition().getY() << " and killed " << attacker->getSpecies() << " at " << attacker->getPosition().getX() << " " << attacker->getPosition().getY() << endl;
	}else{
		defender->setTurnOfDeath(turn);
		historyUpdates(defender);
		removeOrganism(defender);
		cout << defender->getSpecies() << " was killed at " << defender->getPosition().getX() << " " << defender->getPosition().getY() << endl;
	}
	
}
void World::makeTurn()
{
    vector<Position> newPositions;
    int numberOfNewPositions;
    int randomIndex;
	srand(time(0));
	std :: sort(organisms.begin(), organisms.end(), [](Organism *org1, Organism *org2) 
				{return org1->getInitiative() > org2->getInitiative(); });
	for (auto org : organisms) {
		newPositions = getVectorOfFreePositionsAround(org->getPosition());
		numberOfNewPositions = newPositions.size();
		if (numberOfNewPositions > 0) {
            int randomIndex = rand() % numberOfNewPositions;
	        int new_x = newPositions[randomIndex].getX() - org->getPosition().getX();
	        int new_y = newPositions[randomIndex].getY() - org->getPosition().getY();
			org -> move(new_x,new_y);	
        }
	}
	for (int i = 0; i < organisms.size(); ++i){
        auto org = organisms[i];
		org->setLiveLength(org->getLiveLength() - 1);
		if (org->getLiveLength() <= 0) {
			org->setTurnOfDeath(turn);
			historyUpdates(org);
			removeOrganism(org);
			cout << org->getSpecies() << " died from old age at " << org->getPosition().getX() << " " << org->getPosition().getY() << endl;
			--i;
			continue;
		}
		Organism* orgAround = findNearestEnemy(org->getPosition());
		if (orgAround != nullptr && org->getPower() > orgAround->getPower() && org->colision(orgAround)) {
			fightOrganisms(org, orgAround);
			--i;
			continue;
		}
		if (org->ifReproduce() && numberOfNewPositions > 0) {
			org->setPower(org->getPower() / 2);
			reproduceOrganism(org, &organisms);
		}
		org->setPower(org->getPower() + 1);
    }
    turn++;
}

void World::serialize(std::ofstream& ofs) {
    ofs.write((char*)&worldX, sizeof(int));
    ofs.write((char*)&worldY, sizeof(int));
    ofs.write((char*)&turn, sizeof(int));
    int numOrganisms = organisms.size();
    ofs.write((char*)&numOrganisms, sizeof(int));
    for (auto org : organisms) {
        org->serialize(ofs);
    }
}

void World::deserialize(std::ifstream& ifs) {
    ifs.read((char*)&worldX, sizeof(int));
    ifs.read((char*)&worldY, sizeof(int));
    ifs.read((char*)&turn, sizeof(int));
    int numOrganisms;
    ifs.read((char*)&numOrganisms, sizeof(int));
    for (int i = 0; i < numOrganisms; i++) {
        Organism* org = nullptr;
        char species;
        ifs.read((char*)&species, sizeof(char));
        org = Factory::create(species);
        org->deserialize(ifs);
        addOrganism(org);
    }
}

void World::writeWorld(std::string fileName) {
    std::ofstream ofs(fileName, std::ios::out | std::ios::binary);
    if (ofs.is_open()) {
        serialize(ofs);
        ofs.close();
    }
}

void World::readWorld(std::string fileName) {
    std::ifstream ifs(fileName, std::ios::in | std::ios::binary);
    if (ifs.is_open()) {
        deserialize(ifs);
        ifs.close();
    }
}

string World::toString()
{
	string result = "\nturn: " + to_string(getTurn()) + "\n";
	string spec;

	for (int wY = 0; wY < getWorldY(); ++wY) {
		for (int wX = 0; wX < getWorldX(); ++wX) {
			Organism* org = getOrganismFromPosition(wX, wY);
			if (org != nullptr) {
				spec = org->getSpecies();
				result += spec;
			}
			else {
				result += separator;
			}
		};
		result += "\n";
	}
	return result;
}

