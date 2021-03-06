#include "uci.h" 

UCIReader::UCIReader(TCHAR* applicationName, TCHAR* applicationPath) 
{ 
    this->applicationName = applicationName; 
	this->applicationPath = applicationPath;
	CreateChildPipes();
	CreateChildProcess();
}

string UCIReader::InsertCommand(string &inst) const
{
	TCHAR tInst[BUFFSIZE];
	CHAR buff[BUFFSIZE];
	_tcscpy_s(tInst, BUFFSIZE, CA2T(inst.c_str()));
	WriteToPipe(tInst);
	Sleep(220);
	ReadFromPipe(buff);
	return string(buff, strlen(buff));
}

void UCIReader::CreateChildPipes()
{ 
    SECURITY_ATTRIBUTES sAttr = { sizeof(SECURITY_ATTRIBUTES)  };
    sAttr.lpSecurityDescriptor = NULL; 
    sAttr.bInheritHandle = TRUE; 
    BOOL bSuccess = FALSE; 
    
    bSuccess = CreatePipe( &hStdInRd, &hStdInWr, &sAttr, 0 ); 
	if (!bSuccess) {
		cout << "Error Exiting - SetHandleInformation " << GetLastError() << endl;
		cin.get();
		exit(1);
	}
    
    bSuccess = CreatePipe( &hStdOutRd, &hStdOutWr, &sAttr, 0 );
	if (!bSuccess) {
		cout << "Error Exiting - SetHandleInformation" << GetLastError() << endl;
		cin.get();
		exit(1);
	}

    bSuccess = SetHandleInformation( hStdInWr, HANDLE_FLAG_INHERIT, 0  );
	if (!bSuccess) {
		cout << "Error Exiting - SetHandleInformation " << GetLastError() << endl;
		cout << GetLastError() << endl;
		cin.get();
		exit(1);
	}
    
    bSuccess = SetHandleInformation( hStdOutRd, HANDLE_FLAG_INHERIT, 0  );
	if (!bSuccess) {
		cout << "Error Exiting - SetHandleInformation " << GetLastError() << endl;
		cin.get();
		exit(1);
	}

     
}

void UCIReader::WriteToPipe(const TCHAR* buff) const
{
	BOOL bSuccess = FALSE;
	DWORD bytesWritten;
	bSuccess = WriteFile(hStdInWr, buff, strlen(buff), &bytesWritten, NULL);
	if (!bSuccess) {
		cout << "Error Exiting - WriteToPipe " << GetLastError() << endl;
		cin.get();
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

    bSuccess = CreateProcess(applicationPath, NULL, NULL, NULL, TRUE, 0, NULL, NULL, &startupInfo, &procInfo);
	if (!bSuccess) {
		cout << "Error Exiting - CreateProcess " << GetLastError() << endl;
		cin.get();
		exit(1);
	}
		
    else
    {
        CloseHandle(procInfo.hProcess);
        CloseHandle(procInfo.hThread);
    }
}


void UCIReader::ReadFromPipe(CHAR* buff) const
{
    BOOL bSuccess = FALSE;
    DWORD bytesWritten;
    bSuccess = ReadFile( hStdOutRd, buff, BUFFSIZE, &bytesWritten, NULL );
	if (!bSuccess) {
		cout << "Error Exiting - ReadFromPipe " << GetLastError() << endl;
		cin.get();
		exit(1);
	}
    buff[bytesWritten] = 0;
}

Uci::Uci(string& applicationName, string& applicationPath)
{
	TCHAR name[1024];
	TCHAR path[1024];
	_tcscpy_s(name, 1024, applicationName.c_str());
	_tcscpy_s(path, 1024, applicationPath.c_str());
	reader = new UCIReader(name, path);
    moveType = new MoveUci(reader);
}

void Uci::MakeMove(string& instr)
{
    moveType->MakeMove(instr);
}

