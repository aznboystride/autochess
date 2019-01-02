#include "uci.h" 

UCIReader::UCIReader(string& path) 
{ 
    this->path = path; 
  
} 

void UCIReader::CreateChildPipes() 
{ 
    SECURITY_ATTRIBUTES sAttr = { sizeof(SECURITY_ATTRIBUTES)  };
    sAttr.lpSecurityDescriptor = NULL; 
    sAttr.bInheritHandle = TRUE; 
    BOOL bSuccess = FALSE; 
    
    bSuccess = CreatePipe( &hStdInRd, &hStdInWr, &sAttr, 0 ); 
    if( !bSuccess  ) 
        ErrorExit(TEXT("CreatePipe"));
    
    bSuccess = CreatePipe( &hStdOutRd, &hStdOutWr, &sAttr, 0 );
    if( !bSuccess  )
        ErrorExit(TEXT("CreatePipe"));

    bSuccess = SetHandleInformation( &hStdInWr, HANDLE_FLAG_INHERIT, 0  );
    if( !bSuccess )
        ErrorExit(TEXT("SetHandleInformation"));
    
    bSuccess = SetHandleInformation( &hStdOutRd, HANDLE_FLAG_INHERIT, 0  );
    if( !bSuccess  )
        ErrorExit(TEXT("SetHandleInformation"));

     
}

void UCIReader::CreateChildProcess(const TCHAR* applicationName)
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

    bSuccess = CreateProcess(applicationName, NULL, NULL, TRUE, 0, NULL, NULL, &startupInfo, &procInfo);
    if( !bSuccess )
        ErrorExit(TEXT("CreateProcess"));
    else
    {
        CloseHandle(procInfo.hProcess);
        CloseHandle(procInfo.hThread);
    }
}

void UCIReader::WriteToPipe(CHAR* buff)
{
    BOOL bSuccess = FALSE;
    DWORD bytesWritten;
    bSuccess = WriteFile( hStdInWr, buff, strlen(buff), &bytesWritten, NULL );
    if ( !bSuccess  )
        ErrorExit( TEXT("WriteToPipe")  );
}

void UCIReader::ReadFromPipe()
{
    BOOL bSuccess = FALSE;
    DWORD bytesWritten;
    CHAR buff[4096];
    bSuccess = ReadFile( hStdOutRd, buff, 4096, &bytesWritten, NULL );
    if( !bSuccess )
        ErrorExit( TEXT("ReadFromPipe") );
    buff[bytesWritten] = 0;
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

