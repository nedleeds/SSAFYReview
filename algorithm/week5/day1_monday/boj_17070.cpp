#include <iostream>
#include <vector>
using namespace std;

int rowMax;
int MAP[17][17];
int visited[17][17];

int dir[3][2][3] = {
	{	{0, 1, 0},
		{2, 2, 0}	}, // pipe:1

	{	{ 2, 2, 0 },
		{ 0, 1, 0 }	}, // pipe:2

	{	{ 2, 2, 0},
		{ 0, 1, 2}	}  // pipe:3
};


struct Pos { int r, c; };
vector<Pos> path;
// move +> new Dir + 해당 방향으로 한번더 증가(체크해보자)
// 일단 dir에 맞춰서 dfs + backtracking 구현
int cnt;
void dfs(Pos now) {
	if (now.r == rowMax && now.c == rowMax) {

		for (int i = 0; i < path.size(); i++) {
			cout << '{' << path[i].r << ", " << path[i].c << "} ";
		}
		cout << '\n';
		cnt++;
		return;
	}


	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i <= 1 && j == 2) 
				continue;
			Pos next = { now.r + dir[i][0][j], now.c + dir[i][1][j] };

			if (next.r <= 0 || next.c <= 0 || next.r > rowMax || next.c > rowMax)
				continue;
			if (MAP[next.r][next.c] == 1)
				continue;
			if (visited[next.r][next.c] != 0)
				continue;
			if (i==0 && next.r)

			visited[next.r][next.c] = 1;
			path.push_back(next);

			dfs(next);

			visited[next.r][next.c] = 0;
			path.pop_back();
		}

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> rowMax;

	for (int row = 1; row <= rowMax; row++) {
		for (int col = 1; col <= rowMax; col++) {
			cin >> MAP[row][col];
		}
	}


	Pos start = { 1, 1 };
	visited[1][1] = 1;
	path.push_back({ 1, 1 });
	dfs(start);

	cout << cnt;

	return 0;
}