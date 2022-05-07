#include <string>
#include <iostream>
#include "pieces.h"
#include <algorithm>

using namespace std;


king King;
queen Queen;
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
    cout << "INVALID INPUT! so imma just assume you want it set off.\n";
  }

 return;
}

int game(){
while (1){
  cout << "pick piece to move (enter 'exit' to exit.): ";
  cin >> piece;
transform(piece.begin(), piece.end(), piece.begin(), ::toupper);

if(piece == "KING"){
 King.makeMove();
}
if(piece == "QUEEN"){
Queen.makeMove();
}
if(piece == "EXIT"){
  cout << "Exiting program. \n";
  return 0;
  }
 }
}

int main(){
  debugAsk();
  setupBoard();
  game();
  return 0;
}
