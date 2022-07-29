#include <iostream>
#include <vector>
using namespace std;

int nodeNum;
int visited[10];
int printed[10];
int adj_mtx[101][101];
vector<int> path;

void dfs(int now) {

	if (printed[now] == 0) {
		cout << now << ' ';
		printed[now] = 1;
	}

	for (int next = 0; next < nodeNum; next++) {
		if (adj_mtx[now][next] == 0) continue;
		if (visited[next]) continue;		

		path.push_back(next);
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

	cin >> nodeNum;

	for (int from = 0; from < nodeNum; from++) {
		for (int to = 0; to < nodeNum; to++) {
			cin >> adj_mtx[from][to];
		}
	}

	path.push_back(0);
	visited[0] = 1;
	dfs(0);
	visited[0] = 0;
	path.pop_back();

	return 0;
}