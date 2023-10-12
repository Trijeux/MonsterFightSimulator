#include "ClasseMonster.h"
#include "ClassePlayer.h"
#include <iostream>

Monster::Monster(int _healthPoints, int _attackDamage, int _defensePoints, int _speed, Race _monsterRace) : HP(_healthPoints), AD(_attackDamage), DP(_defensePoints), S(_speed), monsterRace(_monsterRace) {};
 
Monster::~Monster()
{
	std::cout << "Le monster est detruite" << std::endl;
}


void Monster::StateMonster()
{
	std::string monsterName = nameMonster(monsterRace);
	std::cout << "Vie : " << HP << " Attack : " << AD << " Defense : " << DP << " speed : " << S << " NameRace : " << monsterName << std::endl;
}

std::string Monster::nameMonster(Race nameRace)
{
	switch (nameRace) {
	case Orc:
		return "Orc";
	case Troll:
		return "Troll";
	case Goblin:
		return "Goblin";
	default:
		return "Invalid";
	}
}