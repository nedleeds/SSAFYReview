#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dRow[4] = { -1, 1, 0, 0 };
int dCol[4] = { 0, 0, -1, 1 };
int MAP[10][10];
int visited[10][10];
int rowMax, colMax;
struct Node { int row, col; };
vector<Node> blanks;
vector<Node> viruses;

int impactCnt;
void dfs(Node now) {
	for (int i = 0; i < 4; i++) {
		Node next = { now.row + dRow[i], now.col + dCol[i] };
		if (visited[next.row][next.col] != 0) continue;
		if (MAP[next.row][next.col] != 0) continue;

		visited[next.row][next.col] = 1;
		impactCnt++;
		dfs(next);
	}
}

void initVisted() {
	for (int row = 1; row <= rowMax; row++)
		for (int col = 1; col <= colMax; col++) {
			if (MAP[row][col] != 0)
				visited[row][col] = 1;
			else
				visited[row][col] = 0;
		}
}

int getMaxArea() {
	int maxArea = -2134567890;
	for (int i = 0; i < blanks.size(); i++)
		for (int j = i + 1; j < blanks.size(); j++)
			for (int k = j + 1; k < blanks.size(); k++) {
				Node v1 = blanks[i];
				Node v2 = blanks[j];
				Node v3 = blanks[k];

				MAP[v1.row][v1.col] = 1;
				MAP[v2.row][v2.col] = 1;
				MAP[v3.row][v3.col] = 1;

				initVisted();
				impactCnt = 0;
				for (int i = 0; i < viruses.size(); i++)
					dfs(viruses[i]);

				int safeArea = int(blanks.size()) - impactCnt - 3;
				if (maxArea < safeArea)
					maxArea = safeArea;

				MAP[v1.row][v1.col] = 0;
				MAP[v2.row][v2.col] = 0;
				MAP[v3.row][v3.col] = 0;
			}
	return maxArea;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> rowMax >> colMax;
	// MAP 초기화 1로 -> dir 로 1인 경우 continue 적용
	// 이렇게하면 nr, nc 범위 체크 필요 x
	for (int row = 0; row < 10; row++)
		for (int col = 0; col < 10; col++) {
			MAP[row][col] = 1;
		}

	for (int row = 1; row <= rowMax; row++)
		for (int col = 1; col <= colMax; col++) {
			cin >> MAP[row][col];
			if (MAP[row][col] == 0) {
				blanks.push_back({ row, col });
			}
			else {
				visited[row][col] = 1;
				if (MAP[row][col] == 2)
					viruses.push_back({ row, col });
			}
		}

	cout << getMaxArea() << '\n';

	return 0;
}

// node 하나에서 갈 수 있는 모든 경로 탐색 -> DFS, BFS
// 차이는? 
// 
// 1) 구현 상의 차이
//	  DFS는 가야하는 Node를 vector로 넣어서 for문으로 탐색
//    BFS는 가야하는 Node를 queue로 넣어서 while !queue.empty()로 탐색
// 
// 2) 동작 과정의 차이
//	  DFS는 노드 하나에서 갈 수 있는 가장 깊은 곳을 재귀로 접근
//	  BFS는 노드 하나에서 출발해 근처 갈 수 있는 곳을 queue에다 넣고 접근
//