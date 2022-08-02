#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct HP { int to, hp; };
vector<HP> adjList[100001];
int visited[100001];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int numNode, numEdge, hpLimit;
	cin >> numNode >> numEdge >> hpLimit;

	// 1. get the tree.
	HP start = {0,0};
	for (int i = 0; i < numEdge; i++) {
		int from, to, hp;
		cin >> from >> to >> hp;
		adjList[from].push_back({ to, hp });
		if (from == 1) {
			start = { from, 0 };
		}
	}

	// 2. create the queue.
	queue<HP> q;
	
	// 3. set the intial value.
	q.push(start);
	visited[start.to] = start.hp;

	// 7. iterate till q is empty.
	int cnt = 0 ;
	while (!q.empty()) {
		// 4. get the current node.
		HP now = q.front();
		q.pop();

		/*cout << now.to << visited[now.to];*/
		//cout << now.to << " cost : " << visited[now.to] << '\n';
		cnt++;

		for (int i = 0; i < adjList[now.to].size(); i++) {
			// adjacent list doesn't need to check the next one.
			// as it has already checked by its size.
			HP next = adjList[now.to][i];
			if (visited[next.to] != 0) continue;

			// next accumulated hp value
			// = next.hp + current accumulated hp value
			visited[next.to] = visited[now.to] + next.hp;

			if (visited[next.to] > hpLimit) continue;
			q.push(next);
		}
	}

	cout << cnt - 1 << '\n';

	return 0;
}