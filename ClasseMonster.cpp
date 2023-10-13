#include "ClasseMonster.h"
#include <iostream>
#include <random>

Monster::Monster(int _healthPoints, int _attackDamage, int _defensePoints, int _speed, Race _monsterRace) : HP(_healthPoints), AD(_attackDamage), DP(_defensePoints), S(_speed), monsterRace(_monsterRace) {}

Monster::Monster(int _attackDamageTemp, int _defensePointTemp, int _nbRound) : ADTemp(_attackDamageTemp), DPTemp(_defensePointTemp), nbRound(_nbRound) {};

Monster::~Monster()
{
	std::cout << "Le monster est detruite" << std::endl;
}

void Monster::Choix(Monster& enemy)
{
	int choix;
	std::random_device rand;
	std::default_random_engine e2(rand());
	std::uniform_int_distribution<> nbrand(1, 4);
	choix = nbrand(e2);
	/*std::cout << "Choix : " << choix << std::endl;*/

	if (choix == 1)
	{
		std::cout << "Attack" << std::endl;
		Attack(enemy);
		return;
	}
	if (choix == 2)
	{
		std::cout << "Rage" << std::endl;
		Rage(enemy);
		return;
	}
	if (choix == 3)
	{
		std::cout << "Pary" << std::endl;
		Pary();
		return;
	}
	if (choix == 4)
	{
		std::cout << "Heal" << std::endl;
		AutoHeal();
	}
}


void Monster::Round()
{
	nbRound += 1;
	std::cout << "Round : " << nbRound << std::endl;
}

void Monster::Statemonster1()
{
	std::string monsterName = nameMonster();
	std::cout << "Nom :" << "\x1B[34m" << monsterName << "\x1B[0m" << " / Attack :" << AD + ADTemp << " / Defense :" << DP + DPTemp << " / speed :" << S << " / Vie :" << HP << std::endl;
}

void Monster::Statemonster2()
{
	std::string monsterName = nameMonster();
	std::cout << "Nom :" << "\x1B[31m" << monsterName << "\x1B[0m" << " / Attack :" << AD + ADTemp << " / Defense :" << DP + DPTemp << " / speed :" << S << " / Vie :" << HP << std::endl;
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

void Monster::giveHP()
{
	if (HP < HPMax)
	{
		HP += 10;
		if (HP > HPMax)
		{
			HP = HPMax;
		}
	}
	else
	{
		std::cout << "HP deja au Max" << std::endl;
	}
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
		std::cout << enemy.nameMonster() << ": Seulement ? Tu es faible" << std::endl;
	}
}

void Monster::Rage(Monster& enemy)
{
	ADTemp += 10;
	Attack(enemy);
}

void Monster::Pary()
{
	DPTemp += 10;
}

void Monster::AutoHeal()
{
	giveHP();
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

int Monster::DeadOrNot(Monster& enemy1, Monster& enemy2)
{
	if (enemy1.HP <= 0)
	{
		std::cout << "\x1B[34m" << enemy1.nameMonster() << "\x1B[0m" << " est mort" << std::endl;
		std::cout << "\x1B[31m" << enemy2.nameMonster() << "\x1B[0m" << " a gagner" << std::endl;
		return false;
	}
	if (enemy2.HP <= 0)
	{
		std::cout << "\x1B[31m" << enemy2.nameMonster() << "\x1B[0m" << " est mort" << std::endl;
		std::cout << "\x1B[34m" << enemy1.nameMonster() << "\x1B[0m" << " a gagner" << std::endl;
		return false;
	}
}
