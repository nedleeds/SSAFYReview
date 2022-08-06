#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int thisCost[100][100];
int toThisCost[100][100] = {2134567890};
int rMax, cMax;
struct Edge { int from, to, cost; };
int dir[4][2] = {
	{-1, 0},
	{ 1, 0},
	{ 0,-1},
	{ 0, 1}
};

bool operator < (Edge a, Edge b) {
	// < (default : Max heap) 
	// Min heap : return false
	if (a.cost < b.cost) return false;
	if (a.cost > b.cost) return false;

	return false;
}

void dijkstra(Edge start) {
	priority_queue<Edge> pq;
	pq.push(start);
	
	int toThisCost[100][100] = { 0, };
	for (int i = 0; i < rMax; i++)
		for (int j = 0; j < cMax; j++)
			toThisCost[i][j] = 2134567890;
	toThisCost[start.from][start.to] = thisCost[start.from][start.to];

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		if (toThisCost[now.from][now.to] < thisCost[now.from][now.to])
			continue;

		for (int i = 0; i < 4; i++) {
			Edge next = {	now.from + dir[i][0],
							now.to	 + dir[i][1]	};

			if (next.to < 0 || next.from < 0 || next.from >= rMax || next.to >= cMax)
				continue;
			
			next.cost = toThisCost[now.from][now.to] + thisCost[next.from][next.to];

			if (toThisCost[next.from][next.to] <= next.cost)
				continue;

			toThisCost[next.from][next.to] = next.cost;
			pq.push({ next.from, next.to, toThisCost[next.from][next.to] });
		}
	}
	cout << toThisCost[rMax - 1][cMax - 1] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	
	cin >> rMax >> cMax;
	for (int r = 0; r < rMax; r++) {
		for (int c = 0; c < cMax; c++) {
			cin >> thisCost[r][c];
		}
	}

	dijkstra({0, 0, thisCost[0][0]});

	return 0;
}