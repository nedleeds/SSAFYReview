#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
	int left, right;
}node;
vector<Node> adjList[1001];
vector<int> path1;
vector<int> path2;
vector<int> path3;
int visited[1001];
int numNode;

bool cmp(int a, int b) {
	if (a < b) return true;
	if (a > b) return false;
	return false;
}

void dfs_1(int now) {
	if (now == -1) {
		return;
	}

	Node next = adjList[now][0];
	vector<int> checklist = { next.left, next.right };

	for (int j = 0; j < 2; j++) {
		int nextNode = checklist[j];
		if (nextNode == -1) continue;
		if (visited[nextNode] != 0) continue;

		visited[nextNode] = 1;
		dfs_1(nextNode);
		
		path1.push_back(nextNode);
	}
}

void dfs_2(int now) {
	for (int i = 0; i < adjList[now].size(); i++) {
		Node next = adjList[now][i];
		vector<int> checklist = { next.right, next.left };
		for (int j = 0; j < checklist.size(); j++) {
			int nextNode = checklist[j];
			if (visited[nextNode] != 0) continue;

			visited[nextNode] = 1;
			dfs_2(nextNode);
			path2.push_back(nextNode);
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
			path3.push_back(nextNode);

		}
	}
}

void print_path(vector<int> p) {
	int i;
	for (i = 0; i < p.size() - 1; i++) {
		cout << p[i] << ' ';
	}
	cout << p[i] << '\n';
}

void print_reverse(vector<int> p) {
	int i;
	for (i = p.size() - 1; i >= 1; i--) {
		cout << p[i] << ' ';
	}
	cout << p[i] << '\n';
}

void init() {
	for (int i = 0; i < 1001; i++) {
		visited[i] = 0;
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
	print_path(path);

	init();
	cout << startNode << ' ';
	visited[startNode] = 1;
	dfs_2(startNode);
	print_reverse(path2);

	init();
	visited[startNode] = 1;
	dfs_3(startNode);
	path.push_back(startNode);
	print_path(path3);



	return 0;
}