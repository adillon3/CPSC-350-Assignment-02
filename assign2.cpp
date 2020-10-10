#include "assign2.h"

void PrintTitleToOutput(ostream& output)
{
  output << "[]--------------------[]" << endl;
  output << " |* THE GAME OF LIFE *| " << endl;
  output << "[]--------------------[]" << endl << endl;
}
char GetMainMenuChoice()
{
  char menuChoice;

  bool invalidInput = true;

  cout << "Let's get started.\n" <<
          "Would you like to get a random grid or would would you like to provide a file?\n" <<
          "Please enter an R for random grid or F for file: ";

    do
    {
      cin.get(menuChoice);
      cin.ignore(100000000, '\n');

      menuChoice = toupper(menuChoice);

      if(menuChoice == 'R' || menuChoice == 'F')
      {
        invalidInput = false;
      }
      else
      {
        invalidInput = true;
        cout << "Sorry, please enter either an R for random input or an F to provide a file: ";
      }
    }while(invalidInput);

    cout << endl;

    return menuChoice;
}
char GetGameModeInput()
{
  char gameChoice;

  bool invalidInput = true;

  cout << "Which game mode would you like to play: Classic, Donut, or Mirror?\n";
  cout << "Please enter either a C, D, or M: ";

    do
    {
      cin.get(gameChoice);
      cin.ignore(100000000, '\n');

      gameChoice = toupper(gameChoice);

      if(gameChoice == 'C' || gameChoice == 'D' || gameChoice == 'M')
      {
        invalidInput = false;
      }
      else
      {
        invalidInput = true;
        cout << "Sorry, please enter either a C, D, or M: ";
      }
    }while(invalidInput);

    cout << endl;

    return gameChoice;
}
float GetDensityInput()
{
  float desntiy;

  bool invalidInput = true;

  cout << "What population density would you like to start with?\n";


    do
    {
      cout << "Please enter a decimal that is greater than 0 and less than or equal to 1: ";
      cin >> desntiy;
      cin.ignore(100000000, '\n');

      if(cin.fail())
      {
        cin.clear();
        cin.ignore(100000000, '\n');
        cout << "Sorry, please use numeric input.\n";
      }
      else if(desntiy > 0 && desntiy <= 1)
      {
        invalidInput = false;
      }
      else
      {
        invalidInput = true;
        cout << "Sorry, this value is not a valid percentage.\n";
      }
    }while(invalidInput);

    cout << endl;

    return desntiy;
}
void CreateAndAssignGameModeRandom(GameMode* &myGameMode)
{
  int numRows = GetUnsignedIntFromConsole("rows");
  int numCol  = GetUnsignedIntFromConsole("collumns");


  //get float
  float density = GetDensityInput();
  //getgamemode
  char gameModeChar = GetGameModeInput();

  //create game
  if(gameModeChar == 'C')
  {
    myGameMode = new ClassicGM(numRows, numCol, density);
  }
  else if(gameModeChar == 'D')
  {
    myGameMode = new DonutGM(numRows, numCol, density);
  }
  else // if (gameModeChar == 'M')
  {
    myGameMode = new MirrorGM(numRows, numCol, density);
  }
}
unsigned int GetUnsignedIntFromConsole(string dimension)
{
  bool invalidInput = true;
  unsigned int returnInt = 0;
  long int inputInt;

  do
  {
    cout << "Please enter the number of " << dimension << " you would like: ";
    cin  >> inputInt;
    cin.ignore(100000000, '\n');

    if(cin.fail())
    {
      cin.clear();
      cin.ignore(100000000, '\n');
      cout << "Sorry, please enter the number of " << dimension << " in numbers.\n";
    }
    else if(inputInt <= 0)
    {
      cout << "Sorry, the number of " << dimension << " must be a positive, non-zero, number.\n";
      invalidInput = true;
    }
    else
    {
      returnInt = (unsigned int)inputInt;
      invalidInput = false;
    }
  }while(invalidInput);

  cout << endl;

  return returnInt;
}
void CreateAndAssignGameModeFile(GameMode* &myGameMode)
{
  //Get file name from user
  string fileName = GetInputFileName();

  //ask user for gamemode
  char gameModeChar = GetGameModeInput();

    //call appropirate constructor
  if(gameModeChar == 'C')
  {
    myGameMode = new ClassicGM(fileName);
  }
  else if(gameModeChar == 'D')
  {
    myGameMode = new DonutGM(fileName);
  }
  else // if (gameModeChar == 'M')
  {
    myGameMode = new MirrorGM(fileName);
  }
}
char GetOutputLocationChar()
{
  char autoOrEnterChar;

  bool invalidInput = true;

  cout << "How would you like the game to run\n";
  cout << "Would you like the game to play automaticlly, pausing in between generations, would you like\n"
       << "to press the enter key in between generations, or would you like to output to a file?\n";
  cout << "Please enter an A for automatic, an E to press enter, or F to output to a file: ";

  do
  {
    cin.get(autoOrEnterChar);
    cin.ignore(100000000, '\n');

    autoOrEnterChar = toupper(autoOrEnterChar);

    if(autoOrEnterChar == 'A' || autoOrEnterChar == 'E' || autoOrEnterChar == 'F')
    {
      invalidInput = false;
    }
    else
    {
      invalidInput = true;
      cout << "Sorry, please enter either an A, E, or F: ";
    }
  }while (invalidInput);

  cout << endl;

  return autoOrEnterChar;
}
bool CheckLineForVaildChars(string currentString)
{
  int currentLength = currentString.length();

  for(int i = 0; i < currentLength; ++i)
  {
    if(currentString[i] != 'X' && currentString[i] != 'x' && currentString[i] != '-')
    {
      return false;
    }
  }
  return true;
}

bool InputFormatedCorrectly(ifstream & inFile)
{
  int statedNumRows;
  int statedNumCol;
  string temp1;
  string temp2;
  int tempLength1;
  int tempLength2;
  int countedRows = 0;

  //check that the first line is a digit
  inFile >> statedNumRows;

  if(inFile.fail())
  {
    inFile.clear();
    inFile.ignore(100000000, '\n');
    return false;
  }

  inFile >> statedNumCol;

  if(inFile.fail())
  {
    inFile.clear();
    inFile.ignore(100000000, '\n');
    return false;
  }

  inFile.ignore(100000000, '\n');
  getline(inFile, temp1);
  tempLength1 = temp1.length();
  ++countedRows;


  if(CheckLineForVaildChars(temp1))
  {
    return false;
  }


  while(inFile && !inFile.eof() && tempLength2 != 0)
  {
    ++countedRows;

    getline(inFile, temp2);
    tempLength2 = temp2.length();


    if(tempLength1 != tempLength2 && tempLength2 != 0)
    {
      return false;
    }
  }//while(inFile && !inFile.eof() && tempLength2 != 0)


  return true;
}

string GetInputFileName()
{
  string fileName;
  ifstream inFile;
  bool isNotValid = true;

  do
  {
    fileName = GetFileName();

    inFile.open(fileName);

    //check if file exists
    if(inFile)
    {
      if(InputFormatedCorrectly(inFile))
      {
        isNotValid = false; //is valid
      }
      else
      {
        cout << "Sorry, the file, \"" << fileName << "\", was not formatted correctly.\n";
        isNotValid = true; //repeat loop
      }

    }
    else
    {
      cout << "Sorry, the file, \"" << fileName << "\", wasn't found.\n";
      isNotValid = true; //repeat loop
    }

    inFile.close();
  } while(isNotValid);

  return fileName;
}

string GetFileName()
{
  string fileName;
  int stringLength;

  cout << "Please enter the name of the file: ";

  getline(cin, fileName);

  stringLength = fileName.length();

  return fileName;
}
