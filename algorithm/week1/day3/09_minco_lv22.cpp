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

//----string----
//length()
//+ , =, ==
//substr
//find
//replace

char s[4][100];
char longest[10] = "";
char shortest[10] = "aaaaaaaaa";
int longest_idx = 0;
int shortest_idx = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	
	for (int i = 0; i < 4; i++) {
		cin >> s[i];
		if (strcmp(s[i], "0")==0) {
			cout << 0 <<"\n";
			return 0;
		}
		if (strlen(s[i]) > strlen(longest)){
			longest_idx = i;
			strcpy(longest, s[i]);
		}
		if (strlen(s[i]) < strlen(shortest)) {
			shortest_idx = i;
			strcpy(shortest, s[i]);
		}
	}

	cout << "긴문장:" << longest_idx << '\n';
	cout << "짧은문장:" << shortest_idx;

	return 0;
}