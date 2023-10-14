#include "MonsterFightFonction.h"
#include <iostream>
#include <random>
#include <string>
#include <windows.h>
#include "ClasseMonster.h"

int RandPriority()
{
	std::random_device rand;
	std::default_random_engine e2(rand());
	std::uniform_int_distribution<> nbRand(1, 2);
	return nbRand(e2);
}

int ChoiceRaceMonster1(bool resetConsoleForNewGame)
{
	int inputPlayer;
	bool validInput = true;
	bool validNumber = false;
	std::string inputString;

	
	do
	{
		do
		{
			validInput = true;
			validNumber = false;
			std::cout << "Veuillez choisir la race de ton monstre :" << std::endl;
			std::cout << "Orc (" << Orc << ")" << std::endl;
			std::cout << "Troll (" << Troll << ")" << std::endl;
			std::cout << "Goblin (" << Goblin << ")" << std::endl;
			std::cout << "Centaure (" << Centaur << ")" << std::endl;
			std::cout << "Dullahan (" << Dullahan << ")" << std::endl;
			std::cout << "Ogre (" << Ogre << ")" << std::endl;
			std::cout << "Loup-Garou (" << Werewolf << ")" << std::endl;
			std::cout << "Elf (" << Elf << ")" << std::endl;
			std::cout << "Harpy (" << Harpy << ")" << std::endl;
			std::cout << "Salamandre (" << Salamander << ")" << std::endl;
			std::getline(std::cin, inputString);


			
			if (inputString.length() == 0 || !std::all_of(inputString.begin(), inputString.end(), ::isdigit))
			{
				std::cout << inputString << " n'est pas un nombre" << std::endl;
				if (resetConsoleForNewGame)
				{
					system("cls");
					resetConsoleForNewGame = false;
				}
				validInput = false;
			}
			if (validInput)
			{
				
				inputPlayer = std::stoi(inputString);
				if (inputPlayer > Race(9) || inputPlayer < 0)
				{
					validNumber = true;
					std::cout << "Ce n'est pas un chiffre entre 0-9" << std::endl;
					system("Pause");
				}
			}
		} while (validNumber);

	} while (!validInput);
	return inputPlayer;
}

int ChoiceRaceMonster2()
{
	int inputPlayer;
	bool validInput = true;
	bool validNumber = false;
	std::string inputString;
	bool clsExecuted = false;

	
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
			std::cout << std::endl;
			std::cout << "Et ton adversaire :" << std::endl;
			std::cout << "Orc (" << Orc << ")" << std::endl;
			std::cout << "Troll (" << Troll << ")" << std::endl;
			std::cout << "Goblin (" << Goblin << ")" << std::endl;
			std::cout << "Centaure (" << Centaur << ")" << std::endl;
			std::cout << "Dullahan (" << Dullahan << ")" << std::endl;
			std::cout << "Ogre (" << Ogre << ")" << std::endl;
			std::cout << "Loup-Garou (" << Werewolf << ")" << std::endl;
			std::cout << "Elf (" << Elf << ")" << std::endl;
			std::cout << "Harpy (" << Harpy << ")" << std::endl;
			std::cout << "Salamandre (" << Salamander << ")" << std::endl;
			std::getline(std::cin, inputString);

			
			if (inputString.length() == 0 || !std::all_of(inputString.begin(), inputString.end(), ::isdigit))
			{
				std::cout << inputString << " n'est pas un nombre" << std::endl;
				validInput = false;
			}
			if (validInput)
			{
				
				inputPlayer = std::stoi(inputString);
				if (inputPlayer > Race(9) || inputPlayer < 0)
				{
					validNumber = true;
					std::cout << "Ce n'est pas un chiffre entre 0-9" << std::endl;
				}
			}
		} while (validNumber);

	} while (!validInput);
	return inputPlayer;
}

int RandomStatAD()
{
	std::random_device rand;
	std::default_random_engine e2(rand());
	std::poisson_distribution<> nbRand(20);
	return nbRand(e2);
}

int RandomStatDP()
{
	std::random_device rand;
	std::default_random_engine e2(rand());
	std::poisson_distribution<> nbRand(10);
	return nbRand(e2);
}

int RandomStatS()
{
	std::random_device rand;
	std::default_random_engine e2(rand());
	std::poisson_distribution<> nbRand(5);
	return nbRand(e2);
}

void Round(bool startBattle)
{
	static int nbRound;
	if (startBattle)
	{
		nbRound = 0;
	}
	else
	{
		nbRound += 1;
		std::cout << "Round : " << nbRound << std::endl;
	}
}

void ShowMessage(std::string message, int color)
{
	HANDLE terminal = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(terminal, color);
	std::cout << message;
	SetConsoleTextAttribute(terminal, 15);
}