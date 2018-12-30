#ifndef _uci_
#define _uci_
#include <Windows.h>
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

        void CreateProc();
};
class Uci {
    public:
        Uci(string& path);
        void MakeMove(string move);
    private:
        Moves* moveType;
        UCIReader* reader;
};
#endif
