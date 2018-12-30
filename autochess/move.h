#ifndef _move_
#define _move_
#include <iostream>
#include <string>

class Moves {
    public:
        virtual MakeMove(std::string mv) = 0;
};

class MoveGraphically: public Moves {
    public:
        MakeMove(std::string mv);
};

class MoveUci: public Moves {
    public:
        MakeMove(std::string mv);
};
#endif
