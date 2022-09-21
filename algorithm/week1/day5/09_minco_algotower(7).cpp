#include <iostream>
#include <vector>
using namespace std;

// 1. (기본 DFS) --> 그냥 모든 노드를 한번씩 들려보는거 
// 2. DFS + Backtracking --> 모든 경로를 들러보는것 

int nodeNum;
int adj_mtx[13][13];

vector<int> path;
int visited[13];
int cost;
int minCost = 2134567890;

void dfs(int node) {
	if (adj_mtx[node][1] > 0 && cost > 0) {
		if (minCost > cost) {
			minCost = cost;
			for (int i = 0; i < path.size(); i++) {
				cout << path[i] << ' ';
			}
			cout << '\n';
		}
	}

	for (int next = 1; next <= nodeNum; next++) {
		if (visited[next] == 1) continue;
		if (adj_mtx[node][next] == 0) continue;
		if (cost > minCost) continue;

		visited[next] = 1;
		path.push_back(next);
		cost += adj_mtx[node][next];

		dfs(next);

		path.pop_back();
		visited[next] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> nodeNum;

	for (int from = 1; from < nodeNum; from++) {
		for (int to = 1; to < nodeNum; to++) {
			cin >> adj_mtx[from][to];
		}
	}

	visited[1] = 1;
	path.push_back(1);
	dfs(1);
	path.pop_back();
	visited[1] = 0;

	cout << minCost << '\n';


	return 0;
}
