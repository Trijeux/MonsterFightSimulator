#include <iostream>
#include <random>
#include <windows.h>

#include "ClasseMonster.h"
#include "MonsterFightFonction.h"

int main()
{
	bool gameContinue = true;
	bool resteConsoleForNewGame = false;

	std::cout << "Bonjour, bienvenu dans Monster Fight Simulateur" << std::endl;
	std::cout << "Le but c'est que vous choisisez votre";
	ShowMessage(" monstre ", 11) ;
	std::cout << "et votre";
	ShowMessage(" adversaire ", 12);
	std::cout << std::endl;
	std::cout << "Vous allez vous affronter (tout est automatise) et voir qui vas gagner" << std::endl;

	//Game
	do
	{
#pragma region variable local Game
		int priority = 0;
		bool EndBattle = true;
		char playerInputContinue;
#pragma endregion

#pragma region Choix Race
		int joueurChoise1 = ChoiseRaceMonster1(resteConsoleForNewGame);
		int joueurChoise2 = ChoiseRaceMonster2();
#pragma endregion

#pragma region Creat Stat Monster
		int statADMonster1 = RandomStateAD();

		int statDPMonster1 = RandomStateDP();

		int statSMonster1 = RandomStateS();

		int statADMonster2 = RandomStateAD();

		int statDPMonster2 = RandomStateDP();

		int statSMonster2 = RandomStateS();
#pragma endregion

		system("cls");

#pragma region Monster
		Monster monster1(100, statADMonster1, statDPMonster1, statSMonster1, Race(joueurChoise1), 11);
		Monster monster2(100, statADMonster2, statDPMonster2, statSMonster2, Race(joueurChoise2), 12);

#pragma endregion

#pragma region Battle
		// Battle
		do
		{
			std::cout << "---------------------" << std::endl;
			Round();
			if (monster1.getS() == monster2.getS())
			{
				priority = randpriority();
			}

			if (!EndBattle && (monster1.getS() > monster2.getS() || priority == 1))
			{
				monster1.Statemonster();
				monster1.Choix(monster2);
				EndBattle = monster2.DeadOrNot();
				if (EndBattle)
				{
					monster2.Statemonster();
					monster2.Choix(monster1);
				}
				EndBattle = monster1.DeadOrNot();
			}


			if (!EndBattle && (monster1.getS() < monster2.getS() || priority == 2))
			{
				monster2.Statemonster();
				monster2.Choix(monster1);
				EndBattle = monster1.DeadOrNot();
				if (EndBattle)
				{
					monster1.Statemonster();
					monster1.Choix(monster2);
				}
				EndBattle = monster2.DeadOrNot();
			}

			monster1.EndOfRound();
			monster2.EndOfRound();

			std::cout << "Fin du round." << std::endl << "State :" << std::endl;
			monster1.Statemonster();
			monster2.Statemonster();

			system("Pause");
			system("cls");

		} while (EndBattle);
		monster1.EndGameMessage();
		monster2.EndGameMessage();
#pragma endregion

#pragma region EndGame
		std::cout << "Veux tu Recomencer oui(y) ou non(n) : ";
		std::cin >> playerInputContinue;

		if (playerInputContinue == 'n')
		{
			gameContinue = false;
		}
		else
		{
			resteConsoleForNewGame = true;
		}
#pragma endregion
	} while (gameContinue);
}
