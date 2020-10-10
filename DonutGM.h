/*******************************
 * Andrew Dillon
 * 2382400
 * CPSC 350
 * Assignment 02
 *******************************/

#ifndef DONUTGM_H_
#define DONUTGM_H_

#include "GameMode.h"

class DonutGM : public GameMode
{
public:
  //constructors and deconstructors
  DonutGM();
  DonutGM(unsigned int newRows, unsigned int newCol, float initalPopDensity);
  DonutGM(string input);
  ~DonutGM();

  //other methods
  char FindCorrespondingCell(int i, int j, Grid* gridToCheck);
  bool OffBoardNeighborAtLocation(int i, int j, Grid* gridToCheck);
};

#endif /* DonutGH */
