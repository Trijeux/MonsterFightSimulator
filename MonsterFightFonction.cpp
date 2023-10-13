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

int ChoiseRaceMonster1(bool resteConsoleForNewGame)
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
			std::cout << "Veuillez choisire la Race de ton monstre :" << std::endl;
			std::cout << "Orc (" << Orc << ")" << std::endl;
			std::cout << "Troll (" << Troll << ")" << std::endl;
			std::cout << "Goblin (" << Goblin << ")" << std::endl;
			std::cout << "Centaur (" << Centaur << ")" << std::endl;
			std::cout << "Dullahan (" << Dullahan << ")" << std::endl;
			std::cout << "Ogre (" << Ogre << ")" << std::endl;
			std::cout << "Werewolf (" << Werewolf << ")" << std::endl;
			std::cout << "Elf (" << Elf << ")" << std::endl;
			std::cout << "Harpy (" << Harpy << ")" << std::endl;
			std::cout << "Salamander (" << Salamander << ")" << std::endl;
			std::getline(std::cin, inputString);


			// Check if it's a number or not
			if (inputString.length() == 0 || !std::all_of(inputString.begin(), inputString.end(), ::isdigit))
			{
				std::cout << inputString << " n'est pas un nombre" << std::endl;
				if (resteConsoleForNewGame)
				{
					system("cls");
					resteConsoleForNewGame = false;
				}
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
					system("Pause");
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
	bool clsExecuted = false;
	//Checks if the user enters valid data
	do
	{
		do
		{
			validInput = true;
			validNumber = false;
			if (!clsExecuted)
			{
				clsExecuted = true;
			}
			std::cout << "Et ton adversaire :" << std::endl;
			std::cout << "Orc (" << Orc << ")" << std::endl;
			std::cout << "Troll (" << Troll << ")" << std::endl;
			std::cout << "Goblin (" << Goblin << ")" << std::endl;
			std::cout << "Centaur (" << Centaur << ")" << std::endl;
			std::cout << "Dullahan (" << Dullahan << ")" << std::endl;
			std::cout << "Ogre (" << Ogre << ")" << std::endl;
			std::cout << "Werewolf (" << Werewolf << ")" << std::endl;
			std::cout << "Elf (" << Elf << ")" << std::endl;
			std::cout << "Harpy (" << Harpy << ")" << std::endl;
			std::cout << "Salamander (" << Salamander << ")" << std::endl;
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
					std::cout << "Ce n'est pas un chiffre entre " << Race(0) << "-" << Race(8) << std::endl;
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