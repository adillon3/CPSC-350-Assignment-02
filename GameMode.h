/*******************************
 * Andrew Dillon
 * 2382400
 * CPSC 350
 * Assignment 02
 *******************************/

#ifndef GAMEMODE_H_
#define GAMEMODE_H_

#include "Grid.h"

class GameMode{
public:
  GameMode();
  GameMode(unsigned int newRows, unsigned int newCol, float initalPopDensity);
  GameMode(string input);
  ~GameMode();

  //print functions
  void PrintCurrentGrid(ostream& output);
  void PrintNewGrid(ostream& output);
  void PrintOldGrid(ostream& output);
  void PrintCurrentGeneration(ostream& output);


  void RunSimulation(ostream& output, char proceedChar);




  //MAKE THESE PRIVATE????
  void CalcNextGen();
  bool IsStable();
  void RepositionGridPointers();
  bool IsOnBoard(int i, int j, Grid* gridToCheck);
  unsigned int NumNeighbors(unsigned int i, unsigned int j, Grid* gridToCheck);
  unsigned int NumEdgeNeighbor(unsigned int i, unsigned int j, Grid* gridToCheck);
  virtual bool OffBoardNeighborAtLocation(int i, int j, Grid* gridToCheck) = 0;

private:
  //Game logic functions, no reason for outside world to use these


  Grid *currentGrid;
  Grid *newGrid;
  Grid *oldGrid;
  int   generationNumber = 0;


};


#endif /* GAMEMODE_H_ */
