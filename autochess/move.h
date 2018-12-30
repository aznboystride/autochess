#ifndef _move_
#define _move_
#include <iostream>
#include <string>

using namespace std;

class Moves {
    public:
        virtual void MakeMove(string mv) = 0;
};

class MoveGraphically: public Moves {
    public:
        void MakeMove(string mv);
};

class MoveUci: public Moves {
    public:
        void MakeMove(string mv);
};
#endif
