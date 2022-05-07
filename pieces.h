#include <string>

using namespace std;

extern bool debugOnOff;


class boardSquare{
public:
    string getPieces();
    int yCoordOccupied[8];
};


class king{
public:
    void takeFirstSQ();
    void makeMove();
    string getLoc();
private:
    int xCoord = 4;
    int yCoordking = 0;
};


class queen{
public:
    void takeFirstSQ();
    void makeMove();
    string getLoc();
private:
    int xCoord = 3;
    int yCoordqueen = 0;
};

void setupBoard();
extern king King;
extern queen Queen;
