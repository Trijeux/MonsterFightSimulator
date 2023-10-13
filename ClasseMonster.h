#pragma once
#include <string>

enum Race
{
	Orc,
	Troll,
	Goblin
};

class Monster
{
public:
	//Constructor
	Monster(int _healthPoints, int _attackDamage, int _defensePoints, int _speed, Race _monsterRace);
	~Monster();

	//Metode
	void State();
	void Choix();
	void Attack(Monster& enemy);
	void Pary();
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
	Race monsterRace;

	//Metode
	std::string nameMonster();
	void takeDomage(int domage);
	void giveHP();




};

