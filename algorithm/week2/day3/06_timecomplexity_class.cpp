#include <iostream>
using namespace std;

// 시간 복잡도 ( Time Complexity )
// --> 알고리즘 : 항상 " 최악의 경우만 생각 "

// 계산법 종류
// 오메가 -> 최선의 기준
// 세타   -> 평균(통계)의 기준
// 빅오   -> 최악의 기준

// 시간 복잡도의 랭킹
// VERY GOOD : 여기까지 구현되면 왠만해서 다 돌아감
// O(1) -> N 사이즈 관계 없이 무조건 바로 돌아감
// --> N = unlimited
// --> 대회문제 0.05 sec 준대
// --> 일반적으로 DAT 쓰는 문제. : O(1)

// O(log(2)N)
// --> N = unlimited
// --> 이진 탐색 (1~100 까지의 숫자 생각하고 맞추는 게임)
// ----------------------------------------------------

// GOOD : 우리가 구현하게 될 알고리즘의 시간 복잡도.
// O(n) -> linear time (선형) N limit = 1억 (for 문 1개)
// O(nlogn) -> 효율 좋은 정렬 알고리즘 (OElogV)
// ----------------------------------------------------

// 주의
// O(n^2) -> limit : n = 10,000 (for 문 2개)
// O(n^3) -> limit : n = 500 ==> floyd warshall ( 모든 노드로 -> 모든 노드의 최단거리, for 문 3개 )
// ----------------------------------------------------

// 진짜 완전 주의 걍 살얼음판
// O(2^n) --> 모든 combination !
// O(n!) -> limit : n= 11? 10? // 모든 permutation
// --> DFS + backtracking --> 가지치기가 중요한 이유.

// DFS BFS의 시간복잡도
// 인접 행렬 : O(Vertex^2)
// 인접 리스트 : O(Vertex + Edge)

int main() {
	// 1~n까지의 합을 구하는 프로그램
	int n;
	cin >> n;

	// 1. n = 1,000,000 -> 1,000,000번
	int sum = 0;
	for (int i = 0; i <= n; i++)
		sum += i;
	cout << sum << '\n';

	//2. n = 1,000,000 -> 1번
	sum = 0;
	sum = (n * (n + 1)) / 2;
	cout << sum << '\n';

	//3. n = 1,000,000 -> 1,000,000^2
	sum = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= n; j++)
			if (i == j)
				sum += i;
	cout << sum << '\n';

	return 0;
}