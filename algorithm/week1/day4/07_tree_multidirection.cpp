#include <iostream>
#include <vector>
using namespace std;

int adj_arr[10][10];
vector<int> path;
int used[10];
int cntNode;
int cntEdge;

void dfs(int now) {

	if (now == 5) {
		for (int i = 0; i < path.size(); i++)
			cout << path[i] << " ";
		cout << '\n';

		return;
	}

	for (int next = 1; next <= cntNode; next++) {
		if (adj_arr[now][next] == 0) continue;
		if (used[next] == 1) continue;

		path.push_back(next);
		used[next] = 1;

		dfs(next);

		used[next] = 0;
		path.pop_back();
	}

}

/*
5
6
1 2
1 3
1 4
2 5
3 4
4 5
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();


	cin >> cntNode >> cntEdge;

	for (int i = 0; i < cntNode; i++) {
		int from, to;
		cin >> from >> to;
		adj_arr[from][to] = 1;
		adj_arr[to][from] = 1;
	}

	int now = 1;
	path.push_back(now);
	used[now] = 1;

	dfs(now); 

	used[now] = 0;
	path.pop_back();

	return 0;
}