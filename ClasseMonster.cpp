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

#pragma region Method Public
void Monster::Choice(Monster& enemy)
{
	std::random_device rand;
	std::default_random_engine e2(rand());
	std::uniform_int_distribution<> nbRand(1, 4);
	int choice = nbRand(e2);


	if (choice == 1)
	{
		std::cout << "Attaque" << std::endl;
		attack(enemy);
	}
	if (choice == 2)
	{
		std::cout << "rage" << std::endl;
		rage(enemy);

	}
	if (choice == 3)
	{
		std::cout << "Parer" << std::endl;
		parry();

	}
	if (choice == 4)
	{
		std::cout << "Soin" << std::endl;
		autoHeal();
	}
}

void Monster::StatMonster()
{
	std::cout << "Race :";
	showMessageMonster(nameMonster());
	std::cout << " / Attaque :" << AD + ADBonus << " / Defense :" << DP + DPBonus << " / Vitesse :" << S << " / Vie :" << HP << std::endl;
}

void Monster::EndOfRound()
{
	if (DPBonus > 0 || ADBonus > 0)
	{
		resetDPBonus();
		resetADBonus();
	}
}

void Monster::EndGameMessage()
{
	if (HP <= 0)
	{
		showMessageMonster(nameMonster());
		std::cout << " a perdu" << std::endl;
	}
	
	if (HP > 0)
	{
		showMessageMonster(nameMonster());
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

#pragma region Method Private
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
		return "Centaure";
	case Dullahan:
		return "Dullahan";
	case Ogre:
		return "Ogre";
	case Werewolf:
		return "Loup-Garou";
	case Elf:
		return "Elf";
	case Harpy:
		return "Harpy";
	case Salamander:
		return "Salamandre";
	default:
		return "Invalide";
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
		std::random_device rand;
		std::default_random_engine e2(rand());
		std::poisson_distribution<> nbRand(5);
		int healPoint = nbRand(e2);

		HP += healPoint;
		
		if (HP > HPMax)
		{
			HP = HPMax;
		}
		showMessageMonster(nameMonster());
		std::cout << ": ca fait du bien" << std::endl;
	}
	else
	{
		std::cout << "HP deja au Max" << std::endl;
	}
}

void Monster::resetDPBonus()
{
	DPBonus = 0;
}

void Monster::resetADBonus()
{
	ADBonus = 0;
}

void Monster::attack(Monster& enemy)
{
	bool miss = true;
	
	if (AD + ADBonus > enemy.DP + enemy.DPBonus)
	{
		int domage = AD + ADBonus - enemy.DP + enemy.DPBonus;
		enemy.takeDomage(domage);
		miss = false;
	}
	if (ADBonus <= 0)
	{
		showMessageMonster(nameMonster());
		std::cout << ": prend ca" << std::endl;
	}
	if (ADBonus > 0)
	{
		showMessageMonster(nameMonster());
		std::cout << ": tu vas mourir" << std::endl;
	}
	if (miss)
	{
		showMessageMonster(enemy.nameMonster());
		std::cout << ": seulement ? Tu es faible" << std::endl;
	}
}

void Monster::rage(Monster& enemy)
{
	std::random_device rand;
	std::default_random_engine e2(rand());
	std::poisson_distribution<> nbRand(5);;
	int ragePoint = nbRand(e2);

	ADBonus += ragePoint;
	attack(enemy);
}

void Monster::parry()
{
	std::random_device rand;
	std::default_random_engine e2(rand());
	std::poisson_distribution<> nbRand(5);;
	int parryPoint = nbRand(e2);

	DPBonus += parryPoint;
	showMessageMonster(nameMonster());
	std::cout << ": essaie de me toucher si tu peux" << std::endl;
}

void Monster::autoHeal()
{
	giveHP();
}

void Monster::showMessageMonster(std::string message)
{
	HANDLE terminal = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(terminal, color);
	std::cout << message;
	SetConsoleTextAttribute(terminal, 15);
}
#pragma endregion












