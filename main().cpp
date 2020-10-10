/*******************************
 * Andrew Dillon
 * 2382400
 * CPSC 350
 * Assignment 02
 *******************************/
#include "assign2.h"

int main()
{
  //REAL MAIN

  char menuChoice; // 'F' or 'R'
  bool invalidInput = true;
  char outputLocationChar; // 'A', 'E' or 'F'
  GameMode* currentGameMode;

  //title
  cout << "Hello, and welcome to..." << endl << endl;
  PrintTitleToOutput(cout);

  //menu
  menuChoice = GetMainMenuChoice();

  //creating GameMode
  if(menuChoice == 'F')
  {
    CreateAndAssignGameModeFile(currentGameMode);
  }
  else // menuChoice == 'R'
  {
    CreateAndAssignGameModeRandom(currentGameMode);
  }

  //output and running simlation
  outputLocationChar = GetOutputLocationChar();

  if(outputLocationChar == 'F')
  {
    //create file
    ofstream fout;
    fout.open(GetFileName());
    cout << endl;

    PrintTitleToOutput(fout);

    currentGameMode -> RunSimulation(fout, outputLocationChar);

    //close file
    fout.close();
  }
  else // press enter or automatic
  {
    currentGameMode -> RunSimulation(cout, outputLocationChar);
  }

  cout << "\n\nThank you for playing!\n\n";

  return 0;
}
