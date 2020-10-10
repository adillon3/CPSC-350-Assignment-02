/*******************************
 * Andrew Dillon
 * 2382400
 * CPSC 350
 * Assignment 02
 *******************************/

 #include "ClassicGM.h"

ClassicGM :: ClassicGM() : GameMode(){}
ClassicGM :: ClassicGM(unsigned int newRows, unsigned int newCol, float initalPopDensity) :
          GameMode(newRows, newCol, initalPopDensity) {}
ClassicGM :: ClassicGM(string input) : GameMode(input){}
ClassicGM :: ~ClassicGM(){}
bool ClassicGM :: OffBoardNeighborAtLocation(int i, int j, Grid* gridToCheck)
{
  return false;
}
