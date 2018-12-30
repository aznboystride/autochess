#ifndef _chesscom
#define _chesscom
#include "move.h"
#include <iostream>
#include <string>
using namespace std;

class ChessCommunicator
{
    public:
        void MakeMove(string move);
    private:
        ChessCommunicator();
        Moves* moveType;
};
#endif
