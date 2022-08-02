#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> adjList[11];
int visited[11];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int numNode, numEdge;
	cin >> numNode >> numEdge;

	// 1. get the graph.
	for (int i = 0; i < numEdge; i++) {
		int from, to;
		cin >> from >> to;
		adjList[from].push_back(to);
		adjList[to].push_back(from);
	}

	int jobLocation, numRide;
	cin >> jobLocation >> numRide;
	if (numRide == 0){
		cout << 1 << '\n';
		return 0;
	}

	// 2. create the queue.
	queue<int> q;

	// 3. initialization
	q.push(jobLocation);
	visited[jobLocation] = 1;

	// 7. iterate till queue is empty
	while (!q.empty()) {
		// 4. get the current node
		int now = q.front();
		q.pop();
		
		/*cout << now << "(" << visited[now] << ")" << "->";*/
		for (int i = 0; i < adjList[now].size(); i++) {
			// 5. get the next node.
			int next = adjList[now][i];
			
			// 6. check the next node.
			// adjacent list doen't need to check ability to enter.
			// only thing needed to be checked is whether we have
			// visited before.
			if (visited[next] > 0) continue;
			visited[next] = visited[now] + 1;
			if (now == jobLocation)
				visited[next] -= 1;
			q.push(next);
		}
	}

	int cnt = 0;
	for (int i = 0; i <= numNode; i++) {
		if (0 < visited[i] && visited[i] <= numRide) {
			cnt += 1;
		}
	}
	cout << cnt << '\n';

	return 0;
}