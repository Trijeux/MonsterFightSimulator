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
	~Monster();
#pragma endregion

#pragma region Method

	void Choice(Monster& enemy);

	void StatMonster();

	//Complete rounds
	void EndOfRound();

	void EndGameMessage();

	bool DeadOrNot();

	int getS() { return S; };
#pragma endregion

private:

#pragma region Property
	int HP;
	int AD;
	int DP;
	int S;
	int DPBonus = 0;
	int ADBonus = 0;
	int HPMax = 100;
	Race monsterRace;
	int color;
#pragma endregion

#pragma region Method

	std::string nameMonster();
	
	void takeDomage(int domage);
	
	void giveHP();
	
	void resetDPBonus();
	
	void resetADBonus();

	void attack(Monster& enemy);

	void rage(Monster& enemy);
	
	void parry();

	void autoHeal();

	void showMessageMonster(std::string message);
#pragma endregion

};

