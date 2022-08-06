#include <iostream>
#include <queue> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	
	priority_queue<int> pq; // default
	priority_queue<int, vector<int>, greater<int>> pq; // 작은 순서

	pq.push(5);
	pq.push(6);
	pq.push(3);
	pq.push(1);
	pq.push(4);
	pq.push(2);
	pq.push(777);

	while (!pq.empty()) {
		cout << pq.top();
		pq.pop();
	}

	return 0;
}
/*
필기
1. priority queue 라이브러리는 queue 라이브러리 안에 있다

2. priority_queue<int> pq;  - priority queue 선언하는 방법

3. 메서드
	1) push(): 삽입
	2) empty(): priority_queue가 비워져있는지 확인
	3) top(): priority_queue에서 우선순위가 제일 높은 data를 하나 확인
	4) pop(): priority_queue에서 우선순위가 제일 높은 data를 하나 삭제

4. 디버깅**
	1) while문 에 break point를 찍고 step 진행
	2) pq를 real time으로 진행하면 pq 순서가 내가 아는 순서가 아니다!!!
	3) -> 이유 : data가 ** heap 구조 **로 관리 되어지기 때문이다

5. heap 구조
	1) 654123 -> {6}-{5 / 4}-{1, 2 / 3} 이런 식으로 tree로 저장
	2) 근데!! tree가 그냥 tree가 아닌 " complete binary tree " 이다

6. complete binary tree 
	1) node 를 추가하는 순서 : 제일 왼쪽부터 채워간다
		a. root node : 1개 -> root 바로 채움
		b. level 2 parent node(5, 4) : 2개 노드니깐 왼쪽부터(5->4)
		c. level 3 parent node(1, 2, 3) : 3개 노드니깐 왼쪽부터(1->2->3)
	2) node를 생성하는 순서가 정해져있는 것이 complete binary tree의 특징

7. priority queue 를 볼때는 complete binary tree 를 그려서 보는 것이 파악하기 쉽다
	1) parent - child 관계에서 parent 노드의 우선순위가 항상 높아야한다
	2) 6-{5/3}-{1,4/2} 는 맞는 순서일까?
		: 맞다. 왜냐? 직접 적으로 연결 되어있는 node들에 대해서 parent - child 우선순위를 따진다
		: 즉, 6-{5}-{1,4} 가 성립, 6-{3}-{2} 가 성립하므로 이것은 priority queue 이다!!

8. 777 을 push 해준다면?
	1) 삽입 순서는 6-1)에서 말하듯, 왼쪽부터 확인한다
		a. {6}:차있다. (binary tree니깐 차있는지 확인 가능)
		b. {5 / 3}: 차있다
		c. {1, 4 / 2}: 하나 비어있네 ==> {1, 4 / 2, 777}
	2) 삽입된 (777)과 연결된 parent node {3}과 비교
		a. 어? {777}(child)가 {3}(parent) 보다 더 크네? 교체! 
			: {6} - {5 / 777} - {1, 4 / 3}
		b. 어? {777}(child)가 {6}(parent) 보다 더 크네? 교체!
			: {777} - {5 / 6} - {1, 4 / 3}
		c. 777 이 root가 되면서 종료 ~

9. 정리 : priority queue 구성 2가지
	1) complete binary tree 
	   - 특징 : 왼쪽부터 채운다
	2) 부모가 자식보다 우선순위보다 높아야 한다

10. priority queue 시간 복잡도
	1) complete binary tree
		-> 반복 횟수 : 1 (삽입은 바로 넣기 때문)
	2) 부모가 자식보다 우선순위보다 높아야 하는 경우 확인 시
		-> 반복 횟수  
			: 총 data 갯수 N이라 할 때, 최하위 level({1,4/2,3})에서
			  그 상위 level({5,6})으로 올라가게 되면 절반 씩 줄어든다!
			  --> N/(2^k) = 1 ---> k(level) = log2(N) = log(N)
	3) 따라서, 1개의 노드 추가시 log(N), n개의 노드 추가시, n*log(N)이 된다.

11. priority queue의 삭제
	: 마찬가지 특징 2가지 순서에 맞게 확인.
	1) complete binary tree 
		: 조건에 맞는 오른쪽 가장 아래 녀석을 체크해 root와 swap
		: {777} 과 {3}을 swap 후 777 삭제
	2) 부모가 자식보다 우선순위가 높은가?
		: {3} - {5/6} - {1, 4 / 2} 니깐, 6이랑 swap 이 되어야겠지?
		: 해당 작업은 logN (이유: root에서 마지막 노드까지 트리의 높이 logN)까지 체크해야돼.
		: 그래서 log(N)

12. priority queue 와 sort(in <alogrithm>) 의 시간 복잡도 차이
	let1) N개의 data가 주어진 상황
	1) sort 정렬: NlogN 보장
	2) priority queue: NlogN

	let2) ( let1)에다가 1개의 data를 추가적으로 넣고 처리 )* M번
	1) sort 정렬: M(N+M)log(N+M) 
	2) priority queue: Mlog(N+M) 
	3) N+M -> 데이터 추가할 때마다 총 데이터 수가 증가하니깐.

	정리)
	1)  !! data를 '추가'해가며 처리하는 경우 !! <- let2)
		즉, data가 변경될 수 있는 경우에는 priority queue가 더 좋다.

	2)	!! data 수가 변경되지 않는 경우 !!-> sort 라이브러리를 사용하는게 좋다.
		ex) 4번째로 큰 수를 찾아야 돼 -> sort는 DAT처럼 index == 4 로 바로 접근.O(1)
		즉, 우선 순위가 중간 정도인 애들을 확인 할 때는 sort 알고리즘이 적합하다.

	3) priority queue에서 data를 수정하는 시점
		a. data를 추가 할 때
		b. data를 삭제 할 때
		c. 그 외 중간 노드를 직접 수정하는 경우는 XXXXX

13. priority queue 사용하기
	1) default : 큰 값 우선 - less(<) 이용 
	   수정방향 : 작은 값 우선 - greate(>) 이용
			   : priority_queue<int, vector<int>, greater<int>> pq;
			   : 이게 귀찮다? 그럼 입력 값에 -달아서 음수로 넣고, 출력시 -붙여서 다시 양수로

오전 수업 샘플 코드
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

struct 비교구조 {
	bool operator()(int A, int B)
	{
		//return true : B가 우선순위가 높음
		// return false : A가 우선순위가 높음
		if (A < B) return false;
		if (A > B) return true;
		return false;
	} // 작은 값을 우선으로 쓰는 구조

};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	priority_queue<int> pq; // default : 큰 값 우선(operator<, less 상태)
	priority_queue<int, vector<int>, greater<int>> pqMIN1; // option : 작은 값 우선(operator>, grater로 세팅)
	priority_queue<int, vector<int>, 비교구조> pqMIN2; // option : 비교구조를 활용한 작은 값 우선(직접 만든 비교구조로 세팅)
	pq.push(6); // data 추가
	pq.empty(); //비어있는가?
	pq.size(); // data의 개수
	pq.top(); // 제일 우선순위가 높은 data확인
	pq.pop(); // 제일 우선순위가 높은 data삭제
}
*/