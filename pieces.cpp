#include "pieces.h"
#include <iostream>
#include <string>


using namespace std;

void where2movedebug(string where2move, int newYCoord){
  cout << "\n--------------------------------------------" << "\n DEBUG: \n  where2move[0]=" << where2move[0] << "\n" << "  where2move[1]=" << where2move[1] << "\n" << "  newYCoord=" << newYCoord << "\n" << "  where2move.length=" << where2move.length() << ("\n--------------------------------------------\n") << "\n";
return;
}
string getString(char x)
{
    // string class has a constructor
    // that allows us to specify size of
    // string as first parameter and character
    // to be filled in given size as second
    // parameter.
    string s(1, x);

    return s;
}
string xCoordToLetter(int _in){
char _out;
  switch (_in){
    case 0:
    _out = 'a';
    break;
    case 1:
    _out = 'b';
    break;
    case 2:
    _out = 'c';
    break;
    case 3:
    _out = 'd';
    break;
    case 4:
    _out = 'e';
    break;
    case 5:
    _out = 'f';
    break;
    case 6:
    _out = 'g';
    break;
    case 7:
    _out = 'h';
    }
  string _outstr = getString(_out);
    return(_outstr);
}

string king::getLoc(){
  string xLetter;
  string output = "";

if((xCoord < 0) || (xCoord > 7)){
  cout << "Error: value of int king::xCoord is invalid.";
  return "";
}

xLetter = xCoordToLetter(xCoord);

output = xLetter;
output += std::to_string(yCoordking+1);
return(output);
}

void king::makeMove(){
  string where2move = "";
  int newXCoord;
  cout << "current location of your king: " << getLoc() << "\n";
  cout << "where to move the king: ";
  cin >> where2move;
  int newYCoord = (((int)(where2move[1]))-48);
  where2movedebug(where2move, newXCoord);
  if ((where2move.length() != 2) || !((where2move[0] == 'a') ||
  (where2move[0] == 'b') || (where2move[0] == 'c') || (where2move[0] == 'd')
  || (where2move[0] == 'e') || (where2move[0] == 'f') || (where2move[0] == 'g') ||
  (where2move[0] == 'h')) || (newYCoord > 8) || (newYCoord < 1)){
    cout << "invalid input";
    return;
  }
  switch (where2move[0]) {
    case 'a':
    newXCoord = 0;
    break;
    case 'b':
    newXCoord = 1;
    break;
    case 'c':
    newXCoord = 2;
    break;
    case 'd':
    newXCoord = 3;
    break;
    case 'e':
    newXCoord = 4;
    break;
    case 'f':
    newXCoord = 5;
    break;
    case 'g':
    newXCoord = 6;
    break;
    case 'h':
    newXCoord = 7;
    }
if((newYCoord-yCoordking) != 1 || (newYCoord-yCoordking != -1)){
  cout << "The King cannot move this far. Try again nerd. \n";
  makeMove();
}
if((newYCoord == yCoordking) && (newXCoord == xCoord)){
  cout << "idiot didnt even move the piece. TRY AGAIN. \n";
  makeMove();
}
yCoordking = newYCoord;
xCoord = newXCoord;
cout << "your king's new position is " + getLoc() + "\n";

return;
}
