#include <iostream>
#include <queue> 
using namespace std;

struct Node {
	int row, col;
};


bool operator<(Node A, Node B) {
	// < : ture ( �������� )
	// *** TIP : PQ�� C++������ default�� max heap�̱� ������ ***
	//	         �⺻ ������ ���������̴ϱ� �ݴ��! -> ��� Ʋ�� ������ �ܿ��� ����.

	if (A.row < B.row)   // �������� ����: < ������ �������� ����
		return false;	 // return false;
	if (A.row > B.row)   // �������� ����: < ������ ���������� ����
		return true;	 // return true;

	// col : �켱���� �������� ����
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
�ʱ�
1. 

*/