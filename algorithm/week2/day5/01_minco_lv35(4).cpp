#include <iostream>
#include <queue>
using namespace std;

struct Edge {
	int nodeFrom;
	int nodeTo;
	int cost;
};

bool operator < (Edge a, Edge b) {
	// < : greater operator : default - MINMAX Heap (return true)
	// return false : MIN HEAP (작은게 우선순위가 더 높다)
	if (a.cost < b.cost) return false;
	if (a.cost > b.cost) return true;

	// if a.cost == b.cost
	if (a.nodeFrom < b.nodeFrom) return false;
	if (a.nodeFrom > b.nodeFrom) return true;

	// if a.cost == b.cost && a.nodeFrom == a.nodeFrom
	if (a.nodeTo < b.nodeTo) return false;
	if (a.nodeTo > b.nodeTo) return true;

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int num;
	cin >> num;

	//priority_queue에다가 간선 정보 + cost 입력 
	priority_queue<Edge> pq;
	for (int r = 0; r < num; r++) {
		for (int c = 0; c < num; c++) {
			int cost;
			cin >> cost;
			if (cost <= 0) continue;
			if (r >= c) continue;
			pq.push({ r, c, cost });
		}
	}

	//cost 값들만 추출해서 vector에 넣기
	int cnt = 0;
	Edge e;
	while (cnt < 10) {
		e = pq.top();
		e.cost *= 2;
		pq.pop();
		pq.push(e);
		cnt++;
	}
	
	cout << e.cost << "만원\n";

	return 0;
}
/*
-----------------[ 내 설계 1 ]-----------------
1.	priority_queue
	-> 간선 정보 + cost 입력 

2.	vector 에 cost 값만 넣기 (틀림)
	-> 여기서 문제 발생
	-> 문제의 조건에 맞춰서 pq가 생성되는데,
	-> 옮기면서 cost 기준으로만 진행됨.

3. vector 내부의 값들에 *=2 진행 (틀림)

-----------------[ 내 설계 2 ]-----------------
1. priority_queue -> 간선 + cost

2-A. priority_queue 
	-> pop 하지 않고, front() 값 추출
	-> front() *= 2
	-> 이걸 10번 반복.
	-> index = index % pq.size()
	   index++;
	==> !!! pq는 index 접근이 불가 !!!
	==> HEAP 구조라서 pop으로 최상위 node꺼내고
	    push로 삽입만 가능하다.
	==> 실제 문제 내용도, push 과정에서 cost에 따른
	    순서가 바뀌는 걸 고려해야 정답처리가 됐다.
	==> 따라서 수정된 풀이는 2-B.와 같다.

2-B. priority_queue
	-> 총 10번의 반복문
	-> 해당 반복문 안에서 top()을 e(Edge) 꺼내고 pop()
	-> e의 costs *= 2 (가격 증가)
	-> push(): 자동으로 overriding 된 식에 의해 정렬됨.
	-> 반복문 종료 후 e 출력
	
-----------------[ 교수님 설계 ]-----------------
나랑 동일
*/