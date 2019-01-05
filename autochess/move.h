#ifndef _move_
#define _move_
#include <iostream>
#include <string>
#include "uci.h"

using namespace std;

class UCIReader;

class Moves {
    public:
        virtual void MakeMove(string&) = 0;
};

class MoveGraphically: public Moves {
	private:
		UCIReader* reader;
    public:
		MoveGraphically(UCIReader*);
        void MakeMove(string&);
};

class MoveUci: public Moves {
	private:
		UCIReader* reader;
    public:
		MoveUci(UCIReader*);
        void MakeMove(string&);
};
#endif
