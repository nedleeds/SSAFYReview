#include <iostream>
#include <queue> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	
	priority_queue<int> pq; // default
	priority_queue<int, vector<int>, greater<int>> pq; // ���� ����

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
�ʱ�
1. priority queue ���̺귯���� queue ���̺귯�� �ȿ� �ִ�

2. priority_queue<int> pq;  - priority queue �����ϴ� ���

3. �޼���
	1) push(): ����
	2) empty(): priority_queue�� ������ִ��� Ȯ��
	3) top(): priority_queue���� �켱������ ���� ���� data�� �ϳ� Ȯ��
	4) pop(): priority_queue���� �켱������ ���� ���� data�� �ϳ� ����

4. �����**
	1) while�� �� break point�� ��� step ����
	2) pq�� real time���� �����ϸ� pq ������ ���� �ƴ� ������ �ƴϴ�!!!
	3) -> ���� : data�� ** heap ���� **�� ���� �Ǿ����� �����̴�

5. heap ����
	1) 654123 -> {6}-{5 / 4}-{1, 2 / 3} �̷� ������ tree�� ����
	2) �ٵ�!! tree�� �׳� tree�� �ƴ� " complete binary tree " �̴�

6. complete binary tree 
	1) node �� �߰��ϴ� ���� : ���� ���ʺ��� ä������
		a. root node : 1�� -> root �ٷ� ä��
		b. level 2 parent node(5, 4) : 2�� ���ϱ� ���ʺ���(5->4)
		c. level 3 parent node(1, 2, 3) : 3�� ���ϱ� ���ʺ���(1->2->3)
	2) node�� �����ϴ� ������ �������ִ� ���� complete binary tree�� Ư¡

7. priority queue �� ������ complete binary tree �� �׷��� ���� ���� �ľ��ϱ� ����
	1) parent - child ���迡�� parent ����� �켱������ �׻� ���ƾ��Ѵ�
	2) 6-{5/3}-{1,4/2} �� �´� �����ϱ�?
		: �´�. �ֳ�? ���� ������ ���� �Ǿ��ִ� node�鿡 ���ؼ� parent - child �켱������ ������
		: ��, 6-{5}-{1,4} �� ����, 6-{3}-{2} �� �����ϹǷ� �̰��� priority queue �̴�!!

8. 777 �� push ���شٸ�?
	1) ���� ������ 6-1)���� ���ϵ�, ���ʺ��� Ȯ���Ѵ�
		a. {6}:���ִ�. (binary tree�ϱ� ���ִ��� Ȯ�� ����)
		b. {5 / 3}: ���ִ�
		c. {1, 4 / 2}: �ϳ� ����ֳ� ==> {1, 4 / 2, 777}
	2) ���Ե� (777)�� ����� parent node {3}�� ��
		a. ��? {777}(child)�� {3}(parent) ���� �� ũ��? ��ü! 
			: {6} - {5 / 777} - {1, 4 / 3}
		b. ��? {777}(child)�� {6}(parent) ���� �� ũ��? ��ü!
			: {777} - {5 / 6} - {1, 4 / 3}
		c. 777 �� root�� �Ǹ鼭 ���� ~

9. ���� : priority queue ���� 2����
	1) complete binary tree 
	   - Ư¡ : ���ʺ��� ä���
	2) �θ� �ڽĺ��� �켱�������� ���ƾ� �Ѵ�

10. priority queue �ð� ���⵵
	1) complete binary tree
		-> �ݺ� Ƚ�� : 1 (������ �ٷ� �ֱ� ����)
	2) �θ� �ڽĺ��� �켱�������� ���ƾ� �ϴ� ��� Ȯ�� ��
		-> �ݺ� Ƚ��  
			: �� data ���� N�̶� �� ��, ������ level({1,4/2,3})����
			  �� ���� level({5,6})���� �ö󰡰� �Ǹ� ���� �� �پ���!
			  --> N/(2^k) = 1 ---> k(level) = log2(N) = log(N)
	3) ����, 1���� ��� �߰��� log(N), n���� ��� �߰���, n*log(N)�� �ȴ�.

11. priority queue�� ����
	: �������� Ư¡ 2���� ������ �°� Ȯ��.
	1) complete binary tree 
		: ���ǿ� �´� ������ ���� �Ʒ� �༮�� üũ�� root�� swap
		: {777} �� {3}�� swap �� 777 ����
	2) �θ� �ڽĺ��� �켱������ ������?
		: {3} - {5/6} - {1, 4 / 2} �ϱ�, 6�̶� swap �� �Ǿ�߰���?
		: �ش� �۾��� logN (����: root���� ������ ������ Ʈ���� ���� logN)���� üũ�ؾߵ�.
		: �׷��� log(N)

12. priority queue �� sort(in <alogrithm>) �� �ð� ���⵵ ����
	let1) N���� data�� �־��� ��Ȳ
	1) sort ����: NlogN ����
	2) priority queue: NlogN

	let2) ( let1)���ٰ� 1���� data�� �߰������� �ְ� ó�� )* M��
	1) sort ����: M(N+M)log(N+M) 
	2) priority queue: Mlog(N+M) 
	3) N+M -> ������ �߰��� ������ �� ������ ���� �����ϴϱ�.

	����)
	1)  !! data�� '�߰�'�ذ��� ó���ϴ� ��� !! <- let2)
		��, data�� ����� �� �ִ� ��쿡�� priority queue�� �� ����.

	2)	!! data ���� ������� �ʴ� ��� !!-> sort ���̺귯���� ����ϴ°� ����.
		ex) 4��°�� ū ���� ã�ƾ� �� -> sort�� DATó�� index == 4 �� �ٷ� ����.O(1)
		��, �켱 ������ �߰� ������ �ֵ��� Ȯ�� �� ���� sort �˰����� �����ϴ�.

	3) priority queue���� data�� �����ϴ� ����
		a. data�� �߰� �� ��
		b. data�� ���� �� ��
		c. �� �� �߰� ��带 ���� �����ϴ� ���� XXXXX

13. priority queue ����ϱ�
	1) default : ū �� �켱 - less(<) �̿� 
	   �������� : ���� �� �켱 - greate(>) �̿�
			   : priority_queue<int, vector<int>, greater<int>> pq;
			   : �̰� ������? �׷� �Է� ���� -�޾Ƽ� ������ �ְ�, ��½� -�ٿ��� �ٽ� �����

���� ���� ���� �ڵ�
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

struct �񱳱��� {
	bool operator()(int A, int B)
	{
		//return true : B�� �켱������ ����
		// return false : A�� �켱������ ����
		if (A < B) return false;
		if (A > B) return true;
		return false;
	} // ���� ���� �켱���� ���� ����

};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	priority_queue<int> pq; // default : ū �� �켱(operator<, less ����)
	priority_queue<int, vector<int>, greater<int>> pqMIN1; // option : ���� �� �켱(operator>, grater�� ����)
	priority_queue<int, vector<int>, �񱳱���> pqMIN2; // option : �񱳱����� Ȱ���� ���� �� �켱(���� ���� �񱳱����� ����)
	pq.push(6); // data �߰�
	pq.empty(); //����ִ°�?
	pq.size(); // data�� ����
	pq.top(); // ���� �켱������ ���� dataȮ��
	pq.pop(); // ���� �켱������ ���� data����
}
*/