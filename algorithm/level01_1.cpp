#include <iostream>
using namespace std;

int main()
{
	char input;
	cin >> input;

	int t = input - '0';

	if (input >= '0' && input <= '9') 
	{
		cout << t + 5;
	}

	return 0;
}