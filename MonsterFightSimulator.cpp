#include <iostream>
#include <random>
#include "ClasseMonster.h"
#include "MonsterFightFonction.h"

int main()
{

	bool gameContinue = true;

	std::cout << "Bonjour, bienvenu dans Monster Fight Simulateur" << std::endl;
	system("Pause");

	//Game
	do
	{
#pragma region variable local Game
		int priority = 0;
		bool EndBattle = true;
		char playerInputContinue;
#pragma endregion

#pragma region Choix Race
		int joueurChoise1 = ChoiseRaceMonster1();
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
		Monster monster1(100, statADMonster1, statDPMonster1, statSMonster1, Race(joueurChoise1));
		Monster monster2(100, statADMonster2, statDPMonster2, statSMonster2, Race(joueurChoise2));
		Monster Rounder(0, 0, 0);
#pragma endregion

#pragma region Battle
		// Battle
		do
		{
			std::cout << "---------------------" << std::endl;
			Rounder.Round();
			if (monster1.getS() == monster2.getS())
			{
				priority = randpriority();
			}
			if (monster1.getS() > monster2.getS() || priority == 1)
			{
				monster1.Statemonster1();
				monster1.Choix(monster2, priority);
				EndBattle = Rounder.DeadOrNot(monster1, monster2);
				if (EndBattle)
				{
					monster2.Statemonster2();
					monster2.Choix(monster1, priority);
				}
			}
			if (monster1.getS() < monster2.getS() || priority == 2)
			{
				monster2.Statemonster2();
				monster2.Choix(monster1, priority);
				EndBattle = Rounder.DeadOrNot(monster1, monster2);
				if (EndBattle)
				{
					monster1.Statemonster1();
					monster1.Choix(monster2, priority);
				}
			}

			Rounder.EndOfRound(monster1, monster2);
			if (EndBattle)
			{
				EndBattle = Rounder.DeadOrNot(monster1, monster2);
			}

			std::cout << "Fin du round." << std::endl << "State :" << std::endl;
			monster1.Statemonster1();
			monster2.Statemonster2();

			system("Pause");
			system("cls");
		} while (EndBattle);
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
			std::cout << "Ok c'est repartie" << std::endl;
		}
#pragma endregion
	}
	while (gameContinue);
}
