#include "uci.h"

UCIReader::UCIReader(string& path)
{
    this->path = path;
    CreateProc();
}

void UCIReader::CreateProc()
{
    cout << "Creating Process  " << path << endl;
	OFSTRUCT of;
	STARTUPINFO startInfo = { sizeof(STARTUPINFO) };
	startInfo.lpTitle = (char*) "TITLE OF SCREEN";
	startInfo.dwFlags = STARTF_USESTDHANDLES;
	startInfo.hStdOutput = (HANDLE) OpenFile("mytextlolfile.txt", &of, OF_WRITE);
	if (startInfo.hStdOutput == (HANDLE) HFILE_ERROR) {
		cout << "FAIL" << endl;
		cout << GetLastError() << endl;
		cin.get();
	}
	PROCESS_INFORMATION procInfo;
	LPSTR lpstr = (char*) "python lol.py";
	if (CreateProcess(NULL, lpstr, NULL, NULL, FALSE, 0, NULL, NULL, &startInfo, &procInfo))
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

