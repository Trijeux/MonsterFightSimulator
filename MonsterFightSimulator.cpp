#include <iostream>
#include "ClasseMonster.h"

int main()
{
	Monster monster1(50, 25, 30, 5, Orc);
	Monster monster2(25, 10, 20, 10, Troll);
	Monster monster3(10, 5, 10, 25, Goblin);

	/*monster1.State();
	monster2.State();
	monster3.State();

	monster1.Attack(monster2);
	monster2.Attack(monster1);*/

	int test = 0;
	do
	{
		monster1.State();
		monster1.Pary();
		monster1.State();
		monster1.EndOfRound();
		test++;
	}
	while (test < 5);
}
