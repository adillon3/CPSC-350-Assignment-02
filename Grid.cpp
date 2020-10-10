#include "Grid.h"

Grid :: Grid()
{
  grid    = nullptr;
  numRows = 0;
  numCol  = 0;
}
//grid from file
Grid :: Grid(string fileName)
{
  ifstream inFile;
	inFile.open(fileName);

	inFile >> numRows;
  inFile >> numCol;
  inFile.ignore(1000000, '\n');

  CreateGridArray();

  string tempString;
  for(int i = 0; i < numRows; ++i)
  {
    getline(inFile, tempString);
    for(int j = 0; j < numCol; ++j)
    {
      if(toupper(tempString[j]) == 'X')
      {
        grid[i][j] = 'X';
      }
      else if(tempString[j] == 'J')
      {
        grid[i][j] = 'J';
      }
      else
      {
        grid[i][j] = '-';
      }
    }
  }

	inFile.close();
}
//random grid
Grid :: Grid(unsigned int newRows, unsigned int newCol, float initalPopDensity)
{
  //initializing variables
  numRows = newRows;
  numCol  = newCol;
  CreateGridArray();

  EmptyOutArray();

  //calculating number of filled squares
  //blank is *% of total squares [numRows * numCol]
  unsigned int numSquaresToFill = initalPopDensity * (numRows * numCol);

  //seed for random number
  srand (time(NULL));

  while(numSquaresToFill > 0)
  {
    //get random row and coll
    unsigned int randomRow = rand() % numRows;
    unsigned int randomCol = rand() % numCol;

    if(grid[randomRow][randomCol] != 'X')
    {
      grid[randomRow][randomCol] = 'X';
      --numSquaresToFill;
    }
  }//while(numSquaresToFill > 0)
}//END function

Grid :: Grid(const Grid &originalGrid)
{
  numRows = originalGrid.numRows;
  numCol  = originalGrid.numCol;

  CopyGrid(originalGrid);
}


Grid :: Grid(int newRow, int newCol)
{
  numRows = newRow;
  numCol  = newCol;
  CreateGridArray();
}

Grid :: ~Grid()
{
  for(int i = 0; i < numRows; ++i)
  {
    delete[] grid[i];
  }
  delete[] grid;
}


//Overloaded operators
bool Grid :: operator==(const Grid &other) const
{

  //checking to make sure they are the same size;
  if(numRows != other.numRows || numCol != other.numCol)
  {
    return false;
  }

  //checking arrays sqaure by square
  for(int i = 0; i < numRows; ++i)
  {
    for(int j = 0; j < numRows; ++j)
    {
      if(grid[i][j] != other.grid[i][j])
      {
        return false;
      }
    }
  }

  return true;
}

Grid& Grid :: operator= (Grid&& other)
{
  if(this != &other)
  {
    delete this -> grid;


  }
}





//Getters and setters
char Grid :: GetCharAt(int i, int j)
{
  return grid[i][j];
}
unsigned int Grid :: GetNumRows()
{
  return numRows;
}
unsigned int Grid :: GetNumCollumns()
{
  return numCol;
}
char Grid :: SetCharAt(int i, int j, char newChar)
{
  grid[i][j] = newChar;
}
void Grid :: PrintGrid(ostream& output)
{
  if(grid != nullptr)
  {
    for(int i = 0; i < numRows; ++i)
    {
      for(int j = 0; j < numCol; ++j)
      {
        output << grid[i][j];
      }
      output << endl;
    }
  }
  else
  {
    output << "No Grid Available";
  }
}








void Grid :: CreateGridArray()
{
    grid    = new char*[numRows];

    for(int i = 0; i < numRows; ++i)
    {
      grid[i] = new char[numCol];
    }

    for(int i = 0; i < numRows; ++i)
    {
      for(int j = 0; j < numCol; ++j)
      {
        grid[i][j] = '-';
      }
    }
}

void Grid :: EmptyOutArray()
{
  for(int i = 0; i < numRows; ++i)
  {
    for(int j = 0; j < numCol; ++j)
    {
      grid[i][j] = '-';
    }
  }
}

bool Grid :: IsEmptyGrid()
{
  for(int i = 0; i < numRows; ++i)
  {
    for(int j = 0; j < numCol; ++j)
    {
      if(grid[i][j] == 'X')
      {
        return false;
      }
    }
  }

  return false;
}

void Grid :: CopyGrid(const Grid &originalGrid)
{
  //creating grid if needed
  if(grid == nullptr)
  {
    CreateGridArray();
  }
  //copying array
  for(int i = 0; i < numRows; ++i)
  {
      for(int j = 0; j < numCol; ++j)
      {
        grid[i][j] = originalGrid.grid[i][j];
      }
  }
}
