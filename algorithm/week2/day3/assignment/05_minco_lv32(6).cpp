#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int numToVote, numCitizen;
	cin >> numToVote >> numCitizen;

	vector<string> v[101];

	for (int i = 0; i < numCitizen; i++) {
		int pick;
		string name;
		cin >> pick >> name;
		v[pick].push_back(name);
	}

	int MaxVoted = -2134567890;
	int MaxPick = 0;
	for (int i = 0; i < numToVote; i++) {
		if (MaxVoted < int(v[i].size())){
			MaxVoted = v[i].size();
			MaxPick = i;
		}
	}

	for (int j = 0; j < v[MaxPick].size(); j++) {
		cout << v[MaxPick][j] << ' ';
	}
	cout << '\n';

	return 0;
}
