/*******************************
 * Andrew Dillon
 * 2382400
 * CPSC 350
 * Assignment 02
 *******************************/

#ifndef ASSIGN2_H_
#define ASSIGN2_H_

#include <iostream>
using namespace std;

#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <chrono>
#include <ctime>

#include "Grid.h"
#include "GameMode.h"
#include "ClassicGM.h"
#include "DonutGM.h"
#include "MirrorGM.h"

//functions
void PrintTitleToOutput(ostream& output);
char GetMainMenuChoice();
unsigned int GetUnsignedIntFromConsole(string dimension);
float GetDensityInput();
void CreateAndAssignGameModeRandom(GameMode* &myGameMode);
void CreateAndAssignGameModeFile(GameMode* &myGameMode);
char GetOutputLocationChar();
string GetInputFileName();
string GetFileName();
void RunSimulation(GameMode* &myGameMode, ostream& output);

#endif /* ASSIGN2_H_ */
