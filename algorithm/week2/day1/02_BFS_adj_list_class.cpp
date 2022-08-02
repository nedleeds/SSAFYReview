#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//BFS 특징
/*
- 완전 탐색 (연결된 모든 node를 들린다.)
- Queue를 사용한다.
- **최소한의 node를 들리는** 방법.
  (그 중 최단 거리를 구하는 경우에 사용되기도 한다)
  (!! 무조건은 아니다 !!)
*/

/* input
9
1 2
1 7
2 3
3 4
4 5
4 6
8 9
*/

/* BFS 제작 순서
1. 그래프 구성(입력을 받는다) - 각 node 간 관계
2. queue를 생성
3. 시작 노드 생성
------------------- 준비완료
4. queue에서 node(now)를 하나 꺼냄
   ㄴ> 감염 시켜나갈 예정인 node
5. now 에서 갈 수 있는 node(next)들 찾기
6. next 들을  queue에 추가

7. 4~6 단계 반복
   ㄴ> 언제까지? 더 이상 감염이 일어나지 않을 때 까지.
   ㄴ> == queue 가 비워지는 타이밍.

복잡해 보이지만, 단계만 알고 구현하면
코드 상의 BFS는 거의 항상 동일하다.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int nodeNum;
	vector<int> adj_lst[10];
	cin >> nodeNum;

	// 1. 그래프 구현
	for (int i = 0; i < nodeNum; i++) {
		int from, to;
		cin >> from >> to;
		adj_lst[from].push_back(to);
	}

	// 2. queue 생성
	queue<int> q;

	// 3. 시작 노드 세팅
	q.push(1);

	// 7. queue가 비워질 때까지
	while (!q.empty())
	{
		// 4. now node 꺼내기
		int now = q.front();
		q.pop();

		// 4-1) now node 다루기
		cout << now << ' ';

		// 5. next node queue에 넣기
		for (int i = 0; i < adj_lst[now].size(); i++) {
			int next = adj_lst[now][i];

			q.push(next);
		}
	}

	return 0;
}