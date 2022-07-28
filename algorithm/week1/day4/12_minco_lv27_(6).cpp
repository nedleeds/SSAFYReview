#include <iostream>
#include <vector>
using namespace std;

string alphabets;
int checked[26];

int main()
{
	cin >> alphabets;

	for (int i = 0; i < alphabets.size(); i++) {
		checked[alphabets[i] - 'A'] += 1;
	}

	int cnt = 0;
	for (int i = 0; i < 26; i++) {
		if (checked[i] > 0)
			cnt += 1;
	}

	cout << cnt << "종류\n";

	return 0;
}