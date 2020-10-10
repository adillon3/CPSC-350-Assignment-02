/*******************************
 * Andrew Dillon
 * 2382400
 * CPSC 350
 * Assignment 02
 *******************************/

#ifndef MIRRORGM_H_
#define MIRRORGM_H_

#include "GameMode.h"

class MirrorGM : public GameMode
{
public:
  //constructors and deconstructors
  MirrorGM();
  MirrorGM(unsigned int newRows, unsigned int newCol, float initalPopDensity);
  MirrorGM(string input);
  ~MirrorGM();
  
  //other methods
  char FindNearestCell(int i, int j, Grid* gridToCheck);
  bool OffBoardNeighborAtLocation(int i, int j, Grid* gridToCheck);

};

#endif /* MIRRORGM_H_ */
