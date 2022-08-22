//#include <iostream>
//#include <vector>
//using namespace std;
//int steps[] = { 2, 7 };
//int MAP[151];
//int DP[151];
//int mapSize;
//int initialMAX = -2134567890;
//
//int maxScore = initialMAX;
//int dp(int now) {
//	if (now > mapSize){
//		DP[now] = MAP[now];
//		return MAP[now];
//	}
//
//	int maxNextScore = initialMAX;
//	for (int i = 0; i < 2; i++) {
//		int next = now + steps[i];
//		if (next < 0 || next > mapSize)
//			continue;
//		if (DP[next] != -2134567890)
//			continue;
//		int nextScore = max(maxNextScore, dp(next));
//
//		if (maxNextScore < nextScore)
//			maxNextScore = nextScore;
//	}
//	int nowScore = maxNextScore + MAP[now];
//	DP[now] = nowScore;
//	return nowScore;
//}
//
//void initDP(int initValue) {
//	for (int i = 0; i < 151; i++)
//		DP[i] = initValue;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie();
//	cout.tie();
//
//	cin >> mapSize;
//	for (int i = 1; i <= mapSize; i++)
//		cin >> MAP[i];
//
//	initDP(initialMAX);
//	cout << dp(0) << '\n';
//
//	return 0;
//}