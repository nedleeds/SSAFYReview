#include <iostream>
#include <queue> 
using namespace std;

struct Node {
	int row, col;
};


bool operator<(Node A, Node B) {
	// < : ture ( 오름차순 )
	// *** TIP : PQ는 C++에서는 default가 max heap이기 때문에 ***
	//	         기본 정렬이 내림차순이니까 반대다! -> 사실 틀린 거지만 외우기는 좋다.

	if (A.row < B.row)   // 오름차순 정렬: < 에서는 정상적인 상태
		return false;	 // return false;
	if (A.row > B.row)   // 내림차순 정렬: < 에서는 비정상적인 상태
		return true;	 // return true;

	// col : 우선순위 오름차순 정렬
	//	   : A.row < B.row
	if (A.col < B.col) return true;
	if (A.col > B.col) return false;

	return false;
}

void sturct_priority_queue() {
	//priority_queue<Node> pq;
	priority_queue<Node> pq;

	pq.push({ 5, 3 });
	pq.push({ 4, 3 });
	pq.push({ 2, 7 });
	pq.push({ 1, 9 });
	pq.push({ 4, 2 });
	pq.push({ 5, 7 });

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	sturct_priority_queue();

	return 0;
}
/*
필기
1. 

*/