#include <iostream>
#include <cstring>
using namespace std;

string echo;
string total_echo;
int cnt = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	for (int i = 0; i < 5; i++) {
		cin >> echo;
		total_echo.append(echo);
	}

	for (int j = 0; j < total_echo.length(); j++) {
		int idx = (total_echo.find("MCD", j));
		if (idx != -1) {
			cnt++;
			j = idx + 2;
		}
	}


	cout << cnt << '\n';


	return 0;
}