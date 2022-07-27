#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

//----cstring----
//strlen
//strcat
//strcmp / strncmp
//strcpy / strncpy
//strstr
char s[3][10];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	for (int i = 0; i < 3; i++) {
		cin >> s[i];
	}

	if (strcmp(s[0], s[1]) == 0 && strcmp(s[1], s[2]) == 0) {
		cout << "WOW\n";
	}
	else if (strcmp(s[0], s[1]) != 0 && strcmp(s[0], s[2]) != 0 && strcmp(s[1], s[2]) != 0) {
		cout << "BAD\n";
	}
	else {
		cout << "GOOD\n";
	}

	return 0;
}