#include <iostream>
#include <vector>
using namespace std;

int visited[10];
int adj_arr[10][10];
int nodeNum, startNode, endNode;
vector<int> path;

int cost = 0;
int minCost = 2134567890;
int maxCost = -2134567890;
void dfs(int node) {
	if (node == endNode) {
		if (minCost > cost) {
			minCost = cost;
		}
		if (maxCost < cost) {
			maxCost = cost;
		}
	}

	for (int next = 0; next < nodeNum; next++) {
		if (visited[next] == 1) continue;
		if (adj_arr[node][next] == 0) continue;

		cost += adj_arr[node][next];
		visited[next] += 1;
		path.push_back(node);

		dfs(next);
		
		path.pop_back();
		visited[next] -= 1;
		cost -= adj_arr[node][next];

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> nodeNum;

	for (int i = 0; i < nodeNum; i++) {
		for (int j = 0; j < nodeNum; j++) {
			cin >> adj_arr[i][j];
		}
	}

	cin >> startNode >> endNode;

	path.push_back(startNode);
	visited[startNode] = 1;
	dfs(startNode);
	visited[startNode] = 0;
	path.pop_back();

	cout << minCost << '\n';
	cout << maxCost << '\n';

	return 0;
}