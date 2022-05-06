#include <string>

using namespace std;



class boardSquare{
public:
    string getPieces();
private:
    int yCoord[8];
};

class king{
public:
    void makeMove();
    string getLoc();
private:
    int xCoord = 4;
    int yCoordking = 0;
};
