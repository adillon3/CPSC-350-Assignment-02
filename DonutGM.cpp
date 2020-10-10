/*******************************
 * Andrew Dillon
 * 2382400
 * CPSC 350
 * Assignment 02
 *******************************/

 #include "DonutGM.h"

DonutGM :: DonutGM() : GameMode(){}
DonutGM :: DonutGM(unsigned int newRows, unsigned int newCol, float initalPopDensity) :
            GameMode(newRows, newCol, initalPopDensity){}
DonutGM :: DonutGM(string input) : GameMode(input){}
DonutGM :: ~DonutGM(){}


char DonutGM :: FindCorrespondingCell(int i, int j, Grid* gridToCheck)
{
  int numRows = gridToCheck -> GetNumRows();
  int numCol  = gridToCheck -> GetNumCollumns();
  //four corners
  //upper left corner, get lower right corner
  if(i < 0 && j < 0)
  {
    return gridToCheck -> GetCharAt(numRows - 1, numCol - 1);
  }
  //upper right corner, get lower left corner
  if(i < 0 && j >= numCol)
  {
    return gridToCheck -> GetCharAt(numRows - 1, 0);
  }
  //lower left corner, get upper right corner
  if(i >= numRows && j < 0)
  {
    return gridToCheck -> GetCharAt(0, numCol - 1);
  }
  //lower right corner, get upper left corner
  if(i >= numRows && j >= numCol)
  {
    return gridToCheck -> GetCharAt(0, 0);
  }

  //sides
  //above board, get bottom row
  if(i < 0)
  {
    return gridToCheck -> GetCharAt(numRows - 1, j);
  }
  //to left of the board, get right column
  if(j < 0)
  {
    return gridToCheck -> GetCharAt(i, numCol - 1);
  }
  //below board, get top row
  if(i >= numRows)
  {
    return gridToCheck -> GetCharAt(0, j);
  }
  //to right of the board, get left column
  if(j >= numCol)
  {
    return gridToCheck -> GetCharAt(i, 0);
  }

}
bool DonutGM ::  OffBoardNeighborAtLocation(int i, int j, Grid* gridToCheck)
{
  if(FindCorrespondingCell(i, j, gridToCheck) == 'X')
  {
    return true;
  }
  return false;
}
