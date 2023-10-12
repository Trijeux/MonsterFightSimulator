#pragma once
#include <string>

enum Race
{
	Orc,
	Troll,
	Goblin
};

class Monster
{
public:
	//Constructor
	Monster(int _healthPoints, int _attackDamage, int _defensePoints, int _speed, Race _monsterRace);
	~Monster();

	//Metode
	void StateMonster();

private:

	//Propryety
	int HP;
	int AD;
	int DP;
	int S;
	Race monsterRace;

	//Metode
	std::string nameMonster(Race NameRace);

	
};

