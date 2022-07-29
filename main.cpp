#include <string>
#include <iostream>
#include "pieces.h"
#include <algorithm>
#include <chrono>
#include <thread>

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

void summary(){
     int sleepytime = 80;

     cout << "\n\n\n-----------------------------------------------\n\n";
     std::this_thread::sleep_for(std::chrono::milliseconds(sleepytime));
     cout << "You can move the King (enter 'King'):";
     std::this_thread::sleep_for(std::chrono::milliseconds(sleepytime));
     cout << "\n   Current position: ";
     std::this_thread::sleep_for(std::chrono::milliseconds(sleepytime));
     cout << King.getLoc() + "\n\nThe Queen (enter 'Queen'):";
     std::this_thread::sleep_for(std::chrono::milliseconds(sleepytime));
     cout << "\n   Current position: " + Queen.getLoc();
     std::this_thread::sleep_for(std::chrono::milliseconds(sleepytime));
     cout << "\n\nOr you can exit the program by typing 'exit'\n";
     std::this_thread::sleep_for(std::chrono::milliseconds(sleepytime));
     cout << "\n-----------------------------------------------\n\n\n";
     std::this_thread::sleep_for(std::chrono::milliseconds(sleepytime));
}

int game(){
while (1){
  summary();
  cout << "pick piece to move: ";
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
