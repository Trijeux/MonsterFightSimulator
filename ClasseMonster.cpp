#include "ClasseMonster.h"
#include <iostream>

Monster::Monster(int _healthPoints, int _attackDamage, int _defensePoints, int _speed, Race _nameRace) : HP(_healthPoints), AD(_attackDamage), DP(_defensePoints), S(_speed), NameRace(_nameRace){};


void Monster::Test()
{
	std::cout << "Vie : " << HP << " Attack : " << AD << " Defense : " << DP << ;
}