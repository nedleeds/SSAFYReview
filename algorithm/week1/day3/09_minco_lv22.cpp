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

char encriptions[][100000] = {
	"Jason",
	"Dr.tom",
	"EXEXI",
	"GK12P",
	"POW",
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	char passwd[1000];
	cin >> passwd;

	for (int j = 0; j < 5; j++) {
		if (strcmp(encriptions[j], passwd) == 0) {
			cout << "��ȣ����\n";
			return 0;
		}
	}
    
	cout << "��ȣƲ��\n";
	return 0;
}