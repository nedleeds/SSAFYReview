#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> adjList[100001];
int visited[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int numNode, numEdge;
	cin >> numNode >> numEdge;

	// 1. get the graph
	for (int i = 0; i < numEdge; i++) {
		int from, to;
		cin >> from >> to;
		adjList[from].push_back(to);
		adjList[to].push_back(from);
	}

	// 2. create queue
	queue<int> q;

	// 3. set the init value
	int start;
	cin >> start;
	q.push(start);
	visited[start] = 1;
	
	int cnt = 0;
	// 7. iterate till queue is empty.
	while (!q.empty()) {
		// 4. get the current node
		int now = q.front();
		q.pop();

		for (int idx = 0; idx < adjList[now].size(); idx++) {
			int next = adjList[now][idx];
			// 5. check the condition of next 
			if (visited[next] != 0) continue;
			cnt++;

			// 6. push the checked next node to the queue.
			//cout << next << ' ';
			visited[next] = 1;
			q.push(next);
		}
	}

	cout << cnt << '\n';
	return 0;
}