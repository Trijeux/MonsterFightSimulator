#include <iostream>
#include <random>
#include "ClasseMonster.h"

int main()
{
	bool gameContinue = true;
	std::cout << "Bonjour, bienvenu dans Monster Fight Simulateur" << std::endl;
	do
	{
		char playerInputContinue;
		int joueurChoise1;
		int joueurChoise2;
		std::cout << "Veuillez choisire la Race du premier monstre Orc(0), Troll(1) ou Goblin(2) :" << std::endl;
		std::cin >> joueurChoise1;
		std::cout << "ET le deuxieme Orc(0), Troll(1) ou Goblin(2) :";
		std::cin >> joueurChoise2;
		system("cls");

		Monster monster1(100, 30, 20, 10, Race(joueurChoise1));
		Monster monster2(100, 30, 20, 10, Race(joueurChoise2));
		Monster Rounder(0, 0, 0);

		//monster1.Attack(monster2);
		//monster2.Attack(monster1);

		bool EndBattle = true;
		int priority;
		do
		{
			std::cout << "---------------------" << std::endl;
			Rounder.Round();
			if (monster1.getS() == monster2.getS())
			{
				std::random_device rand;
				std::default_random_engine e2(rand());
				std::uniform_int_distribution<> nbrand(1, 2);
				priority = nbrand(e2);
			}
			if (monster1.getS() > monster2.getS() || priority == 1)
			{
				monster1.State();
				monster1.Choix(monster2);
				EndBattle = Rounder.DeadOrNot(monster1, monster2);
				if (EndBattle)
				{
					monster2.State();
					monster2.Choix(monster1);
				}
			}
			if (monster1.getS() < monster2.getS() || priority == 2)
			{
				monster2.State();
				monster2.Choix(monster1);
				EndBattle = Rounder.DeadOrNot(monster1, monster2);
				if (EndBattle)
				{
					monster1.State();
					monster1.Choix(monster2);
				}
			}
			/*	std::cout << "Apres action avant reset" << std::endl;
		monster1.State();
		std::cout << "Apres action avant reset" << std::endl;
		monster2.State();*/
			Rounder.EndOfRound(monster1, monster2);
			if (EndBattle)
			{
				EndBattle = Rounder.DeadOrNot(monster1, monster2);
			}
		} while (EndBattle);
		std::cout << "Veux tu Recomencer oui(y) ou non(n) : ";
		std::cin >> playerInputContinue;
		if (playerInputContinue == 'n')
		{
			gameContinue = false;
		}
	}
	while (gameContinue);
}
