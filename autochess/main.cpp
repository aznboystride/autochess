#include "uci.h"
#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string applicationName = "Artifical Chess";
	string applicationPath = "C:\\Users\\peynu\\Desktop\\stockfish-10-win\\Windows\\stockfish_10_x64.exe";
	cout << "Attempting to create UCI object" << endl;
	Uci* uci = new Uci(applicationName, applicationPath);
	string command = "uciread";
	uci->MakeMove(command);
	system("pause");
	return 0;
}