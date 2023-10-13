#include "MonsterFightFonction.h"
#include <iostream>
#include <random>

int randpriority()
{
	std::random_device rand;
	std::default_random_engine e2(rand());
	std::uniform_int_distribution<> nbrand(1, 2);
	return nbrand(e2);
}

int ChoiseRaceMonster1()
{
	int inputPlayer;
	std::cout << "Veuillez choisire la Race du premier monstre Orc(0), Troll(1) ou Goblin(2) :" << std::endl;
	std::cin >> inputPlayer;
	return inputPlayer;
}

int ChoiseRaceMonster2()
{
	int inputPlayer;
	std::cout << "ET le deuxieme Orc(0), Troll(1) ou Goblin(2) :";
	std::cin >> inputPlayer;
	return inputPlayer;
}