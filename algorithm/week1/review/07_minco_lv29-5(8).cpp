#include <iostream>
#include <vector>
using namespace std;

char MAP[4][3];
int dir[4][2] = {
	{0, 1},
	{1, 0},
	{0,-1},
	{-1,0},
};
struct Point {
	int row, col;
	char alphabet;
};

vector<Point> Monsters;

void sortMonsters() {
	for (int j = 0; j < Monsters.size()-1; j++) {
		for (int k = 1; k < Monsters.size(); k++) {
			if (Monsters[j].alphabet > Monsters[k].alphabet) {
				Point tmp = Monsters[j];
				Monsters[j] = Monsters[k];
				Monsters[k] = tmp;
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 3; c++) {
			char monster;
			cin >> monster;
			MAP[r][c] = monster;
			if ('A' <= MAP[r][c] && MAP[r][c] <= 'Z') {
				Monsters.push_back({ r, c, MAP[r][c]});
			}
		}
	}

	sortMonsters();

	// Monster 들을 움직인다. (5초)
	// 움직이고 나서 (nr, nc)가 
	// #과 겹치면 stop, 
	// 알파벳끼리 겹치면 겹치면 stop, 
	// 범위 벗어나면 stop

	for (int time = 0; time < 5; time++) {
		int idx = time % 4;
		for (int i=0; i<Monsters.size(); i++) {
			int nr = Monsters[i].row + dir[idx][0];
			int nc = Monsters[i].col + dir[idx][1];
			if ((0 <= nr && nr < 4) && (0 <= nc && nc < 3)){
				if (MAP[nr][nc] == '_') {
					char tmp = MAP[Monsters[i].row][Monsters[i].col];
					MAP[Monsters[i].row][Monsters[i].col] = '_';
					MAP[nr][nc] = tmp;
					Monsters[i].row = nr;
					Monsters[i].col = nc;
				}
			}
		}
	}

	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 3; c++) {
			cout << MAP[r][c];
		}
		cout << '\n';
	}

	return 0;
}
