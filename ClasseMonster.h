#pragma once
#include <string>

//Race Monster
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

	//Randomly choose the action that the monster will do
	void Choice(Monster& enemy);

	//Displays all monster information
	void StatMonster();

	//End the Round and reset the bonus statistics
	void EndOfRound();

	//Tells who lost and who won
	void EndGameMessage();

	//Check if one of the monsters is dead
	bool DeadOrNot();

	//Give the value of the speed
	int getSP() { return SP; };
#pragma endregion

private:

#pragma region Property

	//heal Point
	int HP;

	//Attack Point
	int AP;

	//Defense Point
	int DP;

	//Speed Point
	int SP;

	//Defense Point Bonus
	int DPBonus = 0;

	//Attack Point Bonus
	int ADBonus = 0;

	//heal Point Max
	int HPMax = 100;

	//Race Monster
	Race monsterRace;

	//Color Monster
	int color;
#pragma endregion

#pragma region Method

	//Take the index of the enum and give the name of the monster in string
	std::string nameMonster();

	//Remove HP from the Monster according to the damage using the attack method
	void takeDamage(int damage);

	//Remove Bonus Points from defense obtained
	void resetDPBonus();

	//Remove Bonus Points from attack obtained
	void resetADBonus();

	//Calculate the damage that the target monster will receive or if it fails
	void attack(Monster& enemy);

	//Gives bonus attack points
	void rage(Monster& enemy);

	//Gives bonus defense points
	void parry();

	//Gives HP to a monster
	void heal();

	//Set a color according to the monster's color
	void showMessageMonster(std::string message);
#pragma endregion

};

