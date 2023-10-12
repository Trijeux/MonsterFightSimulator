#pragma once
#include <string>

class Player
{
public:

	//Constructor
	Player(int _healthPoints, int _attackDamage, int _defensePoints, int _speed, std::string _namePlayer);
	~Player();

	//Propryety
	std::string NamePlayer;

	//Metode
	void StatePlayer();

private:

	//Propryety
	int HP;
	int AD;
	int DP;
	int S;
	
};

