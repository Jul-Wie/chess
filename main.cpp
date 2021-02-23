#include <string>
#include <iostream>
#include "pieces.h"

using namespace std;

int main(){
  King king(1);
  string input;
  cout << "Current king location: " << king.getLoc() << endl;
  cout << "K: ";
  cin >> input;
  char in_abc = input.at(0);
  cout << in_abc << endl;
  int in_y_123 = input.at(1);
   in_y_123 = in_y_123 - 48;
  int in_x_abc;
  if(in_abc == 'a'){
    in_x_abc = 1;
  }
  if(in_abc == 'b'){
    in_x_abc = 2;
  }
  if(in_abc == 'c'){
    in_x_abc = 3;
  }
  if(in_abc == 'd'){
    in_x_abc = 4;
  }
  if(in_abc == 'e'){
    in_x_abc = 5;
  }
  if(in_abc == 'f'){
    in_x_abc = 6;
  }
  if(in_abc == 'g'){
    in_x_abc = 7;
  }
  if(in_abc == 'h'){
    in_x_abc = 8;
  }
  cout << in_y_123 << " " << in_x_abc;
  king.makemove(in_x_abc, in_y_123);
  cout << "Current king location: " << king.getLoc() << endl;


}
