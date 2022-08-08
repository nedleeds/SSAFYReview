#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> adjList[101];
vector<int> path;
int visited[101];
int numNode, numEdge;

void dfs(int now) {
	/*if (adjList[now].size() == 0) {
		for (int i = 0; i < path.size(); i++)
			cout << path[i] << ' ';
		cout << '\n';
	}*/

	for (int i = 0; i < adjList[now].size(); i++) {
		int next = adjList[now][i];
		if (visited[next] != 0) continue;

		path.push_back(next);
		visited[next] = 1;

		dfs(next);
		path.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> numNode >> numEdge;

	for (int i = 0; i < numEdge; i++) {
		int from, to;
		cin >> from >> to;
		adjList[from].push_back(to);
		adjList[to].push_back(from);
	}

	visited[1] = 1;
	path.push_back(1);
	dfs(1);

	int cnt = 0;
	for (int i = 0; i < 101; i++) {
		if (visited[i] > 0) {
			cnt++;
		}
	}
	cout << cnt-1;
	return 0;
}
/*
한 노드와 연결된 모든 노드가 감염된다.
끊어진 노드여도 결국 그들의 그룹끼리 감염.

컴퓨터 수는 100이지만, 인접리스트로 구현해보자.

[입력]
1. 컴퓨터 수 입력
   컴퓨터 번호(노드 번호는 1번부터!!)

2. 둘째 줄부터 네트워크 상에서 연결된 쌍의 수가 주어짐
   쌍의 수만큼 from - to 입력

[출력]
1. 1번 컴퓨터가 바이러스 걸렸을 때, 총 바이러스에 걸리는 컴퓨터 수 출력

[설계]

기본 dfs 문제? - 한번만 반복 no
+ backtracking (path 추가)
+ 무방향
dfs(1) 넣고,
visited 체크 한 다음
path넣어야 돼
-------여기까지 일단 구현----------
visited 를 굳이 0으로 다시 초기화 안하고 놔두면,
방문한 곳들이 체크가 되고 다돌면 멈춰.
그럼 main에서 0이 아닌 곳 counting !!
-------일부 정답 처리 됨-------

이유는, 무방향이 아니었기 때문.
어떻게 알았느냐? --> 틀린 답의 경로가 작게 나왔고
왜 작게 나왔을까 생각해본 결과, 덜 돌았다는 판단.
그래서 무방향으로 다시 설정해서 돌린 결과 정답처리.

*/