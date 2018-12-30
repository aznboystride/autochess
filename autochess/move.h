#ifndef _move_
#define _move_
#include <iostream>
#include <string>

using namespace std;

class Moves {
    public:
        virtual MakeMove(string mv) = 0;
};

class MoveGraphically: public Moves {
    public:
        MakeMove(string mv);
};

class MoveUci: public Moves {
    public:
        MakeMove(string mv);
};
#endif
