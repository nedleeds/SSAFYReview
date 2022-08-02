#include <iostream>
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
7
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
	int adj_mtx[10][10] = { 0, };

	// 1. 그래프 구성
	cin >> nodeNum;
	for (int i = 0; i < nodeNum; i++) {
		int from, to;
		cin >> from >> to;
		adj_mtx[from][to] = 1;
	}

	// 2. Queue 생성
	queue<int> q; // queue에 넣는 정보 : !! Node 정보 !!


	// 3. 시작 노드 세팅
	int startNode = 1;
	q.push(startNode);

	// 7. 4~6단계 반복
	// queue가 비워지지 않았다 == 감염시켜 나갈 예정인 node(next)가 남았다.
	while(!q.empty()) { 
		// 4.queue에서 node(now)를 하나 꺼냄
		int now = q.front(); // now -> 이번에 감염을 시켜나갈 node
		q.pop();

		// ----- 이번에 now를 들렸다 -------
		cout << now << ' ';
		// --------------------------------

		// 5. now에서 갈 수 있는 node(next)들 찾기.
		for (int next = 1; next <= 9; next++) {
			if (adj_mtx[now][next] == 0) continue; // now->next 로 갈 수 없다

			// next를 찾았다!!!

			// now->next 가능 : 감염시킬 수 있다!
			// 6. next를 queue에다가 넣어준다.
			q.push(next);
		}
	}


	return 0;
}