/*******************************
 * Andrew Dillon
 * 2382400
 * CPSC 350
 * Assignment 02
 *******************************/
#include "GameMode.h"

//constructors and Destructors
GameMode::GameMode()
{
  currentGrid = nullptr;
  newGrid     = nullptr;
  oldGrid     = nullptr;
  generationNumber = 0;
}
GameMode::GameMode(unsigned int newRows, unsigned int newCol, float initalPopDensity)
{
  currentGrid = new Grid(newRows, newCol, initalPopDensity);
  newGrid     = nullptr;
  oldGrid     = nullptr;
  generationNumber = 0;
}
GameMode::GameMode(string input)
{
  currentGrid = new Grid(input);
  newGrid     = nullptr;
  oldGrid     = nullptr;
  generationNumber = 0;
}
GameMode::~GameMode()
{
  delete currentGrid;
  delete newGrid;
  delete oldGrid;
}

//print functions
void GameMode:: PrintCurrentGrid(ostream& output)
{
  if(currentGrid != nullptr)
  {
    currentGrid -> PrintGrid(output);
  }
  else
  {
    output << "Current Grid does not exist\n";
  }
}
void GameMode:: PrintNewGrid(ostream& output)
{
  if(newGrid != nullptr)
  {
    newGrid -> PrintGrid(output);
  }
  else
  {
    output << "New Grid does not exist\n";
  }
}
void GameMode:: PrintOldGrid(ostream& output)
{
  if(oldGrid != nullptr)
  {
    oldGrid -> PrintGrid(output);
  }
  else
  {
    output << "Old Grid does not exist\n";
  }
}
void GameMode:: PrintCurrentGeneration(ostream& output)
{
  output << "Generation #" << generationNumber << endl;

  PrintCurrentGrid(output);

  output << endl;
}


unsigned int GameMode:: NumNeighbors(unsigned int i, unsigned int j, Grid* gridToCheck)
{
  unsigned int  neighborsCount = 0;

  if(i == 0 || j == 0 || i == gridToCheck -> GetNumRows() - 1
                      || j == gridToCheck -> GetNumCollumns() - 1)
  {
    neighborsCount = NumEdgeNeighbor(i, j, gridToCheck);
  }
  else
  {
    //upper left
    if(gridToCheck -> GetCharAt(i - 1, j - 1) == 'X')
    {
      ++neighborsCount;
    }

    //upper middle
    if(gridToCheck -> GetCharAt(i - 1, j) == 'X')
    {
      ++neighborsCount;
    }

    //upper right
    if(gridToCheck -> GetCharAt(i - 1, j + 1) == 'X')
    {
      ++neighborsCount;
    }

    //middle left
    if(gridToCheck -> GetCharAt(i, j - 1) == 'X')
    {
      ++neighborsCount;
    }

    //skipping center

    //middle right
    if(gridToCheck -> GetCharAt(i, j + 1) == 'X')
    {
      ++neighborsCount;
    }

    //lower left
    if(gridToCheck -> GetCharAt(i + 1, j - 1) == 'X')
    {
      ++neighborsCount;
    }

    //lower middle
    if(gridToCheck -> GetCharAt(i + 1, j) == 'X')
    {
      ++neighborsCount;
    }

    //lower right
    if(gridToCheck -> GetCharAt(i + 1, j + 1) == 'X')
    {
      ++neighborsCount;
    }
  }

  return neighborsCount;
}
bool GameMode ::IsOnBoard(int i, int j, Grid* gridToCheck)
{
  if(i < 0 || j < 0 || i >= gridToCheck -> GetNumRows() || j >= gridToCheck -> GetNumCollumns())
  {
    return true;
  }

  return false;
}
void GameMode::CalcNextGen()
{
  if(newGrid == nullptr)
  {
    newGrid = new Grid(currentGrid -> GetNumRows(), currentGrid -> GetNumCollumns());
  }

  for(int i = 0; i < currentGrid -> GetNumRows(); ++i)
  {
    for(int j = 0; j < currentGrid -> GetNumCollumns(); ++j)
    {
      unsigned int cellNeighbors = NumNeighbors(i, j, currentGrid);

      if(cellNeighbors == 2)//newGrid base on applying game rules to currentGrid
      {
        newGrid -> SetCharAt(i, j, currentGrid -> GetCharAt(i, j));
      }
      else if(cellNeighbors == 3)//three neighbors will always have a bacteria
      {
        newGrid -> SetCharAt(i, j, 'X');
      }
      else  //all other cases. either dies of lonliness or of overcrowding
      {
        newGrid -> SetCharAt(i, j, '-');
      }
    }
  }//for(int i = 0; i < currentGrid -> GetNumRows(); ++i)
}
bool GameMode::IsStable()
{
  //Check that grids exist before trying
  if(currentGrid -> IsEmptyGrid())
  {
    return true;
  }

  //new grid same as current
  if(newGrid != nullptr && *newGrid == *currentGrid)
  {
    return true;
  }
  //grid fliping between two options
  else if(oldGrid != nullptr && *newGrid == *oldGrid)
  {
    return true;
  }
  else
  {
    return false;
  }
}
void GameMode:: RepositionGridPointers()
{
  //disposing of old grid
  delete oldGrid;
  //making current grid the old one
  oldGrid = currentGrid;
  //making the new grid the current one
  currentGrid = newGrid;
  //newgrid stays how it is, it will be written over next time CalcNextGen is called
  newGrid = nullptr;
}

void GameMode :: RunSimulation(ostream& output, char proceedChar)
{
  bool gameIsNotStable = true;
  string temp;


  PrintCurrentGeneration(output);

  while(gameIsNotStable)
  {
    if(proceedChar == 'E') //press enter for next gen
    {
      getline(cin, temp);
    }
    else if(proceedChar == 'A') //wait a second for next get
    {
      //timed delay
    }

    CalcNextGen();
    ++generationNumber;

    if(IsStable())
    {
      gameIsNotStable = false; //game is stable

      cout << "Simulation complete.  The grid is stable.\n";
      cout << "Please press enter to exit the program.";
      getline(cin, temp);
    }
    else
    {
      RepositionGridPointers();

      PrintCurrentGeneration(output);
    }

  } //while(gameIsNotStable)
}



unsigned int GameMode :: NumEdgeNeighbor(unsigned int i, unsigned int j, Grid* gridToCheck)
{
  int numNeighbors = 0;

  //upper left
  if(IsOnBoard(int(i) - 1, int(j) - 1, gridToCheck))
  {
    if(OffBoardNeighborAtLocation((int)i - 1,(int)j - 1, gridToCheck))
    {
      ++numNeighbors;
    }
  }
  else
  {
    if(gridToCheck -> GetCharAt(i - 1, j - 1) == 'X')
    {
      ++numNeighbors;
    }
  }
  //upper middle
  if(IsOnBoard(int(i) - 1, int(j), gridToCheck))
  {
    if(OffBoardNeighborAtLocation((int)i - 1,(int)j, gridToCheck))
    {
      ++numNeighbors;
    }
  }
  else
  {
    //upper middle
    if(gridToCheck -> GetCharAt(i - 1, j) == 'X')
    {
      ++numNeighbors;
    }
  }
  //upper right
  if(IsOnBoard(int(i) - 1, int(j) + 1, gridToCheck))
  {
    if(OffBoardNeighborAtLocation((int)i - 1,(int)j + 1, gridToCheck))
    {
      ++numNeighbors;
    }
  }
  else
  {
    //upper right
    if(gridToCheck -> GetCharAt(i - 1, j + 1) == 'X')
    {
      ++numNeighbors;
    }
  }
  //middle left
  if(IsOnBoard(int(i), int(j) - 1, gridToCheck))
  {
    if(OffBoardNeighborAtLocation((int)i, (int)j - 1, gridToCheck))
    {
      ++numNeighbors;
    }
  }
  else
  {
    //middle left
    if(gridToCheck -> GetCharAt(i, j - 1) == 'X')
    {
      ++numNeighbors;
    }
  }
  //skipping center
  //middle right
  if(IsOnBoard(int(i), int(j) + 1, gridToCheck))
  {
    if(OffBoardNeighborAtLocation((int)i,(int)j + 1, gridToCheck))
    {
      ++numNeighbors;
    }
  }
  else
  {
    //middle right
    if(gridToCheck -> GetCharAt(i, j + 1) == 'X')
    {
      ++numNeighbors;
    }
  }
  //lower left
  if(IsOnBoard(int(i) + 1, int(j) - 1, gridToCheck))
  {
    if(OffBoardNeighborAtLocation((int)i + 1,(int)j - 1, gridToCheck))
    {
      ++numNeighbors;
    }
  }
  else
  {
    //lower left
    if(gridToCheck -> GetCharAt(i + 1, j - 1) == 'X')
    {
      ++numNeighbors;
    }
  }
  //lower middle
  if(IsOnBoard(int(i) + 1, int(j), gridToCheck))
  {
    if(OffBoardNeighborAtLocation((int)i + 1,(int)j, gridToCheck))
    {
      ++numNeighbors;
    }
  }
  else
  {
    if(gridToCheck -> GetCharAt(i + 1, j) == 'X')
    {
      ++numNeighbors;
    }
  }
  //lower right
  if(IsOnBoard(int(i) + 1, int(j) + 1, gridToCheck))
  {
    if(OffBoardNeighborAtLocation((int)i + 1,(int)j + 1, gridToCheck))
    {
      ++numNeighbors;
    }
  }
  else
  {
    if(gridToCheck -> GetCharAt(i + 1, j + 1) == 'X')
    {
      ++numNeighbors;
    }
  }

  return numNeighbors;
}
