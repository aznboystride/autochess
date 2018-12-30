#include "uci.h"

UCIReader::UCIReader(string& path)
{
    this->path = path;
    CreateProcess();
}

void UCIReader::CreateProcess()
{
    cout << "Creating Process With Fork On Path " << path << endl;
}

string UCIReader::InsertCommand(string mv)
{
    cout << "inserted command" << endl;
    return "command inserted :)";
}

Uci::Uci(string& path)
{
    moveType = new MoveUci();
    UCIReader = new UCIReader(path);
}

void Uci::MakeMove(string move)
{
    moveType->MakeMove(move);
}

