#ifndef _uci_
#define _uci_
#include <Windows.h>
#include "move.h"
#include <iostream>
#include <string>
#include <atlstr.h>

#ifndef BUFFSIZE
#define BUFFSIZE 4096
#endif

using namespace std;

class UCIReader
{
    public:
        UCIReader(TCHAR*, TCHAR*);
        string InsertCommand(string&) const;
    private:
		TCHAR* applicationName;
		TCHAR* applicationPath;
		HANDLE hStdInWr, hStdInRd, hStdOutWr, hStdOutRd;
		void CreateChildProcess();
		void CreateChildPipes();
		void WriteToPipe(const TCHAR*) const;
		void ReadFromPipe(CHAR*) const;
};
class Uci {
    public:
        Uci(string&, string&);
        void MakeMove(string&);
    private:
        Moves* moveType;
        UCIReader* reader;
};
#endif
