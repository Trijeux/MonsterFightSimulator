#include "ClassePlayer.h"
#include <iostream>


Player::Player(int _healthPoints, int _attackDamage, int _defensePoints, int _speed, std::string _namePlayer) : HP(_healthPoints), AD(_attackDamage), DP(_defensePoints), S(_speed), NamePlayer(_namePlayer) {}

Player::~Player()
{
	std::cout << "Le joueur est detruite" << std::endl;
}

void Player::StatePlayer()
{
	std::cout << "Vie : " << HP << " Attack : " << AD << " Defense : " << DP << " speed : " << S << " Name : " << NamePlayer << std::endl;
};
