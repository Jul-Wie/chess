#include <string>
#include <iostream>
#include "pieces.h"
#include <algorithm>

using namespace std;

boardSquare board[8];
king King;
string piece;
bool debugOnOff;
void debugAsk(){
  string debugMode;

  cout << "Debug mode? [y/N]: ";
  cin >> debugMode;

  transform(debugMode.begin(), debugMode.end(), debugMode.begin(), ::toupper);

  if((debugMode == "Y") || (debugMode == "YES")){
    debugOnOff = 1;
    cout << "Debugging mode enabled. (debugOnOff = 1) \n";
  }
  else if((debugMode == "N") || (debugMode == "NO")){
    debugOnOff = 0;
    cout << "Debugging mode disabled. \n";
  }
  else {
    debugOnOff = 0;
    cout << "INVALID INPUT (how u so dumb?) so imma just assume u too dumb to understand debuggin mode so its set off.";
  }
 
 return;
}

int game(){
  cout << "pick piece to move: ";
  cin >> piece;

  if (piece != "king"){
    cout << "not an existing piece pls try again. \n";
    game();
  }

  King.makeMove();
   return 0;
 }

int main(){
  debugAsk();
  game();
  return 0;
}
