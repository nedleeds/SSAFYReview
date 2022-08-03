#include <iostream>
#include <queue>
using namespace std;
string MAP[5];
int visited1[5][5];
int visited2[5][5];

int dir[5][2] = {
	{-1, 0},
	{ 1, 0},
	{ 0,-1},
	{ 0, 1},
	{0, 0}
};

struct pos {
	int r, c;
}anna, elsa;

int N;

int checkRange(pos now) {
	if (now.r < 0 || now.c < 0 || now.r >= N || now.c >= N)
		return 1;
	else
		return 0;
}
int maxArr[5][5];

void getMax(int arr1[5][5], int arr2[5][5]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr1[i][j] > arr2[i][j]) {
				maxArr[i][j] = arr1[i][j];
			}
			else {
				maxArr[i][j] = arr2[i][j];
			}
		}
	}
}

int getMin() {
	int m = 2134567890;
	for (int r = 0; r < 5; r++) {
		for (int c = 0; c < 5; c++) {
			if (m > maxArr[r][c] && maxArr[r][c] > 0)
				m = maxArr[r][c];
		}
	}
	return m;
}

void floodfill(pos start, int visited[5][5]) {
	queue<pos> q;
	q.push(start);
	visited[start.r][start.c] = 1;

	while (!q.empty()) {
		pos now = q.front();
		q.pop();

		for (int i = 0; i < 5; i++) {
			pos next = { now.r + dir[i][0] , now.c + dir[i][1] };

			if (checkRange(next))
				continue;
			if (visited[next.r][next.c] > 0)
				continue;
			if (MAP[next.r][next.c] == '#')
				continue;

			visited[next.r][next.c] = visited[now.r][now.c] + 1;

			q.push(next);
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> N;
	for (int i = 0; i < 5; i++) {
		cin >> MAP[i];
	}

	cin >> anna.r >> anna.c >> elsa.r >> elsa.c;

	floodfill(anna, visited1);
	floodfill(elsa, visited2);

	getMax(visited1, visited2);
	cout << getMin()-1 << '\n';
	return 0;
}