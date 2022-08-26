#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Pos { int row, col; };
struct Node { int idx, row, col, life, time; } germ;
queue<Node> deactivate, activate, dead;
vector<Pos> visited;


int startRowMax, startColMax, totalTime;
int dRow[4] = {-1, 1, 0, 0};
int dCol[4] = { 0, 0,-1, 1};
int visited[2501];
int taken[2501];

int isVisited(Pos g) {
	for (int i = 0; i < visited.size(); i++) {
		if ((visited[i].row == g.row) && (visited[i].col == g.col))
			return 1;
	}
	return 0;
}

int isTaken(Pos g) {
	// MAP �� �����ִ� germ���� row, col�̶� ��ġ�ϴ��� Ȯ��
	// deactivate + dead
	for (int i = 0; i < deactivate.size(); i++) {
		
	}
	for (int i = 0; i < deactivate.size(); i++) {

	}

	return 0;
}

void start(int totalTime) {
	while (totalTime > 0) {
		// 1. deactivate ť���� �ϳ��� ����
		germ = deactivate.front();
		deactivate.pop();

		// 2. ���� Ȯ��
		// 2-1 now ��: time+=1;
		germ.time++;
		if (germ.time == germ.life) {
			activate.push(germ);
		}
		// 2-2. next ��: ����迭�� �ϳ��� 
		for (int i = 0; i < 4; i++) {
			Node next = { germ.row + dRow[i], germ.col + dCol[i] ,
						 germ.life , germ.time };
			int nr = next.row;
			int nc = next.col;
			if (isTaken({nr, nc}) continue;
			if (isVisited({ nr, nc })) continue;
			

		}

		totalTime --;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		cin >> startRowMax >> startColMax >> totalTime;
		int idx = 0;
		for (int r = 0; r < startRowMax; r++) {
			for (int c = 0; c < startColMax; c++) {
				int life;
				cin >> life;
				deactivate.push({ idx, r, c, life, 0 });
			}
		}
	}
	start(totalTime);

	int de = 1;

	return 0;
}