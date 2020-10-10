/*******************************
 * Andrew Dillon
 * 2382400
 * CPSC 350
 * Assignment 02
 *******************************/
#ifndef GRID_H_
#define GRID_H_

//#include "assign2.h"

#include <iostream>
using namespace std;

#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>

class Grid
{
  public:
    //constructors and destructors
    Grid();
    Grid(string fileName);
    Grid(unsigned int newRows, unsigned int newCol, float initalPopDensity);
    Grid(const Grid &originalGrid);
    Grid(int newRow, int newCol);
    ~Grid();

    //overloaded operators
    bool operator==(const Grid &other) const;
    //move assignment operator
    Grid& operator= (Grid&& Other);

    //Getters and setters
    char GetCharAt(int i, int j);
    unsigned int GetNumRows();
    unsigned int GetNumCollumns();
    char SetCharAt(int i, int j, char newChar);
    void initializeGrid(string fileName);
    void initializeGrid(unsigned int newRows, unsigned int newCol, float initalPopDensity);
    void copyArray(const Grid &originalGrid);

    //Other methods
    void PrintGrid(ostream& output);
    void EmptyOutArray();
    bool IsEmptyGrid();
    void CopyGrid(const Grid &originalGrid);


  private:
    void CreateGridArray();

    char** grid;
    unsigned int numRows;
    unsigned int numCol;

};

#endif /* GRID_H_ */
