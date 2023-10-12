#include <iostream>
#include "ClasseMonster.h"
#include "ClassePlayer.h"

int main()
{
	std::string nameInput;
	std::cout << "Quel est ton nom ?" << std::endl;
	std::cin >> nameInput;

	Player player1(20, 10, 40, 15, nameInput);
	Monster monster1(50, 25, 30, 5, Orc);
	Monster monster2(25, 10, 20, 10, Troll);
	Monster monster3(10, 5, 10, 25, Goblin);

	player1.StatePlayer();
	monster1.StateMonster();
	monster2.StateMonster();
	monster3.StateMonster();
}
