#include <iostream>
#include <vector>

using namespace std;

int adj_arr[10][10];
int nodeNum;
int visited[10];
vector<int> path;
int paths[10][100];

/* adj_arr 이 다음과 같을 때, path 모두를 출력하라.
7
0 0 0 0 1 0 1
0 0 0 0 0 1 0
1 1 0 1 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
*/	

void dfs(int now) {
	int s = 0;

	for (int c = 0; c < nodeNum; c++) {
		s += adj_arr[now][c];
	}
	if (s == 0) {
		for (int k = 0; k < path.size(); k++) {
			cout << path[k] << ' ';
		}
		cout << '\n';
	}

	for (int next = 0; next < nodeNum; next++) {
		if (adj_arr[now][next] == 0) {		
			continue;
		};
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

	int M = -2134567890;
	int M_idx = 0;
	for (int from = 0; from < nodeNum; from++) {
		int s = 0;
		for (int to = 0; to < nodeNum; to++) {
			cin >> adj_arr[from][to];
			s += adj_arr[from][to];
		}
		if (s > M) {
			// find root node.
			M = s;
			M_idx = from;
		}
	}
	
	visited[M_idx] = 1;
	path.push_back(M_idx);
	dfs(M_idx);
	visited[M_idx] = 0;
	path.pop_back();
	return 0;
}