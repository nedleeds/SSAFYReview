#include <iostream>
using namespace std;
/*
Union 
- ��ġ�� ����
- �׷��� �����ִ� ����
- ex) Union(A, B), Union(A, C), Union(D, E)
Find 
- ã�� ����
- ��ǥ ã�µ����� ���
- ��ǥ�� �������� �Ǵ�
- Find(B) => A

Union, Find �� �׻� '��ǥ'�� ����
*/
int parent[10];

int Find(int now) {
	if (now == parent[now]) // by �ʱ⼼��
		return now;
	// dfs ó�� ����
	int root = Find(parent[now]);
	parent[now] = root; // **
	// **: ��ǥ�� ã�⸸ �ϸ� �Ǳ� ������
	//     �ٷ� parent ������ root �� ����
	//     �׷� find ������ ���� ã�� �ʿ䰡 ����
	return root;
}


void Union(int a, int b) {
	// �׷��� �����ִ�(=�ϳ��� �����ִ�) �Լ�
	int aRoot= Find(a); // capA = a�� ��ǥ
	int bRoot = Find(b); // capB = b�� ��ǥ

	parent[bRoot] = aRoot;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	// 1. �� node�� �ڱ��ڽ��� ��ǥ��!(��� �и�)
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