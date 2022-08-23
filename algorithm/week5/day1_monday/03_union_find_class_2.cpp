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
	// A�� B�� �̹� ���� �׷��̾��� -> �ƹ� �͵� ������

	// A�� B�� �ٸ� �׷��ΰ��
	parents[bRoot] = aRoot; //bRoot�� �θ� aRoot�� ����

	/* ------- ���� �߰��� �����Ǵ� ���� ------- */
	// ��ǥ�� �ٲٴ� �Ŵϱ� ���� ����(�����)�� �Ѱ���ߵ�
	memberCnt[aRoot] += memberCnt[bRoot];
	memberCnt[bRoot] = 0;
}

int main() {

	for (int i = 0; i < 10; i++) {
		parents[i] = i;
		/* ------- ���� �߰��� �ڱ� �ʱ�ȭ ���� ------- */
		memberCnt[i] = 1;
	}


	Union(1, 2);
	Union(2, 3);
	Union(1, 4);
	
	// Q. 2���� ���� �׷��� �� ���̴�?
	cout << "Group 2's memeber: " << memberCnt[Find(2)] <<'\n';

	Union(2, 5);
	Union(6, 7);
	Union(7, 8);
	Union(5, 8);

	cout << "Group 3's memeber: " << memberCnt[Find(3)] <<'\n';

	return 0;
}