#include "uci.h"

UCIReader::UCIReader(string& path)
{
    this->path = path;
    CreateProc();
}

void UCIReader::CreateProc()
{
    cout << "Creating Process  " << path << endl;
	STARTUPINFO startInfo = { sizeof(STARTUPINFO) };
	PROCESS_INFORMATION procInfo;
	LPSTR lpstr = (char*) "python C:\\Users\\peynu\\Desktop\\Project6.py";
	if (CreateProcess(NULL, lpstr, NULL, NULL, FALSE, NULL, NULL, NULL, &startInfo, &procInfo))
		cout << "Success " << endl;
	else
		cout << "Failure " << GetLastError() << endl;
}

string UCIReader::InsertCommand(string mv)
{
    cout << "inserted command" << endl;
    return "command inserted :)";
}

Uci::Uci(string& path)
{
    moveType = new MoveUci();
    reader = new UCIReader(path);
}

void Uci::MakeMove(string move)
{
    moveType->MakeMove(move);
}

