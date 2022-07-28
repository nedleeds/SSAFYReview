#include <iostream>
#include <vector>
using namespace std;

int adj_arr[10][10];
vector<int> path;
int used[10];
int cntNode;
int cntEdge;

void dfs(int now) {

	for (int i = 0; i < path.size(); i++)
		cout << path[i] << " ";
	cout << '\n';

	for (int next = 0; next <= cntNode; next++) {
		if (adj_arr[now][next] == 0) continue;
		//if (used[next] == 1) continue;

		path.push_back(next);
		//used[next] = 1;

		dfs(next);

		//used[next] = 0;
		path.pop_back();
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();


	cin >> cntNode;
	for (int from = 0; from < cntNode; from++) {
		for (int to = 0; to < cntNode; to++) {
			cin >> adj_arr[from][to];
		}
	}

	int now = 0;
	path.push_back(now);
	used[now] = 1;

	dfs(now);

	used[now] = 0;
	path.pop_back();

	return 0;
}