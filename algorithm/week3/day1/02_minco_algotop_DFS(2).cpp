#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> adjList[101];
int visited[101];
vector<int> path1;
vector<int> path2;

bool cmp(int a, int b) {
	if (a < b) return false;
	if (a > b) return true;
	return false;
}

int push_check(vector<int> path, int next) {
	for (int i = 0; i < path.size(); i++) {
		if (path[i] == next) {
			return 0;
		}
	}
	return 1;
}

void dfs(int now) {

	sort(adjList[now].begin(), adjList[now].end(), cmp);
	for (int i = 0; i < adjList[now].size(); i++) {
		int next = adjList[now][i];
		if (visited[next] != 0) continue;

		visited[next] = 1;
		if (push_check(path1, next))
			path1.push_back(next);
		dfs(next);
		if (push_check(path2, next))
			path2.push_back(next);
		visited[next] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int numNode, numEdge, startNode;
	cin >> numNode >> numEdge >> startNode;

	for (int i = 0; i < numEdge; i++) {
		int from, to;
		cin >> from >> to;
		adjList[from].push_back(to);
	}

	visited[startNode] = 1;
	path1.push_back(startNode);
	dfs(startNode);
	path2.push_back(startNode);

	for (int i = 0; i < path1.size(); i++) {
		cout << path1[i] << ' ';
	}
	cout << '\n';
	for (int i = 0; i < path2.size(); i++) {
		cout << path2[i] << ' ';
	}



	return 0;
}

/* [�� ����] - ���� ����Ʈ�� Ǯ����
DFS + Backtracking �ε�,
next index�� �ݴ�� ����� �����ʺ��� ����.
--> �Ϻ� ���� ó��

��...
�ϴ�, �湮�� ���� �ٽ� ����ϴ� ���� 1
����� child ���� �� ū �� ���� ����ؾߵǴµ� �׷��� ���ϰ� ����
--->sort �Ἥ �ƽ� ���� ����.
*/