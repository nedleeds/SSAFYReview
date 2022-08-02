#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> adjList[100001 * 2];
vector<int> path;
long long visited[100001 * 2];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int numStation, numH2S, numHyperEdges;
	cin >> numStation >> numH2S >> numHyperEdges;

	for (int i = 1; i <= numHyperEdges; i++) {
		// hyper tube info.
		vector<int> info;
		for (int j = 0; j < numH2S; j++) {
			int num;
			cin >> num;
			adjList[i + 100000].push_back(num);
			adjList[num].push_back(i + 100000);
		}
	}

	queue<int> q;

	int startStation = 1;
	int endStation = numStation;
	int stationCnt = 0;
	q.push(startStation);
	visited[startStation] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		
		for (int i = 0; i < adjList[now].size(); i++) {
			int next = adjList[now][i];
			if (visited[next] != 0) continue;

			visited[next] = visited[now] + 1;
			q.push(next);
		}
	}

	if (visited[endStation] == 0)
		cout << -1;
	else
		cout << (visited[endStation] + 1) / 2 << '\n';
		// (visited[endStation] + 1) / 2 -> 역 - 하 - 역 - 하 - 역 - 하

	return 0;
}