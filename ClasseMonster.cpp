#include "ClasseMonster.h"
#include <iostream>
#include <random>

#pragma region Constructor


Monster::Monster(int _healthPoints, int _attackDamage, int _defensePoints, int _speed, Race _monsterRace) : HP(_healthPoints), AD(_attackDamage), DP(_defensePoints), S(_speed), monsterRace(_monsterRace) {}

Monster::Monster(int _attackDamageTemp, int _defensePointTemp, int _nbRound) : ADTemp(_attackDamageTemp), DPTemp(_defensePointTemp), nbRound(_nbRound) {};

Monster::~Monster()
{
	//std::cout << "Le monster est detruite" << std::endl;
}
#pragma endregion

#pragma region Metode Public
void Monster::Choix(Monster& enemy, int priority)
{
	int choix;

	//Choose a number in 1 and 4 for the action performed by the monster
	std::random_device rand;
	std::default_random_engine e2(rand());
	std::uniform_int_distribution<> nbrand(1, 4);
	choix = nbrand(e2);

	//Monster choices
	if (choix == 1)
	{
		std::cout << "Attack" << std::endl;
		Attack(enemy, priority);
	}
	if (choix == 2)
	{
		std::cout << "Rage" << std::endl;
		Rage(enemy, priority);

	}
	if (choix == 3)
	{
		std::cout << "Pary" << std::endl;
		Pary();

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

void Monster::EndOfRound(Monster& enemy1, Monster& enemy2)
{
	//See if monster 1 has temporary defense or temporary attack
	if (enemy1.DPTemp > 0 || enemy1.ADTemp > 0)
	{
		enemy1.resetDPTemp();
		enemy1.resetADTemp();
	}

	//See if monster 2 has temporary defense or temporary attack
	if (enemy2.DPTemp > 0 || enemy2.ADTemp > 0)
	{
		enemy2.resetDPTemp();
		enemy2.resetADTemp();
	}
}

int Monster::DeadOrNot(Monster& enemy1, Monster& enemy2)
{
	//See if monster 1 is dead
	if (enemy1.HP <= 0)
	{
		std::cout << "\x1B[34m" << enemy1.nameMonster() << "\x1B[0m" << " est mort" << std::endl;
		std::cout << "\x1B[31m" << enemy2.nameMonster() << "\x1B[0m" << " a gagner" << std::endl;
		return false;
	}
	//See if monster 2 is dead
	if (enemy2.HP <= 0)
	{
		std::cout << "\x1B[31m" << enemy2.nameMonster() << "\x1B[0m" << " est mort" << std::endl;
		std::cout << "\x1B[34m" << enemy1.nameMonster() << "\x1B[0m" << " a gagner" << std::endl;
		return false;
	}
}
#pragma endregion

#pragma region Metode Private
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
	//Check if life is already at max or not
	if (HP < HPMax)
	{
		int healPoint;
		std::random_device rand;
		std::default_random_engine e2(rand());
		std::poisson_distribution<> nbrand(5);
		healPoint = nbrand(e2);

		HP += healPoint;
		//Prevents you from healing more than max life
		if (HP > HPMax)
		{
			HP = HPMax;
		}
		std::cout << "Ca fait du bien" << std::endl;
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

void Monster::Attack(Monster& enemy, int priority)
{
	int echec = 0;
	//Check if the enemy's defense is not above the attack
	if (AD + ADTemp > enemy.DP + enemy.DPTemp)
	{
		int domage;
		domage = AD + ADTemp - enemy.DP + enemy.DPTemp;
		/*std::cout << nameMonster() << AD << " " << enemy.nameMonster() << enemy.DP << std::endl;*/
		enemy.takeDomage(domage);
		echec = 1;
	}
	if (ADTemp <= 0)
	{
		std::cout << "Prend ca" << std::endl;
	}
	if (ADTemp > 0)
	{
		std::cout << "Tu vas Mourire" << std::endl;
	}
	if (echec == 0 && S > enemy.S || priority == 1)
	{
		std::cout << "\x1B[31m" << enemy.nameMonster() << "\x1B[0m" << ": Seulement ? Tu es faible" << std::endl;
	}
	if (echec == 0 && enemy.S > S || priority == 2)
	{
		std::cout << "\x1B[34m" << enemy.nameMonster() << "\x1B[0m" << ": Seulement ? Tu es faible" << std::endl;
	}
}

void Monster::Rage(Monster& enemy, int priority)
{
	int ragePoint;
	std::random_device rand;
	std::default_random_engine e2(rand());
	std::poisson_distribution<> nbrand(5);;
	ragePoint = nbrand(e2);

	ADTemp += ragePoint;
	Attack(enemy, priority);
}

void Monster::Pary()
{
	int paryPoint;
	std::random_device rand;
	std::default_random_engine e2(rand());
	std::poisson_distribution<> nbrand(5);;
	paryPoint = nbrand(e2);

	DPTemp += paryPoint;
	std::cout << "essaie de me toucher si tu peux" << std::endl;
}

void Monster::AutoHeal()
{
	giveHP();
}
#pragma endregion












