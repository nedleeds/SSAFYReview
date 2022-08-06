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
------------------[ �� ���� ]------------------
N*N*logN
pq���ٰ� left, right �ٹް�,
operator�� ���� ������������ ���� ���� 
���� �߻� 
--> ������ ���� �ٸ� ���� ���ʿ� �ִ� ���� ���� ũ��
    ����� ���� ����.

vector�� �ְ� sort �Ŀ� �߰��� ������� �׳�.

N�� ũ�Ⱑ 1���� �Ѿ�� ���۾���.

------------------[ ������ ���� ]------------------
priority_queue�� ����ϴ� ���� �����̴�.
N*logN �̶� �ξ� ȿ����.

�ٽ�
-> ���� �׷� / ���� �׷��� ������.
-> ���� �׷� : Max heap ( ���� ū ���� -> �� �� )
-> ���� �׷� : Min heap ( ���� ���� ���� -> �� �� )

����
1. �� �׷� -> min heap(���� �׷�) / max heap(���� �׷�)
	- priority_queue<int> maxheap (���� �׷쿡�� ���� �ȶ��� ��) 
		-> default operator: less + Max Heap
	- priority_queue<int ,vector<int>, greater<int>> minHeap (���� �׷쿡�� ���� ���ڶ� ��..)
		-> greater operator�� �ݴ� �����ڴϱ� Min Heap���� ����

2. �� �л��� ������ �޾����� 
	- �� �� ���� ��(bigger) �ȶ��ϰ� ��(smaller) �ȶ��Ѱ�?
	- minheap.push(bigger) + maxheap.push(smaller)
	- !!! �ٵ� !!
	  ���� �׷��� ¯ vs ���� �׷��� �� �Ʒ� -> ���������� �ٽ� ����� �� 
      if (maxheap.top() > minheap.top()) {
            // swap
            int temp = maxheap.top();
            maxheap.push(minheap.top());
            minheap.pop();
            minheap.push(temp);
            maxheap.pop(); 
        }
	- �׷��� maxheap�� top() �ϸ� ��! ��? ���� �׷쿡 �Ѹ��� �� ���� ����!
	  (�ʱ� maxheap�� 500�� �����ϱ�!)
*/