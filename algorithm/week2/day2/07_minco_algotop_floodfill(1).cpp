#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int row, col;
};

int dir[4][2] = {
	{1, 0},
	{-1, 0},
	{0, -1},
	{0, 1},
};

int visited[5][5];

void bfs(Node now) {
	queue<Node> q;
	q.push(now);

	visited[now.row][now.col] = 1;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			Node next = { now.row + dir[i][0], now.col + dir[i][1] };
			if (next.row < 0 || next.col < 0 || next.row>4 || next.col>4)
				continue;
			if (visited[next.row][next.col] != 0) 
				continue;
			
			visited[next.row][next.col] = visited[now.row][now.col] + 1;
			q.push(next);
		}
	}
}

Node start;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> start.row >> start.col;

	bfs(start);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << visited[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}