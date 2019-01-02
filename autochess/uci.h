#ifndef _uci_
#define _uci_
#include <Windows.h>
#include "move.h"
#include <iostream>
#include <string>
#include <atlstr.h>

using namespace std;

class UCIReader
{
    public:
        UCIReader(const TCHAR*);
        string InsertCommand(string&) const;
    private:
		const TCHAR* applicationName;
		HANDLE hStdInWr, hStdInRd, hStdOutWr, hStdOutRd;
		void CreateChildProcess();
		void CreateChildPipes();
		void WriteToPipe(const TCHAR*) const;
		void ReadFromPipe(CHAR*) const;
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
