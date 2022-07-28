#include <iostream>
#include <vector>
using namespace std;

vector<int> Number;
string command;


int visited[10];

void findMax() {
	int M = -2134567890, M_idx;
	for (int i = 0; i < Number.size(); i++) {
		if (visited[Number[i]] == 1) continue;
		if (Number[i] > M) {
			M = Number[i];
			M_idx = i;
		}
	}
	visited[M] += 1;
	cout << M;
}

void findMin() {
	int m = 2134567890, m_idx;
	for (int i = 0; i < Number.size(); i++) {
		if (visited[Number[i]] == 1) continue;
		if (Number[i] < m) {
			m = Number[i];
			m_idx = i;
		}
	}
	visited[m] += 1;
	cout << m;
}

int main()
{


	for (int i = 0; i < 6; i++) {
		int n;
		cin >> n;
		Number.push_back(n);
	}
	cin >> command;

	for (int i = 0; i < command.length(); i++) {
		if (command[i] == 'm') {
			findMin();
		}
		else {
			findMax();
		}
	}

	return 0;
}