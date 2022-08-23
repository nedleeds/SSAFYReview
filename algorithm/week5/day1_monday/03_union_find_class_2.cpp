#include <iostream>
using namespace std;

int parents[10];
int memberCnt[10];
int maxNumMember[10];

int Find(int now) {

	if (parents[now] == now)
		return now;

	parents[now] = Find(parents[now]);
}

void Union(int a, int b) {
	int aRoot = Find(a);
	int bRoot = Find(b);

	if (aRoot == bRoot) return;
	// A와 B가 이미 같은 그룹이었다 -> 아무 것도 하지마

	// A와 B가 다른 그룹인경우
	parents[bRoot] = aRoot; //bRoot의 부모를 aRoot로 설정

	/* ------- 조건 추가시 수정되는 영역 ------- */
	// 대표를 바꾸는 거니깐 딸린 정보(멤버수)도 넘겨줘야돼
	memberCnt[aRoot] += memberCnt[bRoot];
	memberCnt[bRoot] = 0;
}

int main() {

	for (int i = 0; i < 10; i++) {
		parents[i] = i;
		/* ------- 조건 추가시 자기 초기화 영역 ------- */
		memberCnt[i] = 1;
	}


	Union(1, 2);
	Union(2, 3);
	Union(1, 4);
	
	// Q. 2번에 속한 그룹이 몇 명이니?
	cout << "Group 2's memeber: " << memberCnt[Find(2)] <<'\n';

	Union(2, 5);
	Union(6, 7);
	Union(7, 8);
	Union(5, 8);

	cout << "Group 3's memeber: " << memberCnt[Find(3)] <<'\n';

	return 0;
}