#pragma once

//If the speed of the two monsters is equal, choose a number between 1 and 2 to know who starts
int randpriority();

//Asks the player to choose the Race of their first monster
int ChoiseRaceMonster1(bool resteConsoleForNewGame);

//Asks the player to choose the Race of their second monster
int ChoiseRaceMonster2();

//Create a random number between 1 and 40 with a greater chance of being around 20
int RandomStateAD();

//Create a random number between 1 and 20 with a greater chance of being around 10
int RandomStateDP();

//Create a random number between 1 and 10 with a greater chance of being around 5
int RandomStateS();