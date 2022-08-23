#include <iostream>
using namespace std;
/*
Union 
- 합치는 역할
- 그룹을 묶어주는 역할
- ex) Union(A, B), Union(A, C), Union(D, E)
Find 
- 찾는 역할
- 대표 찾는데에도 사용
- 대표를 기준으로 판단
- Find(B) => A

Union, Find 는 항상 '대표'가 기준
*/
int parent[10];

int Find(int now) {
	if (now == parent[now]) // by 초기세팅
		return now;
	// dfs 처럼 만듦
	int root = Find(parent[now]);
	parent[now] = root; // **
	// **: 대표를 찾기만 하면 되기 때문에
	//     바로 parent 값으로 root 값 설정
	//     그럼 find 때마다 굳이 찾을 필요가 없음
	return root;
}


void Union(int a, int b) {
	// 그룹을 묶어주는(=하나로 합쳐주는) 함수
	int aRoot= Find(a); // capA = a의 대표
	int bRoot = Find(b); // capB = b의 대표

	parent[bRoot] = aRoot;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	// 1. 각 node가 자기자신이 대표다!(모두 분리)
	for (int i = 1; i <= 6; i++)
		parent[i] = i;
	

	// 2. Union
	Union(1, 2);
	Union(1, 3);
	Union(4, 5);
	Union(3, 5);

	int de = 1;
	return 0;
}