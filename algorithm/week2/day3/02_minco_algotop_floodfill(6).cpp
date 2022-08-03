#include <iostream>
#include <queue>
using namespace std;

int MAP[101][101];
int visited[101][101];

int dir[4][2] = {
	{-1, 0},
	{ 1, 0},
	{ 0,-1},
	{ 0, 1}
};

struct Pos {
	int r, c;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int rMax, cMax;
	cin >> rMax >> cMax;

	for (int r = 0; r < rMax; r++) {
		for (int c = 0; c < cMax; c++) {
			cin >> MAP[r][c];
		}
	}

	queue<Pos> q;
	
	int group = 1;
	for (int r = 0; r < rMax; r++) {
		for (int c = 0; c < cMax; c++) {
			if (MAP[r][c] == 1) {
				//¼¶ Ã£¾Ò´Ù!
				while (!q.empty()) {
					Pos now = q.front();
					q.pop();

					for (int i = 0; i < 4; i++) {
						Pos next = {
							now.r + dir[i][0],
							now.c + dir[i][1]
						};
						if (next.r < 0 || next.c < 0 || next.r >= rMax || next.c >= cMax)
							continue;

					}

				}
			}
		}
	}




	return 0;
}