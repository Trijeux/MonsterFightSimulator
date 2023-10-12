#pragma once
#include <string>
#include <vector>

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
	Monster(int _healthPoints, int _attackDamage, int _defensePoints, int _speed, Race _nameRace);

	//Propryety
	int HP;
	int AD;
	int DP;
	int S;
	Race NameRace;

	//Metode
	void Test();
};

