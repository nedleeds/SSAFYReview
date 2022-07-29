#include <iostream>
#include <vector>
using namespace std;

int nodeNum;
int edgeNum;

int visited[10];
int cnt = 0;
vector<int> path;
vector<int> adj_list[100];

void dfs(int node) {

	if (adj_list[node].size() == 0) {
		for (int i = 0; i < path.size(); i++) {
			cout << path[i] << ' ';
		}
	}

	for (int next = 1; next <= adj_list[node].size(); next++) {
		if (visited[next] == 1) continue;
		visited[next] = 1;
		path.push_back(next);
		dfs(next);
		//path.pop_back();
		//visited[next] = 0;
		/* 
		fundamental DFS structure.
		you need to check the idea of why I'm using 
		released the previous checked one.
		*/
	}
}

int main() {

	cin >> nodeNum;
	cin >> edgeNum;

	for (int i = 0; i < edgeNum; i++) {
		int from, to;
		cin >> from >> to;
		adj_list[from].push_back(to);
		adj_list[to].push_back(from);
	}
	
	path.push_back(1);
	visited[1] = 1;

	dfs(1);

	visited[1] = 0;
	path.pop_back();

	return 0;
}
