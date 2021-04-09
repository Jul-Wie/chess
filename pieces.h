#include <string>

using namespace std;

int square[8][8];

class King{
private:
      int x_abc;
      int y_123;
      bool side = 0;
      bool firstmove = 1;

public:
      void makemove(int x_abcInput, int y_123Input);
      string getLoc();
      King(bool sideInput){
          x_abc = 5;
          side = sideInput;
          if(side = 0){
            y_123 = 8;
          } else{
            y_123 = 1;
          }
      }

};
class Pawn{
private:
  int x_abc;
  int y_123;
  bool side = 0;
  bool firstmove = 1;
public:
  void makemove(int x_abcInput, int y_123Input);
  string getLoc();
  Pawn(bool sideInput){
    x_abc=5;
    side = sideInput;
    if(side = 0){
      y_123 = 7;
    } else {
      y_123 = 2;
    }
  }

};


