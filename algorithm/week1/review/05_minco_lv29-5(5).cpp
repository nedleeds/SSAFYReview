#include <iostream>
#include <vector>
using namespace std;

int arr[4][5];
int visited[4][5];
int dir[4][2] = {
	{-1, 0},
	{ 1, 0},
	{ 0,-1},
	{ 0, 1}
};

struct Node {
	int row;
	int col;
};

vector<Node> path;
int pathSize;

void check(Node now) {
	// 기저 조건
	if (path.size() == pathSize) {
		cout << "(" << path[0].row << "," << path[0].col << ")\n";
		cout << "(" << path[pathSize-1].row << "," << path[pathSize - 1].col << ")\n";
	}

	// 재귀 호출
	for (int i = 0; i < 4; i++) {
		Node next = { now.row + dir[i][0], now.col + dir[i][1] };
		if (0 > next.row || next.row > 3 || 0 > next.col || next.col > 4)
			continue;
		if (arr[next.row][next.col] == 0) continue;
		if (visited[next.row][next.col] == 1) continue;

		path.push_back(next);
		visited[next.row][next.col] = 1;
		check(next);
	}
}

/* (1,2) (2,4)
0 0 0 0 0
0 0 1 1 0
0 0 1 1 1
0 0 0 0 0
*/

/* (0,1) (2,3)
0 1 0 0 0
0 1 0 0 0
0 1 1 1 0
0 0 0 0 0
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	// 입력 받기
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 5; c++) {
			cin >> arr[r][c];
			if (arr[r][c] == 1) {
				pathSize += 1;
			}
		}
	}

	// start Node 구하기.
	Node start;
	int flag = 0;
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 5; c++) {
			if (arr[r][c] == 1){
				start = { r, c };
				flag = 1;
				break;
			}
		}
		if (flag) break;
	}

	// 경로 1번만 출력 -> 기본 DFS
	visited[start.row][start.col] = 1;
	path.push_back(start);
	check(start);


	return 0;
}