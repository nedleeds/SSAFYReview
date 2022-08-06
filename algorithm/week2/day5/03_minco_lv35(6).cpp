#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	vector<int> scores;
	scores.push_back(500);

	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		int left, right;
		cin >> left >> right;
		scores.push_back(left);
		scores.push_back(right);
		sort(scores.begin(), scores.end());
		cout << scores[scores.size() / 2] << '\n';
	}

	return 0;
}
/*
------------------[ 내 설계 ]------------------
N*N*logN
pq에다가 left, right 다받고,
operator는 왼쪽 점수기준으로 내림 차순 
문제 발생 
--> 오른쪽 값이 다른 행의 왼쪽에 있는 값들 보다 크면
    제대로 동작 안함.

vector에 넣고 sort 후에 중간값 출력하자 그냥.

N의 크기가 1억이 넘어가면 동작안해.

------------------[ 교수님 설계 ]------------------
priority_queue를 사용하는 것이 목적이다.
N*logN 이라 훨씬 효율적.

핵심
-> 하위 그룹 / 상위 그룹을 나눈다.
-> 하위 그룹 : Max heap ( 가장 큰 점수 -> 맨 위 )
-> 상위 그룹 : Min heap ( 가장 작은 점수 -> 맨 위 )

설계
1. 두 그룹 -> min heap(상위 그룹) / max heap(하위 그룹)
	- priority_queue<int> maxheap (하위 그룹에서 가장 똑똑한 애) 
		-> default operator: less + Max Heap
	- priority_queue<int ,vector<int>, greater<int>> minHeap (상위 그룹에서 가장 모자란 애..)
		-> greater operator는 반대 연산자니깐 Min Heap으로 동작

2. 두 학생의 점수를 받았으면 
	- 둘 중 누가 더(bigger) 똑똑하고 덜(smaller) 똑똑한가?
	- minheap.push(bigger) + maxheap.push(smaller)
	- !!! 근데 !!
	  하위 그룹의 짱 vs 상위 그룹의 맨 아래 -> 서열정리를 다시 해줘야 함 
      if (maxheap.top() > minheap.top()) {
            // swap
            int temp = maxheap.top();
            maxheap.push(minheap.top());
            minheap.pop();
            minheap.push(temp);
            maxheap.pop(); 
        }
	- 그러고 maxheap에 top() 하면 끝! 왜? 하위 그룹에 한명이 더 많기 때문!
	  (초기 maxheap에 500을 넣으니깐!)
*/