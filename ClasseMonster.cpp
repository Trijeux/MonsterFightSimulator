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
	std::cout << "Nom :" << monsterName << " / Attack :" << AD << " / Defense :" << DP << " / speed :" << S << " / Vie :" << HP << std::endl;
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

void Monster::Attack(Monster& enemy)
{
	if (AD > enemy.DP)
	{
		int domage;
		domage = AD - enemy.DP;
		/*std::cout << nameMonster() << AD << " " << enemy.nameMonster() << enemy.DP << std::endl;*/
		enemy.takeDomage(domage);
	}
	else
	{
		std::cout << "Seulement ? Tu es faible" << std::endl;
	}
}

void Monster::Pary()
{
	DP += 10;
};
