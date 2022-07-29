#include <iostream>
#include <vector>
using namespace std;

int nodeNum;
int adj_arr[7][7];
int visited[10];

void dfs(int now) {

	cout << now << ' ';

	for (int next = 0; next < nodeNum; next++) {
		if (adj_arr[now][next] == 0) continue;
		if (visited[next] == 1) continue;

		visited[next] = 1;
		dfs(next);
		visited[next] = 0;
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

	dfs(0);

	return 0;
}