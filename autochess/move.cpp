#include "move.h"

MoveGraphically::MoveGraphically(UCIReader* reader)
{
	this->reader = reader;
}

void MoveGraphically::MakeMove(string &instr)
{
	cout << "Making Move Graphically " << instr << endl;
}

MoveUci::MoveUci(UCIReader* reader)
{
	this->reader = reader;
}

void MoveUci::MakeMove(string& instr)
{
	cout << "Making Move Locally " << instr << endl;
	string response = reader->InsertCommand(instr);
	stringstream sd(response, ios_base::in);
	string temp;
	while (getline(sd, temp))
		response = temp;
	cout << "Response: " << response << endl;
}
