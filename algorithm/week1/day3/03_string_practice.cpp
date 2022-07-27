#include <iostream>
using namespace std;

int getlen(char s[]) {
	int i = 0;
	while (s[i] != '\0'){
		i++;
	}
	return i;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	// 1. c string 
	char str[] = "string";
	int len = getlen(str);
	cout << len << "\n";

	// 2. cstring library
	cout << strlen(str) << "\n";

	// 3. C++ string class
	string s = "string";
	cout << s.length() << "\n";

	return 0;
}