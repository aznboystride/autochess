#include "uci.h" 

UCIReader::UCIReader(const TCHAR* applicationName) 
{ 
    this->applicationName = applicationName; 
}

void UCIReader::CreateChildPipes()
{ 
    SECURITY_ATTRIBUTES sAttr = { sizeof(SECURITY_ATTRIBUTES)  };
    sAttr.lpSecurityDescriptor = NULL; 
    sAttr.bInheritHandle = TRUE; 
    BOOL bSuccess = FALSE; 
    
    bSuccess = CreatePipe( &hStdInRd, &hStdInWr, &sAttr, 0 ); 
	if (!bSuccess) {
		cout << "Error Exiting - SetHandleInformation" << endl;
		exit(1);
	}
    
    bSuccess = CreatePipe( &hStdOutRd, &hStdOutWr, &sAttr, 0 );
	if (!bSuccess) {
		cout << "Error Exiting - SetHandleInformation" << endl;
		exit(1);
	}

    bSuccess = SetHandleInformation( &hStdInWr, HANDLE_FLAG_INHERIT, 0  );
	if (!bSuccess) {
		cout << "Error Exiting - SetHandleInformation" << endl;
		exit(1);
	}
    
    bSuccess = SetHandleInformation( &hStdOutRd, HANDLE_FLAG_INHERIT, 0  );
	if (!bSuccess) {
		cout << "Error Exiting - SetHandleInformation" << endl;
		exit(1);
	}

     
}

void UCIReader::WriteToPipe(const TCHAR* buff) const
{
	BOOL bSuccess = FALSE;
	DWORD bytesWritten;
	bSuccess = WriteFile(hStdInWr, buff, strlen(buff), &bytesWritten, NULL);
	if (!bSuccess) {
		cout << "Error Exiting - WriteToPipe" << endl;
		exit(1);
	}
}

void UCIReader::CreateChildProcess()
{
    PROCESS_INFORMATION procInfo;
    STARTUPINFO startupInfo;
    BOOL bSuccess = FALSE;

    ZeroMemory(&procInfo, sizeof(PROCESS_INFORMATION));
    ZeroMemory(&startupInfo, sizeof(STARTUPINFO));
    startupInfo.cb = sizeof(STARTUPINFO);
    startupInfo.hStdError = hStdOutWr;
    startupInfo.hStdOutput = hStdOutWr;
    startupInfo.hStdInput = hStdInRd;
    startupInfo.dwFlags |= STARTF_USESTDHANDLES;

    bSuccess = CreateProcess(applicationName, NULL, NULL, NULL, TRUE, 0, NULL, NULL, &startupInfo, &procInfo);
	if (!bSuccess) {
		cout << "Error Exiting - CreateProcess" << endl;
		exit(1);
	}
		
    else
    {
        CloseHandle(procInfo.hProcess);
        CloseHandle(procInfo.hThread);
    }
}


void UCIReader::ReadFromPipe(CHAR* buff)
{
    BOOL bSuccess = FALSE;
    DWORD bytesWritten;
    bSuccess = ReadFile( hStdOutRd, buff, 4096, &bytesWritten, NULL );
	if (!bSuccess) {
		cout << "Error Exiting - ReadFromPipe" << endl;
		exit(1);
	}
    buff[bytesWritten] = 0;
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

