#include "ClasseMonster.h"
#include <iostream>
#include <random>
#include <windows.h>

#pragma region Constructor
Monster::Monster(int _healthPoints, int _attackDamage, int _defensePoints, int _speed, Race _monsterRace, int _color) : HP(_healthPoints), AD(_attackDamage), DP(_defensePoints), S(_speed), monsterRace(_monsterRace), color(_color) {}

Monster::~Monster()
{
	//std::cout << "Le monster est detruite" << std::endl;
}
#pragma endregion

#pragma region Metode Public
void Monster::Choix(Monster& enemy)
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
		Attack(enemy);
	}
	if (choix == 2)
	{
		std::cout << "Rage" << std::endl;
		Rage(enemy);

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

void Monster::Statemonster()
{
	std::cout << "Nom :";
	ShowMessageMonster(nameMonster());
	std::cout << " / Attack :" << AD + ADTemp << " / Defense :" << DP + DPTemp << " / speed :" << S << " / Vie :" << HP << std::endl;
}

void Monster::EndOfRound()
{
	//See if monster has temporary defense or temporary attack
	if (DPTemp > 0 || ADTemp > 0)
	{
		resetDPTemp();
		resetADTemp();
	}
}

void Monster::EndGameMessage()
{
	//See if monster is dead
	if (HP <= 0)
	{
		ShowMessageMonster(nameMonster());
		std::cout << " a perdu" << std::endl;
	}
	//See if monster is alive
	if (HP > 0)
	{
		ShowMessageMonster(nameMonster());
		std::cout << " a gagne" << std::endl;
	}
}

bool Monster::DeadOrNot()
{
	if (HP <= 0)
	{
		return false;
	}
	
	return true;
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
	case Centaur:
		return "Centaur";
	case Dullahan:
		return "Dullahan";
	case Ogre:
		return "Ogre";
	case Werewolf:
		return "Werewolf";
	case Elf:
		return "Elf";
	case Harpy:
		return "Harpy";
	case Salamander:
		return "Salamander";
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
		ShowMessageMonster(nameMonster());
		std::cout << ": ca fait du bien" << std::endl;
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
	int echec = 0;
	//Check if the enemy's defense is not above the attack
	if (AD + ADTemp > enemy.DP + enemy.DPTemp)
	{
		int domage;
		domage = AD + ADTemp - enemy.DP + enemy.DPTemp;
		enemy.takeDomage(domage);
		echec = 1;
	}
	if (ADTemp <= 0)
	{
		ShowMessageMonster(nameMonster());
		std::cout << ": prend ca" << std::endl;
	}
	if (ADTemp > 0)
	{
		ShowMessageMonster(nameMonster());
		std::cout << ": tu vas Mourire" << std::endl;
	}
	if (echec == 0)
	{
		ShowMessageMonster(enemy.nameMonster());
		std::cout << ": seulement ? Tu es faible" << std::endl;
	}
}

void Monster::Rage(Monster& enemy)
{
	int ragePoint;
	std::random_device rand;
	std::default_random_engine e2(rand());
	std::poisson_distribution<> nbrand(5);;
	ragePoint = nbrand(e2);

	ADTemp += ragePoint;
	Attack(enemy);
}

void Monster::Pary()
{
	int paryPoint;
	std::random_device rand;
	std::default_random_engine e2(rand());
	std::poisson_distribution<> nbrand(5);;
	paryPoint = nbrand(e2);

	DPTemp += paryPoint;
	ShowMessageMonster(nameMonster());
	std::cout << ": essaie de me toucher si tu peux" << std::endl;
}

void Monster::AutoHeal()
{
	giveHP();
}

void Monster::ShowMessageMonster(std::string message)
{
	HANDLE terminal = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(terminal, color);
	std::cout << message;
	SetConsoleTextAttribute(terminal, 15);
}
#pragma endregion












