#include <iostream>
using namespace std;

string branch;
string path;
int cnt = 0;

int checkPath() {
	for (int i = 1; i < path.length(); i++) {
		int dif = path[i] - path[i - 1];
		if (dif > 3 || dif < -3) {
			return 0;
		}
	}
	return 1;
}

void func(int level) {
<<<<<<< Updated upstream
	// ±âÀú Á¶°Ç
	if (level == 4) {
		if (!checkPath()){
			return;
=======
	// ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
	if (level == lvl) {
		for (int j = 0; j < 3; j++) {
			if (DAT[j] == 3) {
				return;
			}
>>>>>>> Stashed changes
		}
		cnt++;
		return;
	}

<<<<<<< Updated upstream
	//Àç±Í Á¶°Ç
=======
	// ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
>>>>>>> Stashed changes
	for (int i = 0; i < branch.length(); i++) {
		path.push_back(branch[i]);
		func(level + 1);
		path.pop_back();

	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> branch;

	func(0);
	cout << cnt << "\n";

	return 0;
}