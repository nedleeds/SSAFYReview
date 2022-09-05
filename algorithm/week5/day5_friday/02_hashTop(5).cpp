#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<string> namelist;
vector<int> idList;
unordered_map<int, vector<string>> recoList;
unordered_map<string, vector<int>> whoList;
unordered_map<int, int> recoCnt;


void doCommand(string cmd) {
	if (cmd == "recommand") {
		int id;
		string x;
		cin >> id >> x;
		recoList[id].push_back(x);
		whoList[x].push_back(id);
		//sort(recoList[id].begin(), recoList[id].end());
		sort(whoList[x].begin(), whoList[x].end());
		recoCnt[id] += 1;
		cout << recoCnt[id] << '\n';
	}
	else if (cmd == "print") {
		int id;
		cin >> id;
		if (recoCnt[id] == 0)
			cout << "none\n";
		else {
			for (int i = 0; i < recoList[id].size(); i++) {
				cout << recoList[id][i] << " ";
			}
			cout << '\n';
		}
	}
	else if (cmd == "whois") {
		string name;
		cin >> name;
		if (whoList[name].empty())
			cout << "none\n";
		else {
			for (int i = 0; i < whoList[name].size(); i++)
				cout << whoList[name][i] << ' ';
			cout << '\n';
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string cmd;
		cin >> cmd;
		doCommand(cmd);
	}

	return 0;
}