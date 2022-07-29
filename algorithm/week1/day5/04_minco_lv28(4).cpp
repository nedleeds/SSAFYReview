#include <iostream>
#include <vector>
using namespace std;

int nodeNum;
int adj_arr[100][100];
int visited[10];
vector<int> path;

void dfs(int now) {

	if (path.size() == 3) {
		for (int i = 0; i < path.size(); i++) {
			cout << path[i] << ' ';
		}
		cout << '\n';
	}

	for (int next = 0; next < nodeNum; next++) {
		if (adj_arr[now][next] == 0) continue;
		if (visited[next] == 1) continue;
		
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
			cin >> adj_arr[from][to];
		}
	}

	path.push_back(0);
	visited[0] = 1;
	dfs(0);
	visited[0] = 0;
	path.pop_back();

	return 0;
}