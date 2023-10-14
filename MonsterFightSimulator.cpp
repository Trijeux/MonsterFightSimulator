#include <iostream>
#include <random>
#include <windows.h>
#include "ClasseMonster.h"
#include "MonsterFightFonction.h"

int main()
{
	bool gameContinue = true;
	bool resetConsoleForNewGame = false;

	std::cout << "Bonjour, bienvenu dans Monster Fight Simulateur" << std::endl;
	std::cout << std::endl;
	std::cout << "Le but est que vous choisissiez votre";
	ShowMessage(" monstre ", 11);
	std::cout << "et votre";
	ShowMessage(" adversaire ", 12);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Vous allez vous affronter (tout est automatique) et voir qui vas gagner" << std::endl;
	std::cout << std::endl;

	//Game
	do
	{
#pragma region Variable Local Game
		int priority = 0;
		bool endBattle = true;
		bool alteration = false;
		int alterationenemy = 0;
		char playerInputContinue;
#pragma endregion

		Round(true);

#pragma region Choice Race
		int playerChoice1 = ChoiceRaceMonster1(resetConsoleForNewGame);
		int playerChoice2 = ChoiceRaceMonster2();
#pragma endregion

#pragma region Creat Stat Monster
		int statADMonster1 = RandomStatAD();

		int statDPMonster1 = RandomStatDP();

		int statSMonster1 = RandomStatS();

		int statADMonster2 = RandomStatAD();

		int statDPMonster2 = RandomStatDP();

		int statSMonster2 = RandomStatS();
#pragma endregion

		system("cls");

#pragma region Monster
		Monster monster1(100, statADMonster1, statDPMonster1, statSMonster1, Race(playerChoice1), 11);
		Monster monster2(100, statADMonster2, statDPMonster2, statSMonster2, Race(playerChoice2), 12);

#pragma endregion


		if (monster1.getS() == monster2.getS())
		{
			priority = RandPriority();
		}
		

		if (monster1.getS() > monster2.getS())
		{
			priority = 1;
		}

		if (monster1.getS() < monster2.getS())
		{
			priority = 2;
		}

#pragma region Battle
		do
		{
			Round();
			std::cout << std::endl;

			if (alteration)
			{
				if (alterationenemy == 1)
				{
					priority = 1;
				}
				if (alterationenemy == 2)
				{
					priority = 2;
				}
			}

			else
			{
				alteration = true;
			}

			if (endBattle && priority == 1)
			{
				monster1.StatMonster();
				monster1.Choice(monster2);
				std::cout << std::endl;
				endBattle = monster2.DeadOrNot();
				if (endBattle)
				{
					monster2.StatMonster();
					monster2.Choice(monster1);
					std::cout << std::endl;
					endBattle = monster1.DeadOrNot();
				}
				alterationenemy = 2;
			}


			if (endBattle && priority == 2)
			{
				monster2.StatMonster();
				monster2.Choice(monster1);
				std::cout << std::endl;
				endBattle = monster1.DeadOrNot();
				if (endBattle)
				{
					monster1.StatMonster();
					monster1.Choice(monster2);
					std::cout << std::endl;
					endBattle = monster2.DeadOrNot();
				}
				alterationenemy = 1;
			}

			monster1.EndOfRound();
			monster2.EndOfRound();

			std::cout << "Fin du round" << std::endl << "State :" << std::endl;
			std::cout << std::endl;
			monster1.StatMonster();
			monster2.StatMonster();

			system("Pause");
			system("cls");

		} while (endBattle);
		monster1.EndGameMessage();
		monster2.EndGameMessage();
		system("Pause");
		system("cls");
#pragma endregion

#pragma region EndGame
		std::cout << "Veux-tu Recommencer oui(y) ou non(n) : ";
		std::cin >> playerInputContinue;

		if (playerInputContinue == 'n')
		{
			gameContinue = false;
		}
		else
		{
			resetConsoleForNewGame = true;
		}
#pragma endregion
	} while (gameContinue);
}
