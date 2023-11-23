#include "ClasseMonster.h"
#include <iostream>
#include <random>
#include <windows.h>

#pragma region Constructor
Monster::Monster(int _healthPoints, int _attackDamage, int _defensePoints, int _speed, Race _monsterRace, int _color) : HP(_healthPoints), AP(_attackDamage), DP(_defensePoints), SP(_speed), monsterRace(_monsterRace), color(_color) {}

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

	//Give the number of the action
	int choice = nbRand(e2);


	if (choice == 1)
	{
		std::cout << "Action : Attaque" << std::endl;
		attack(enemy);
	}
	if (choice == 2)
	{
		std::cout << "Action : Rage" << std::endl;
		rage(enemy);

	}
	if (choice == 3)
	{
		std::cout << "Action : Parer" << std::endl;
		parry();

	}
	if (choice == 4)
	{
		std::cout << "Action : Soin" << std::endl;
		heal();
	}
}

void Monster::StatMonster()
{
	std::cout << "Race :";
	showMessageMonster(nameMonster());
	std::cout << " / Attaque :" << AP + ADBonus << " / Defense :" << DP + DPBonus << " / Vitesse :" << SP << " / Vie :" << HP << std::endl;
}

void Monster::EndOfRound()
{
	//Check if the monsters had attack bonuses
	if (ADBonus > 0)
	{
		resetADBonus();
	}
	//Check if the monsters had defense bonuses
	if (DPBonus > 0)
	{
		resetDPBonus();
	}
}

void Monster::EndGameMessage()
{
	//Checks if the monster is dead to say he lost
	if (HP <= 0)
	{
		showMessageMonster(nameMonster());
		std::cout << " a perdu" << std::endl;
	}

	//Check if the monster is alive to say he has won
	if (HP > 0)
	{
		showMessageMonster(nameMonster());
		std::cout << " a gagne" << std::endl;
	}
}

bool Monster::DeadOrNot()
{
	//Check if the monster is dead
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

void Monster::takeDamage(int damage)
{
	HP -= damage;
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
	int damage = 0;
	bool miss = true;

	//Checks if the attacking monster has more attack than the enemy's defense
	if (AP + ADBonus > enemy.DP + enemy.DPBonus)
	{
		damage = AP + ADBonus - enemy.DP + enemy.DPBonus;
		enemy.takeDamage(damage);
		miss = false;
	}

	//Check if he has an attack bonus
	if (ADBonus <= 0)
	{
		showMessageMonster(nameMonster());
		std::cout << ": prend ca" << std::endl;
		std::cout << "-" << damage << " de vie a ";
		enemy.showMessageMonster(enemy.nameMonster());
		std::cout << std::endl;
	}
	if (ADBonus > 0)
	{
		showMessageMonster(nameMonster());
		std::cout << ": tu vas mourir" << std::endl;
		std::cout << "-" << damage << " de vie a ";
		enemy.showMessageMonster(enemy.nameMonster());
		std::cout << std::endl;
	}

	//Checks if the monster missed the attack
	if (miss)
	{
		std::cout << "Echec de l'attaque" << std::endl;
		enemy.showMessageMonster(enemy.nameMonster());
		std::cout << ": seulement ? Tu es faible" << std::endl;
	}
}

void Monster::rage(Monster& enemy)
{
	std::random_device rand;
	std::default_random_engine e2(rand());
	std::poisson_distribution<> nbRand(5);;

	//Gives a number between 0 and 10 with a greater chance of being closer to 5 for the attack bonus
	int ragePoint = nbRand(e2);

	//Add the bonus to the statistic
	ADBonus += ragePoint;

	std::cout << "Bonus d'attaque de +" << ragePoint << std::endl;
	attack(enemy);
}

void Monster::parry()
{
	std::random_device rand;
	std::default_random_engine e2(rand());
	std::poisson_distribution<> nbRand(5);

	//Gives a number between 0 and 10 with a greater chance of being closer to 5 for the defense bonus
	int parryPoint = nbRand(e2);

	//Add the bonus to the statistic
	DPBonus += parryPoint;

	std::cout << "Bonus de defense de +" << parryPoint << std::endl;
	showMessageMonster(nameMonster());
	std::cout << ": essaie de me toucher si tu peux" << std::endl;
}

void Monster::heal()
{

	//Check if life is lower than max
	if (HP < HPMax)
	{
		std::random_device rand;
		std::default_random_engine e2(rand());
		std::poisson_distribution<> nbRand(5);

		//Gives a number between 0 and 10 with a greater chance of being closer to 5 for the Heal Point
		int healPoint = nbRand(e2);

		//Add life points
		HP += healPoint;

		//Check if life is bigger than max
		if (HP > HPMax)
		{
			HP = HPMax;
		}
		showMessageMonster(nameMonster());
		std::cout << ": ca fait du bien" << std::endl;
		std::cout << "+" << healPoint << " de vie" << std::endl;
	}
	else
	{
		std::cout << "HP deja au Max" << std::endl;
	}
}

void Monster::showMessageMonster(std::string message)
{
	HANDLE terminal = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(terminal, color);
	std::cout << message;
	SetConsoleTextAttribute(terminal, 15);
}
#pragma endregion












