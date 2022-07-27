//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

//----cstring----
//strlen
//strcat
//strcmp / strncmp
//strcpy / strncpy
//strstr

//----string----
//length()
//+ , =, ==
//substr
//find
//replace

char s[5][5];
char DAT[3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int floor = 1;

	for (int i = 0; i < 5; i++) {
		cin >> s[i];
	}

	for (int i = 0; i < 5; i++) {
		if (strcmp(s[i], "up") == 0){
			floor += 1;
		}
		else if (strcmp(s[i], "down") == 0) {
			floor -= 1;
		}
	}

	if (floor < 1) {
		cout << 'B' << -floor + 1 << '\n';
	}
	else {
		cout << floor << '\n';
	}

	return 0;
}