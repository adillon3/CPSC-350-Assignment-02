/*******************************
 * Andrew Dillon
 * 2382400
 * CPSC 350
 * Assignment 02
 *******************************/

#ifndef CLASSICGM_H_
#define CLASSICGM_H_

#include "GameMode.h"

class ClassicGM : public GameMode
{
public:
  //constructors and deconstructors
  ClassicGM();
  ClassicGM(unsigned int newRows, unsigned int newCol, float initalPopDensity);
  ClassicGM(string input);
  ~ClassicGM();
  
  //other methods
  bool OffBoardNeighborAtLocation(int i, int j, Grid* gridToCheck);
};

#endif /* CLASSICGM_H_ */
