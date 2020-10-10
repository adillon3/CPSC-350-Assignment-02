/*******************************
 * Andrew Dillon
 * 2382400
 * CPSC 350
 * Assignment 02
 *******************************/

 #include "MirrorGM.h"

MirrorGM :: MirrorGM() : GameMode(){}
MirrorGM :: MirrorGM(unsigned int newRows, unsigned int newCol, float initalPopDensity) :
            GameMode(newRows, newCol, initalPopDensity){}
MirrorGM :: MirrorGM(string input) : GameMode(input){}
MirrorGM :: ~MirrorGM(){}

char MirrorGM :: FindNearestCell(int i, int j, Grid* gridToCheck)
{
  int numRows = gridToCheck -> GetNumRows();
  int numCol  = gridToCheck -> GetNumCollumns();
  //four corners
  //upper left corner
  if(i < 0 && j < 0)
  {
    return gridToCheck -> GetCharAt((int)i + 1, (int)j + 1);
  }
  //upper right corner
  if(i < 0 && j >= numCol)
  {
    return gridToCheck -> GetCharAt((int)i + 1, (int)j - 1);
  }
  //lower left corner
  if(i >= numRows && j < 0)
  {
    return gridToCheck -> GetCharAt((int)i - 1, (int)j + 1);
  }
  //lower right corner
  if(i >= numRows && j >= numCol)
  {
    return gridToCheck -> GetCharAt((int)i - 1, (int)j - 1);
  }

  //sides
  //above board
  if(i < 0)
  {
    return gridToCheck -> GetCharAt((int)i + 1, (int)j);
  }
  //to left of the board
  if(j < 0)
  {
    return gridToCheck -> GetCharAt((int)i, (int)j + 1);
  }
  //below board
  if(i >= numRows)
  {
    return gridToCheck -> GetCharAt((int)i - 1, (int)j);
  }
  //to right of the board
  if(j >= numCol)
  {
    return gridToCheck -> GetCharAt((int)i, (int)j - 1);
  }

}

bool MirrorGM ::  OffBoardNeighborAtLocation(int i, int j, Grid* gridToCheck)
{
  if(FindNearestCell(i, j, gridToCheck) == 'X')
  {
    return true;
  }
  return false;
}
