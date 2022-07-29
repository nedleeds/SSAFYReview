#include <iostream>
#include <vector>
using namespace std;

vector<int> path;
int startNode, endNode;

int adj_mtx[7][7] = {
	// 0  1  2  3  4  5  6
	  {0, 0, 0, 0, 0, 0, 0}, // 0
	  {0, 0, 0, 1, 0, 1, 1}, // 1
	  {0, 1, 0, 0, 1, 0, 0}, // 2
	  {0, 0, 0, 0, 0, 1, 0}, // 3
	  {0, 1, 0, 0, 0, 0, 0}, // 4
	  {0, 1, 0, 0, 0, 0, 0}, // 5
	  {0, 0, 0, 0, 0, 0, 0}  // 6
};
int visited[10];
int nowCost = 0;
int minCost = 2134567890;

void dfs(int now) {
	if (now == endNode) {
		if (minCost > nowCost) {
			minCost = nowCost;
		}
	}

	for (int next = 1; next <= 6; next++) {
		if (adj_mtx[now][next] == 0) continue;
		if (visited[next] == 1) continue;
		if (nowCost > minCost) continue;

		path.push_back(next);
		visited[next] = 1;
		nowCost += 1;

		dfs(next);

		nowCost -= 1;
		visited[next] = 0;
		path.pop_back();
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> startNode >> endNode;

	path.push_back(startNode);
	visited[startNode] = 1;
	dfs(startNode);
	visited[startNode] = 0;
	path.pop_back();

	if (minCost == 2134567890) {
		cout << 0 << '\n';
	}
	else{
		cout << minCost << '\n';
	}

	return 0;
}