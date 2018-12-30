#ifndef _uci_
#define _uci_
#include "move.h"
#include <iostream>
#include <string>

using namespace std;

class UCIReader
{
    public:
        UCIReader(string& path);
        string InsertCommand(string mv);
    private:
        string path;

        void CreateProcess();
};
class Uci {
    public:
        Uci();
        void MakeMove(string move);
        void Initialize(string path);
    private:
        Move* moveType;
        UCIReader* reader;
};
#endif
