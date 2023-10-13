#pragma once
#include <string>

enum Race
{
	Orc,
	Troll,
	Goblin,
	Nothing
};

class Monster
{
public:
	//Constructor
	Monster(int _healthPoints, int _attackDamage, int _defensePoints, int _speed, Race _monsterRace);
	~Monster();

	//Metode
	void Choix();
	void State();
	void Attack(Monster& enemy);
	void Rage();
	void Pary();
	void AutoHeal();
	void EndOfRound(Monster& enemy1, Monster& enemy2);
	void DeadOrNot();

	/*int getHP() { return HP; };
	int getAD() { return AD; };
	int getDP() { return DP; };
	int getS() { return S; };*/

private:

	//Propryety
	int HP;
	int AD;
	int DP;
	int S;
	int DPTemp = 0;
	int ADTemp = 0;
	Race monsterRace;

	//Metode
	std::string nameMonster();
	void takeDomage(int domage);
	void giveHP();
	void resetDPTemp();
	void resetADTemp();




};

