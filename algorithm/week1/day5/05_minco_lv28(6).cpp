#include <iostream>
#include <vector>
using namespace std;

string alphabets;
string path;

int adj_mtx[8][8];
int visited[10];
int printed[10];

void dfs(int node) {

	if (printed[node] == 0) {
		cout << alphabets[node];
		printed[node] = 1;
	}

	for (int next = 0; next < 8; next++) {
		if (adj_mtx[node][next] == 0) continue;
		if (visited[next] == 1) continue;

		path.push_back(alphabets[next]);
		visited[next] = 1;
		dfs(next);

		visited[next] = 0;
		path.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> alphabets;

	for (int from = 0; from < 8; from++) {
		for (int to = 0; to < 8; to++) {
			cin >> adj_mtx[from][to];
		}
	}

	cout << alphabets[0];
	printed[0] = 1;
	path.push_back(alphabets[0]);
	visited[0] = 1;
	dfs(0);
	visited[0] = 0;
	path.pop_back();

	return 0;
}
