#pragma once
#include <string>

enum Race
{
	Orc,
	Troll,
	Goblin,
	Centaur,
	Dullahan,
	Ogre,
	Werewolf,
	Elf,
	Harpy,
	Salamander
};

class Monster
{

public:
#pragma region Constuctor
	Monster(int _healthPoints, int _attackDamage, int _defensePoints, int _speed, Race _monsterRace, int _color);
	Monster(int _attackDamageTemp, int _defensePointTemp, int _nbRound);
	~Monster();
#pragma endregion

#pragma region Metode

	//Throws a rand between 1 and 4 to know what action it will do
	void Choix(Monster& enemy);

	//Shows the stats of monster 
	void Statemonster();

	//Complete rounds
	void EndOfRound();

	//Check if one of the two monsters is dead
	void EndGameMessage();

	bool DeadOrNot();

	//Gives the value of speed
	int getS() { return S; };
#pragma endregion

private:

#pragma region Property
	int HP;
	int AD;
	int DP;
	int S;
	int DPTemp = 0;
	int ADTemp = 0;
	int HPMax = 100;
	Race monsterRace;
	int color;
#pragma endregion

#pragma region Metode

	//Shows the monster in letters
	std::string nameMonster();

	//Remove hp
	void takeDomage(int domage);

	//Gives hp
	void giveHP();

	//Reset temporary defense
	void resetDPTemp();

	//Reset temporary attack
	void resetADTemp();

	//The monster attacks
	void Attack(Monster& enemy);

	//The monster rages and attacks harder
	void Rage(Monster& enemy);

	//The monster defends itself
	void Pary();

	//The monster heals itself
	void AutoHeal();

	void ShowMessageMonster(std::string message);
#pragma endregion

};

