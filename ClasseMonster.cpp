#include "ClasseMonster.h"
#include <iostream>

Monster::Monster(int _healthPoints, int _attackDamage, int _defensePoints, int _speed, Race _monsterRace) : HP(_healthPoints), AD(_attackDamage), DP(_defensePoints), S(_speed), monsterRace(_monsterRace) {};

Monster::~Monster()
{
	std::cout << "Le monster est detruite" << std::endl;
}


void Monster::State()
{
	std::string monsterName = nameMonster();
	std::cout << "Nom :" << monsterName << " / Attack :" << AD + ADTemp << " / Defense :" << DP + DPTemp << " / speed :" << S << " / Vie :" << HP << std::endl;
}

std::string Monster::nameMonster()
{
	switch (this->monsterRace) {
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

void Monster::takeDomage(int domage)
{
	HP -= domage;
}

void Monster::resetDPTemp()
{
	DPTemp = 0;
}

void Monster::resetADTemp()
{
	ADTemp = 0;
}

void Monster::Attack(Monster& enemy)
{
	if (AD + ADTemp > enemy.DP + enemy.DPTemp)
	{
		int domage;
		domage = AD + ADTemp - enemy.DP + enemy.DPTemp;
		/*std::cout << nameMonster() << AD << " " << enemy.nameMonster() << enemy.DP << std::endl;*/
		enemy.takeDomage(domage);
	}
	else
	{
		std::cout << "Seulement ? Tu es faible" << std::endl;
	}
}

void Monster::Rage()
{
	ADTemp += 10;
}

void Monster::Pary()
{
	DPTemp += 10;
}

void Monster::EndOfRound(Monster& enemy1, Monster& enemy2)
{
	if (enemy1.DPTemp > 0 || enemy1.ADTemp > 0)
	{
		enemy1.resetDPTemp();
		enemy1.resetADTemp();
	}
	if (enemy2.DPTemp > 0 || enemy2.ADTemp > 0)
	{
		enemy2.resetDPTemp();
		enemy2.resetADTemp();
	}
}
