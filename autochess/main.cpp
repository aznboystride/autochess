#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	HANDLE _stdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD bytesWritten;
	char answer[100] = "My name is anonymous";
	string name;
	cout << "What is your name: ";
	if (WriteFile(_stdin, answer, strlen(answer), &bytesWritten, NULL)) {
		cout << "strlen(answer) " << strlen(answer) << endl;
		cout << "BytesWritten " << bytesWritten << endl;
		cin >> name;
		cout << "Hi " << name << endl;
	}
	else {
		cout << "Error Code: " << GetLastError() << endl;
	}
	system("pause");
	return 0;
}