#include "pieces.h"
#include <iostream>
#include <string>


using namespace std;

boardSquare board[8];

void setupBoard(){
  for (int i = 0; i < 8; i++){
    for(int h = 0; h < 8; h++){
    board[i].yCoordOccupied[h] = 0;
  }
}

King.takeFirstSQ();
Queen.takeFirstSQ();

}

void king::takeFirstSQ(){
  board[xCoord].yCoordOccupied[yCoordking] = 6;
}

void queen::takeFirstSQ(){
  board[xCoord].yCoordOccupied[yCoordqueen] = 5;
}

void where2movedebug(string where2move, int newYC){
  cout << "\n--------------------------------------------" << "\n DEBUG: \n  where2move[0]=" << where2move[0] << "\n" << "  where2move[1]=" << where2move[1] << "\n" << "  newYCoord=" << newYC << "\n" << "  where2move.length=" << where2move.length() << ("\n--------------------------------------------\n") << "\n";
return;
}
void oldVSNewDebug(int newX, int newY, int oldX, int oldY){
  cout << "\n--------------------------------------------" << "\n DEBUG: \n  newXCoords=" << newX << "\n" << "  (old)xCoord=" << oldX << "\n" << "  newYCoord=" << newY << "\n" << "  (old)yCoord=" << oldY << ("\n--------------------------------------------\n") << "\n";
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
  cout << "Internal Error: value of int king::xCoord is invalid.";
  return "";
}

board[xCoord].yCoordOccupied[yCoordking] = 6;

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
  int newYCoord = (((int)(where2move[1]))-49);
  if(debugOnOff){
  where2movedebug(where2move, newYCoord);
}
  if ((where2move.length() != 2) || !((where2move[0] == 'a') ||
  (where2move[0] == 'b') || (where2move[0] == 'c') || (where2move[0] == 'd')
  || (where2move[0] == 'e') || (where2move[0] == 'f') || (where2move[0] == 'g') ||
  (where2move[0] == 'h')) || (newYCoord > 7) || (newYCoord < 0)){
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
if(!((newYCoord-yCoordking) == 1 || (newYCoord-yCoordking == -1) || (newYCoord-yCoordking == 0))) {
  cout << "The King cannot move this far. Try again nerd. \n";
  cout << "newYCoord-yCoordking(old)= " << newYCoord-yCoordking << "\n";

  if(debugOnOff){
    oldVSNewDebug(newXCoord, newYCoord, xCoord, yCoordking);
  }
  return;
}

if((newYCoord == yCoordking) && (newXCoord == xCoord)){
  cout << "idiot didnt even move the piece. TRY AGAIN. \n";
  return;
}

string takenByPiece = "";
  switch (board[newXCoord].yCoordOccupied[newYCoord]){
    case 1:
    takenByPiece = "white pawn";
    break;
    case 2:
    takenByPiece = "white knight";
    break;
    case 3:
    takenByPiece = "white bishop";
    break;
    case 4:
    takenByPiece = "white rook";
    break;
    case 5:
    takenByPiece = "white queen";
    break;
    case 6 :
    takenByPiece = "white king";
    break;
    case 7 :
    takenByPiece = "black pawn";
    break;
    case 8 :
    takenByPiece = "black knight";
    break;
    case 9 :
    takenByPiece = "black bishop";
    break;
    case 10 :
    takenByPiece = "black rook";
    break;
    case 11:
    takenByPiece = "black queen";
    break;
    case 12:
    takenByPiece = "black king";
  }

if(board[newXCoord].yCoordOccupied[newYCoord] != 0){
cout << "Square already occupied by the " << takenByPiece << " Try again.\n";
return;
}
board[xCoord].yCoordOccupied[yCoordking] = 0;
yCoordking = newYCoord;
xCoord = newXCoord;
board[xCoord].yCoordOccupied[yCoordking] = 6;
cout << "your king's new position is " + getLoc() + "\n";

return;
}


string queen::getLoc(){
  string xLetter;
  string output = "";

if((xCoord < 0) || (xCoord > 7)){
  cout << "Internal Error: value of int queen::xCoord is invalid.";
  return "";
}

board[xCoord].yCoordOccupied[yCoordqueen] = 5;

xLetter = xCoordToLetter(xCoord);

output = xLetter;
output += std::to_string(yCoordqueen+1);
return(output);
}

void queen::makeMove(){
  string where2move = "";
  int newXCoord;
  cout << "current location of your queen: " << getLoc() << "\n";
  cout << "where to move the queen: ";
  cin >> where2move;
  int newYCoord = (((int)(where2move[1]))-49);
  if(debugOnOff){
  where2movedebug(where2move, newYCoord);
}
  if ((where2move.length() != 2) || !((where2move[0] == 'a') ||
  (where2move[0] == 'b') || (where2move[0] == 'c') || (where2move[0] == 'd')
  || (where2move[0] == 'e') || (where2move[0] == 'f') || (where2move[0] == 'g') ||
  (where2move[0] == 'h')) || (newYCoord > 7) || (newYCoord < 0)){
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

  if(debugOnOff){
    oldVSNewDebug(newXCoord, newYCoord, xCoord, yCoordqueen);
  }

if((newYCoord == yCoordqueen) && (newXCoord == xCoord)){
  cout << "idiot didnt even movmovee the piece. TRY AGAIN. \n";
  makeMove();
}
string takenByPiece = "";
  switch (board[newXCoord].yCoordOccupied[newYCoord]){
    case 1:
    takenByPiece = "white pawn";
    break;
    case 2:
    takenByPiece = "white knight";
    break;
    case 3:
    takenByPiece = "white bishop";
    break;
    case 4:
    takenByPiece = "white rook";
    break;
    case 5:
    takenByPiece = "white queen";
    break;
    case 6 :
    takenByPiece = "white king";
    break;
    case 7 :
    takenByPiece = "black pawn";
    break;
    case 8 :
    takenByPiece = "black knight";
    break;
    case 9 :
    takenByPiece = "black bishop";
    break;
    case 10 :
    takenByPiece = "black rook";
    break;
    case 11:
    takenByPiece = "black queen";
    break;
    case 12:
    takenByPiece = "black king";
  }

if(board[newXCoord].yCoordOccupied[newYCoord] != 0){
cout << "Square already occupied by the " << takenByPiece << " Try again.\n";
return;
}

board[xCoord].yCoordOccupied[yCoordqueen] = 0;
yCoordqueen = newYCoord;
xCoord = newXCoord;
board[xCoord].yCoordOccupied[yCoordqueen] = 5;
cout << "your queen's new position is " + getLoc() + "\n";

return;
}
