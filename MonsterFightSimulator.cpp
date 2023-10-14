#include <iostream>
#include <random>
#include <windows.h>
#include "ClasseMonster.h"
#include "MonsterFightFonction.h"

int main()
{
#pragma region  Local Variable In Main
	bool gameContinue = true;
	bool resetConsoleForNewGame = false;
#pragma endregion

#pragma region Start And Rule
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
#pragma endregion

#pragma region Game
	do
	{
#pragma region Local Variable In Game
		int priority = 0;
		bool endBattle = true;
		bool alteration = false;
		int alterationenemy = 0;
		char playerInputContinue;
#pragma endregion

		//Reset the rounds
		Round(true);

		//The player chooses the name of monster1 and monster2
		int playerChoice1 = ChoiceRaceMonster1(resetConsoleForNewGame);
		int playerChoice2 = ChoiceRaceMonster2();

#pragma region Monster Stats Random
		//Monster1 Statistics
		int statADMonster1 = RandomStatAD();
		int statDPMonster1 = RandomStatDP();
		int statSPMonster1 = RandomStatSP();

		//Monster2 Statistics
		int statADMonster2 = RandomStatAD();
		int statDPMonster2 = RandomStatDP();
		int statSPMonster2 = RandomStatSP();
#pragma endregion

		system("cls");


		Monster monster1(100, statADMonster1, statDPMonster1, statSPMonster1, Race(playerChoice1), 11);
		Monster monster2(100, statADMonster2, statDPMonster2, statSPMonster2, Race(playerChoice2), 12);


#pragma region Check Priority
		//Check if the speed of both shows its equal
		if (monster1.getSP() == monster2.getSP())
		{
			priority = RandPriority();
		}
		
		//Check who does an action first
		if (monster1.getSP() > monster2.getSP())
		{
			priority = 1;
		}
		if (monster1.getSP() < monster2.getSP())
		{
			priority = 2;
		}
#pragma endregion

#pragma region Battle
		do
		{
			Round();
			std::cout << std::endl;

			//Causes that each round the monster attacks first each turn except the first turn
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

			//Monster1 has priority and the battle is not over
			if (endBattle && priority == 1)
			{
				monster1.StatMonster();
				monster1.Choice(monster2);
				std::cout << std::endl;
				endBattle = monster2.DeadOrNot();

				//check that the battle is not over
				if (endBattle)
				{
					monster2.StatMonster();
					monster2.Choice(monster1);
					std::cout << std::endl;
					endBattle = monster1.DeadOrNot();
				}

				alterationenemy = 2;
			}

			//Monster2 has priority and the battle is not over
			if (endBattle && priority == 2)
			{
				monster2.StatMonster();
				monster2.Choice(monster1);
				std::cout << std::endl;
				endBattle = monster1.DeadOrNot();

				//check that the battle is not over
				if (endBattle)
				{
					monster1.StatMonster();
					monster1.Choice(monster2);
					std::cout << std::endl;
					endBattle = monster2.DeadOrNot();
				}

				alterationenemy = 1;
			}

			//Complete the Round
			monster1.EndOfRound();
			monster2.EndOfRound();

			std::cout << "Fin du round" << std::endl << "State :" << std::endl;
			std::cout << std::endl;

			monster1.StatMonster();
			monster2.StatMonster();

			system("Pause");
			system("cls");

		} while (endBattle);
#pragma endregion

		//Say who to win
		monster1.EndGameMessage();
		monster2.EndGameMessage();
		system("Pause");
		system("cls");



		std::cout << "Veux-tu Recommencer oui(y) ou non(n) : ";
		std::cin >> playerInputContinue;

		//Checks if the player wants to play again
		if (playerInputContinue == 'n')
		{
			gameContinue = false;
		}
		else
		{
			resetConsoleForNewGame = true;
		}

	} while (gameContinue);
#pragma endregion
}
