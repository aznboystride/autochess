#ifndef _uci_
#define _uci_
#include "move.h"
#include <iostream>
#include <string>

using namespace std;

class Uci {
    public:
        void Move(string move);
    private:
        Move* moveType;                
};
#endif
