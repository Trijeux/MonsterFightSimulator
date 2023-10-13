#include <iostream>
#include "ClasseMonster.h"

int main()
{
	Monster monster1(100, 30, 30, 5, Orc);
	Monster monster2(100, 10, 10, 10, Troll);
	Monster Rounder(0,0, 0);

	/*monster1.State();
	monster2.State();*/

	//monster1.Attack(monster2);
	//monster2.Attack(monster1);

	bool test = true;
	do
	{
		Rounder.Round();
		monster1.State();
		monster2.State();
		monster2.AutoHeal();
		monster2.State();
		monster1.Attack(monster2);
		Rounder.EndOfRound(monster1, monster2);
		test = Rounder.DeadOrNot(monster1, monster2);
	} while (test);
}
