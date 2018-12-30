#ifndef _uci_
#define _uci_
#include "move.h"
#include <iostream>
#include <string>

using namespace std;

class Uci {
    public:
        Uci();
        void MakeMove(string move);
        void Initialize();
    private:
        Move* moveType;
        UCIReader* reader;
};
#endif
