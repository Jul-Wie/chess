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
      }else {
        std::cout << "Illegal move." << std::endl;
      }

}
string King::getLoc(){
  char abcFRONTEND;
  if(x_abc == 1){
    abcFRONTEND = 'a';
  }
  if(x_abc == 2){
    abcFRONTEND = 'b';
  }
  if(x_abc == 3){
    abcFRONTEND = 'c';
  }
  if(x_abc == 4){
    abcFRONTEND = 'd';
  }
  if(x_abc == 5){
    abcFRONTEND = 'e';
  }
  if(x_abc == 6){
    abcFRONTEND = 'f';
  }
  if(x_abc == 7){
    abcFRONTEND = 'g';
  }
  if(x_abc == 8){
    abcFRONTEND = 'h';
  }
  string output =  abcFRONTEND + to_string(y_123);
  return output;
}
