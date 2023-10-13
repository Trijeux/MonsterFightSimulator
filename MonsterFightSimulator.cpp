#include <iostream>
#include "ClasseMonster.h"

int main()
{
	Monster monster1(50, 25, 30, 5, Orc);
	Monster monster2(25, 10, 20, 10, Troll);
	Monster monstervoid(0, 0, 0, 0, Nothing);

	/*monster1.State();
	monster2.State();*/

	//monster1.Attack(monster2);
	//monster2.Attack(monster1);

	int test = 0;
	do
	{
		std::cout << "New Round" << std::endl;
		monster1.State();
		monster2.State();
		monster1.Rage();
		monster2.Pary();
		monster1.State();
		monster2.State();
		monster1.Attack(monster2);
		test++;
		monstervoid.EndOfRound(monster1, monster2);
	} while (test < 5);
}
