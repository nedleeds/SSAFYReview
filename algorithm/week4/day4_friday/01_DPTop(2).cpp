#include <iostream>
#include <vector>
using namespace std;
int dir[] = { 2, 7 };
int MAP[151];
int mapSize;
int visited[10001];

int score;
int maxScore = -2134567890;
void dp(int now) {
	if (now >= mapSize){
		if (maxScore < score) {
			maxScore = score;
		}
		return;
	}

	for (int i = 0; i < 2; i++) {
		int next = now + dir[i];
		if (next < 1 || next > mapSize)
			continue;
		if (visited[next] != 0)
			continue;

		score = score + MAP[next];
		
		dp(next);
		score = score - MAP[next];
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();


	cin >> mapSize;
	for (int i = 1; i <= mapSize; i++)
		cin >> MAP[i];

	dp(0);
	cout << maxScore << '\n';

	return 0;
}