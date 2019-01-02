#include "uci.h"

UCIReader::UCIReader(string& path)
{
    this->path = path;
    CreateProc();
}

void UCIReader::CreateChildProcess(const TCHAR* applicationName)
{
    PROCESS_INFORMATION procInfo;
    STARTUPINFO startupInfo;
    BOOL bSuccess = FALSE;

    ZeroMemory(&procInfo, sizeof(PROCESS_INFORMATION));
    ZeroMemory(&startupInfo, sizeof(STARTUPINFO));
    startupInfo.cb = sizeof(STARTUPINFO);
    startupInfo.hStdError = hStdError;
    startupInfo.hStdOutput = hStdOut;
    startupInfo.hStdInput = hStdIn;
    startupInfo.dwFlags |= STARTF_USESTDHANDLES;

    bSuccess = CreateProcess(applicationName, NULL, NULL, TRUE, 0, NULL, NULL, &startupInfo, &procInfo);
    if( !bSuccess )
        ErrorExit(TEXT("CreateProcess"));
    else
    {
        CloseHandle(procInfo.hProcess);
        CloseHandle(procInfo.hThread);
    }
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

