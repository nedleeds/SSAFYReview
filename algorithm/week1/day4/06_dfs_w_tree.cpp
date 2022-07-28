#include <iostream>
#include <vector>
using namespace std;

/*
5
1 2
1 3
2 4
2 5
*/

// tree from adjacent matrix
int arr[6][6] = { 0 }; //adjacent matrix: arr[from][to] -> tree니깐 arr[parent][child]
vector<int> adjacent_list[100];
int nodeNum;

void dfs_adjacent_array(int now) { // 지금 now라는 node에 있다
	// now 에서 갈 수 있는 next라는 node로 가라 !
	// arr[now][????] == 1
	// 특정 node에서 갈 수 있는 node 찾기 !!

	// 기저 조건은 재귀 임에도, 아래의 재귀 조건에서
	// next node( child node )가 없는 경우 continue를 계속
	// 만나게 되면서 다음 for문 인덱스, 그 다음 for문 인덱스 
	// 결국 for문이 종료가 된다. 그렇게 되면 call된 재귀함수들이
	// 자동으로 하나씩 종료가 되게 된다.

	// 즉, 깊이 대로 쭈우우우욱 들어가서 마지막 child노드에서
	// arr[now][next] == 0 이기 때문에, continue -> for 문 종료 -> dfs 종료 -> return ;
	// 이전 층의 dfs로 돌아감.그러고 그 층의 next node 유무 판단이 이루어 진다.!!

	cout << now << '\n';
	for (int next = 1; next <= nodeNum; next++) {
		if (arr[now][next] == 0) {
			continue; // child(next node)가 없으면 무시!!
		}
		dfs_adjacent_array(next);
	}
}

void dfs_adjacent_list(int now) {
	cout << now << '\n';
	for (int i = 0; i < adjacent_list[now].size(); i++) {
		int next = adjacent_list[now][i];
		dfs_adjacent_list(next);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> nodeNum;

	for (int i = 1; i < nodeNum; i++) {
		int parent, child;
		cin >> parent >> child;
		//arr[parent][child] = 1; // 인접 행렬인 경우.
		adjacent_list[parent].push_back(child);
	}

	// DFS : Depth First Search (with tree)
	//       -> 완전 탐색 !! (모든 것을 다 돌려본다.)

	// 1. tree에서 모든 노드를 다 들려보자 !! (재귀 사용)
	//dfs_adjacent_array(1); // -> 인접 행렬로 구현한 것 !!

	dfs_adjacent_list(1);

	return 0;
}