#include <iostream>
using namespace std;
int dir[] = { 2, 7 };
int MAP[151];
int DP[151];
int mapSize;

int dp(int now) {
	if (now > mapSize)
		return -2134567890;
	
	int maxNextScore = -2134567890;
	for (int i = 0; i < 2; i++) {
		int next = now + dir[i];
		if (next < 1 || next > mapSize)
			continue;
		if (DP[next] != -2134567890)
			continue;

		int nextScore = max(maxNextScore, dp(next));
	}
	int nowScore = maxNextScore + MAP[now]; // 현재부터~ 끝까지 획득하는 점수
	DP[now] = nowScore;
	return nowScore;
}

void initDP(int initValue) {
	for (int i = 0; i < mapSize; i++)
		DP[i] = initValue;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	

	cin >> mapSize;
	for (int i = 1; i <= mapSize; i++)
		cin >> MAP[i];

	initDP(-2134567890);

	dp(0);
	cout << DP[1] << '\n';

	return 0;
}