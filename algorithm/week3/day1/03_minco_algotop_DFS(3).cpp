#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
	int left, right;
}node;
vector<Node> adjList[1001];
vector<int> path;
int visited[1001];
int numNode;

bool cmp(int a, int b) {
	if (a < b) return true;
	if (a > b) return false;
	return false;
}

vector<int> path2;
void dfs_1(int now) {
	Node next = adjList[now][0];
	vector<int> checklist = { next.left, next.right };

	if (next.left == -1 && next.right == -1) {
		if (visited[now] == 1) {
			path.push_back(now);
			visited[now]++;
		}
		return;
	}

	for (int j = 0; j < 2; j++) {
		int nextNode = checklist[j];
		if (nextNode == -1) continue;
		if (visited[nextNode] != 0) continue;


		visited[nextNode] = 1;
		if (visited[now] == 1 && checklist[0] == -1) {
			path.push_back(now);
			path.push_back(checklist[1]);
			visited[now]++;
			visited[checklist[1]]++;
		}
		dfs_1(nextNode);
		if (visited[now] == 1) {
			path.push_back(now);
			visited[now]++;
		}
	}
}

void dfs_2(int now) {
	for (int i = 0; i < adjList[now].size(); i++) {
		Node next = adjList[now][i];
		vector<int> checklist = { next.right, next.left };
		for (int j = 0; j < checklist.size(); j++) {
			int nextNode = checklist[j];
			if (nextNode == -1) continue;
			if (visited[nextNode] != 0) continue;

			visited[nextNode] = 1;
			dfs_2(nextNode);
			path.push_back(nextNode);

		}
	}
}

void dfs_3(int now) {
	for (int i = 0; i < adjList[now].size(); i++) {
		Node next = adjList[now][i];
		vector<int> checklist = { next.left, next.right };
		for (int j = 0; j < checklist.size(); j++) {
			int nextNode = checklist[j];
			if (nextNode == -1) continue;
			if (visited[nextNode] != 0) continue;

			visited[nextNode] = 1;
			dfs_3(nextNode);
			path.push_back(nextNode);

		}
	}
}

void print_path() {
	int i;
	for (i = 0; i < path.size() - 1; i++) {
		cout << path[i] << ' ';
	}
	cout << path[i] << '\n';
}

void print_reverse() {
	int i;
	for (i = path.size() - 1; i >= 1; i--) {
		cout << path[i] << ' ';
	}
	cout << path[i] << '\n';
}

void init() {
	for (int i = 0; i < 1001; i++) {
		visited[i] = 0;
	}
	while (!path.empty()) {
		path.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> numNode;
	for (int i = 0; i < numNode; i++) {
		int from;
		cin >> from >> node.left >> node.right;
		adjList[from].push_back(node);
	}

	int startNode = 1;
	visited[startNode] = 1;
	dfs_1(startNode);
	print_path();

	init();
	cout << startNode << ' ';
	visited[startNode] = 1;
	dfs_2(startNode);
	print_reverse();

	init();
	visited[startNode] = 1;
	dfs_3(startNode);
	path.push_back(startNode);
	print_path();



	return 0;
}