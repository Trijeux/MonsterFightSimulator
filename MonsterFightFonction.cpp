#include "MonsterFightFonction.h"
#include <iostream>
#include <random>
#include <string>

#include "ClasseMonster.h"

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
	bool validInput = true;
	bool validNumber = false;
	std::string inputString;

	//Checks if the user enters valid data
	do
	{
		do
		{
			validInput = true;
			validNumber = false;
			system("cls");
			std::cout << "Veuillez choisire la Race du premier monstre Orc(0), Troll(1) ou Goblin(2) :" << std::endl;
			std::getline(std::cin, inputString);

			// Check if it's a number or not
			if (inputString.length() == 0 || !std::all_of(inputString.begin(), inputString.end(), ::isdigit))
			{
				std::cout << inputString << " n'est pas un nombre" << std::endl;
				validInput = false;
			}
			if (validInput)
			{
				// Checks if number is between 1 and array size
				inputPlayer = std::stoi(inputString);
				if (inputPlayer > Race(2) || inputPlayer < 0)
				{
					validNumber = true;
					std::cout << "Ce n'est pas un chiffre entre " << Race(0) << "-" << Race(2) << std::endl;
				}
			}
		} while (validNumber);

	} while (!validInput);
	return inputPlayer;
}

int ChoiseRaceMonster2()
{
	int inputPlayer;
	bool validInput = true;
	bool validNumber = false;
	std::string inputString;

	//Checks if the user enters valid data
	do
	{
		do
		{
			validInput = true;
			validNumber = false;
			std::cout << "ET le deuxieme Orc(0), Troll(1) ou Goblin(2) :" << std::endl;
			std::getline(std::cin, inputString);

			// Check if it's a number or not
			if (inputString.length() == 0 || !std::all_of(inputString.begin(), inputString.end(), ::isdigit))
			{
				std::cout << inputString << " n'est pas un nombre" << std::endl;
				validInput = false;
			}
			if (validInput)
			{
				// Checks if number is between 1 and array size
				inputPlayer = std::stoi(inputString);
				if (inputPlayer > Race(2) || inputPlayer < 0)
				{
					validNumber = true;
					std::cout << "Ce n'est pas un chiffre entre " << Race(0) << "-" << Race(2) << std::endl;
				}
			}
		} while (validNumber);

	} while (!validInput);
	return inputPlayer;
}

int RandomStateAD()
{
	std::random_device rand;
	std::default_random_engine e2(rand());
	std::poisson_distribution<> nbrand(20);
	return nbrand(e2);
}

int RandomStateDP()
{
	std::random_device rand;
	std::default_random_engine e2(rand());
	std::poisson_distribution<> nbrand(10);
	return nbrand(e2);
}

int RandomStateS()
{
	std::random_device rand;
	std::default_random_engine e2(rand());
	std::poisson_distribution<> nbrand(5);
	return nbrand(e2);
}