#pragma once
#include <string>
#include "Position.h"
#include <list>
#include <tuple>
#include <vector>
using namespace std;
class Organism
{
private:
	int power;
	Position position;
	int powerToReproduce;
	char species;
	int liveLength;
	int initiative;
	list<tuple<int, int>> history;
	int turnOfDeath;
	int turnOfBorn;
	Organism* parent;
	vector<Organism*> children;
	bool isPoisunous;

public:
	Organism(Position position);
	Organism() : power(0), position(0, 0), powerToReproduce(0),species('O'), liveLength(0), parent(nullptr), children() {};
	int getPowerToReproduce();
	void setPowerToReproduce(int powerToReproduce);
	int getPower();
	int getInitiative();
	void setIsPoisunous(bool isPoisunous);
	bool getIsPoisunous();
	void addChild(Organism* child);
	vector<Organism*> getChildren();
	void setChildren(vector<Organism*> children);
	void setInitiative(int initiative);
	string historyToString();
	int getTurnOfDeath();
	void setTurnOfDeath(int turnOfDeath);
	int getTurnOfBorn();
	void setTurnOfBorn(int turnOfBorn);
	void addHistory(int turn, int turnOfDeath);
	void setHistory(list<tuple<int, int>> history);
	list<tuple<int, int>> getHistory();
	void setPower(int power);
	Position getPosition();
	int getLiveLength();
	void updateHistory(int turn, int turnOfDeath);
	virtual ~Organism() = 0;
	void setLiveLength(int liveLength);
	void setPosition(Position position);
	char getSpecies();
	void setSpecies(char spec);
	bool ifReproduce();
	string toString();
	void serialize(std::ofstream& ofs);
	void deserialize(std::ifstream& ifs);
	bool colision(Organism* other);
	Organism(Organism& org, Position position, int turn);
	virtual Organism* reproduce(Organism& org, int currentTurn, Position newPosition);
	virtual void move(int dx, int dy);
	Organism* getParent();
  	void setParent(Organism* parent); 
	
};