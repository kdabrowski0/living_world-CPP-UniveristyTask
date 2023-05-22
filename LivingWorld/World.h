#pragma once
#include <vector>
#include <ctime>
#include "Organism.h"

using namespace std;
class World
{
private:
	int worldX;
	int worldY;
	int turn = 0;
	vector<Organism*> organisms;
	char separator = '.';
	Organism* getOrganismFromPosition(int x, int y);
	bool isPositionOnWorld(int x, int y);
	bool isPositionFree(Position position);


public:
	World(int worldX, int worldY);
	World() : World(9, 9) {};
	int getWorldX();	
	void setWorldX(int worldX);
	int getWorldY();
	void setWorldY(int worldY);
	int getTurn();
	void removeOrganism(Organism* organism);
	string getOrganisms();
	void addOrganism(Organism* organism);
	vector<Position> getVectorOfFreePositionsAround(Position position);
	void makeTurn();
	void serialize(std::ofstream& ofs);
	void deserialize(std::ifstream& ifs);
	void writeWorld(std::string fileName);
	Organism* findNearestEnemy(Position position);
	void historyUpdates(Organism* org);
	void reproduceOrganism(Organism* organism, std::vector<Organism *> *organismAdded);
	vector<Position> getVectorOfPositionAround(Position position);
	void readWorld(std::string fileName);
	void fightOrganisms(Organism* attacker, Organism* defender);
	string toString();

};