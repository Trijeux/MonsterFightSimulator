#pragma once
#include <string>

//Gives a random number between 1 and 2
int RandPriority();

//Gives the race of the monster the player wants to use for the first monster
int ChoiceRaceMonster1(bool resetConsoleForNewGame);

//Gives the race of the monster the player wants to use for the second monster
int ChoiceRaceMonster2();

//Gives a random attack stat
int RandomStatAD();

//Gives a random defense stat
int RandomStatDP();

//Gives a random speed statistic
int RandomStatSP();

//Gives the number of Rounds to pass
void Round(bool startBattle = false);

//Puts a message in color
void ShowMessage(std::string message, int color);