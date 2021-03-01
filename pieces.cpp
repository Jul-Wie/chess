#include "pieces.h"
#include <iostream>

using namespace std;

void King::makemove(int x_abcInput, int y_123Input){
  int y_minimal = y_123 - 1;
  int x_minimal = x_abc - 1;
  int y_max = y_123 + 1;
  int x_max = x_abc + 1;
      if ((y_123Input == y_123 || y_123Input == y_max || y_123Input == y_minimal) && (x_abcInput == x_abc || x_abcInput == x_max || x_abcInput == x_minimal)){

          y_123 = y_123Input;
          x_abc = x_abcInput;
          firstmove = 0;
      }else {
        std::cout << "Illegal move." << std::endl;
      }

}
string King::getLoc(){
  char abcFRONTEND;
  if(x_abc == 1){
    abcFRONTEND = 'a';
  }
  else if(x_abc == 2){
    abcFRONTEND = 'b';
  }
  else if(x_abc == 3){
    abcFRONTEND = 'c';
  }
  else if(x_abc == 4){
    abcFRONTEND = 'd';
  }
  else if(x_abc == 5){
    abcFRONTEND = 'e';
  }
  else if(x_abc == 6){
    abcFRONTEND = 'f';
  }
  else if(x_abc == 7){
    abcFRONTEND = 'g';
  }
  else if(x_abc == 8){
    abcFRONTEND = 'h';
  }
  string output =  abcFRONTEND + to_string(y_123);
  return output;
}

void Pawn::makemove(int x_abcInput, int y_123Input){
  int y_minimal = y_123;
  int x_minimal = x_abc;
  int y_max = y_123 + 1;
  int y_startup_max = y_123 + 2;
  int x_max = x_abc;
  if(firstmove){
      if ((y_123Input == y_123 || y_123Input == y_startup_max || y_123Input == y_max || y_123Input == y_minimal) && (x_abcInput == x_abc || x_abcInput == x_max || x_abcInput == x_minimal)){

          y_123 = y_123Input;
          x_abc = x_abcInput;
          firstmove = 0;
      }else {
        std::cout << "Illegal move." << std::endl;
        cout << y_123Input << x_abcInput << endl;
        y_123 = y_123Input;
        x_abc = x_abcInput;
        cout << y_123 << x_abc <<endl;
      }
    } else{
      if ((y_123Input == y_123 || y_123Input == y_max || y_123Input == y_minimal) && (x_abcInput == x_abc || x_abcInput == x_max || x_abcInput == x_minimal)){

          y_123 = y_123Input;
          x_abc = x_abcInput;
      }else {
        std::cout << "Illegal move." << std::endl;
      }


    }
}
string Pawn::getLoc(){
  char abcFRONTEND;
  if(x_abc == 1){
    abcFRONTEND = 'a';
  }
  else if(x_abc == 2){
    abcFRONTEND = 'b';
  }
  else if(x_abc == 3){
    abcFRONTEND = 'c';
  }
  else if(x_abc == 4){
    abcFRONTEND = 'd';
  }
  else if(x_abc == 5){
    abcFRONTEND = 'e';
  }
  else if(x_abc == 6){
    abcFRONTEND = 'f';
  }
  else if(x_abc == 7){
    abcFRONTEND = 'g';
  }
  else if(x_abc == 8){
    abcFRONTEND = 'h';
  }
  string output =  abcFRONTEND + to_string(y_123);
  return output;
}
