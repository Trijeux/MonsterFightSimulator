#pragma once
#include <string>

enum Race
{
	Orc,
	Troll,
	Goblin,
};

class Monster
{
public:
#pragma region Constuctor
	Monster(int _healthPoints, int _attackDamage, int _defensePoints, int _speed, Race _monsterRace);
	Monster(int _attackDamageTemp, int _defensePointTemp, int _nbRound);
	~Monster();
#pragma endregion

#pragma region Metode

	//Throws a rand between 1 and 4 to know what action it will do
	void Choix(Monster& enemy, int priority);

	//Displays the number of rounds completed
	void Round();

	//Shows the stats of monster 1
	void Statemonster1();

	//Shows the stats of monster 2
	void Statemonster2();

	//Complete rounds
	void EndOfRound(Monster& enemy1, Monster& enemy2);

	//Check if one of the two monsters is dead
	int DeadOrNot(Monster& enemy1, Monster& enemy2);

	//Gives the value of speed
	int getS() { return S; };
#pragma endregion

private:

#pragma region Propryety
	int HP;
	int AD;
	int DP;
	int S;
	int DPTemp = 0;
	int ADTemp = 0;
	int HPMax = 100;
	int nbRound = 0;
	Race monsterRace;
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
	void Attack(Monster& enemy, int priority);

	//The monster rages and attacks harder
	void Rage(Monster& enemy, int priority);

	//The monster defends itself
	void Pary();

	//The monster heals itself
	void AutoHeal();
#pragma endregion






};

