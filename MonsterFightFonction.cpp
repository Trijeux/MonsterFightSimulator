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

	//Returns 1 or 2 to know who performs an action first
	return nbRand(e2);
}

int ChoiceRaceMonster1(bool resetConsoleForNewGame)
{
#pragma region  Local Variable
	int inputPlayer;
	bool validInput = true;
	bool validNumber = false;
	std::string inputString;
#pragma endregion

#pragma region input checker
	do
	{
		do
		{

#pragma region Player choice
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

			//Player input
			std::getline(std::cin, inputString);
#pragma endregion

			//Check if it's a number or not
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

			//Checks if it is a number between the given values
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
#pragma endregion

	//Return player Input (The Race Monster)
	return inputPlayer;
}

int ChoiceRaceMonster2()
{
#pragma region  Local Variable
	int inputPlayer;
	bool validInput = true;
	bool validNumber = false;
	std::string inputString;
	bool clsExecuted = false;
#pragma endregion

#pragma region input checker
	do
	{
		do
		{
			//Clear the console if it hasn't been done yet
			if (!clsExecuted)
			{
				clsExecuted = true;
			}

#pragma region Player choice
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

			//Player input
			std::getline(std::cin, inputString);
#pragma endregion

			//Check if it's a number or not
			if (inputString.length() == 0 || !std::all_of(inputString.begin(), inputString.end(), ::isdigit))
			{
				std::cout << inputString << " n'est pas un nombre" << std::endl;
				validInput = false;
			}

			//Checks if it is a number between the given values
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
#pragma endregion

	//Return player Input (The Race Monster)
	return inputPlayer;
}

int RandomStatAD()
{
	std::random_device rand;
	std::default_random_engine e2(rand());
	std::poisson_distribution<> nbRand(20);

	//Return a number between 0 and 40 with a greater chance of being closer to 20 which is the attack statistic
	return nbRand(e2);
}

int RandomStatDP()
{
	std::random_device rand;
	std::default_random_engine e2(rand());
	std::poisson_distribution<> nbRand(10);

	//Return a number between 0 and 20 with a greater chance of being close to 10 which is the defense statistic
	return nbRand(e2);
}

int RandomStatSP()
{
	std::random_device rand;
	std::default_random_engine e2(rand());
	std::poisson_distribution<> nbRand(5);

	//Return a number between 0 and 10 with a greater chance of being close to 5 which is the speed statistic
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