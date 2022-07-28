#include <iostream>
using namespace std;

/*
5
1 2
1 3
2 4
2 5
*/

// tree from adjacent matrix
int arr[6][6] = { 0 }; //adjacent matrix: arr[from][to] -> tree�ϱ� arr[parent][child]
int nodeNum;

void dfs(int now) { // ���� now��� node�� �ִ�
	// now ���� �� �� �ִ� next��� node�� ���� !
	// arr[now][????] == 1
	// Ư�� node���� �� �� �ִ� node ã�� !!

	// ���� ������ ��� �ӿ���, �Ʒ��� ��� ���ǿ���
	// next node( child node )�� ���� ��� continue�� ���
	// ������ �Ǹ鼭 ���� for�� �ε���, �� ���� for�� �ε��� 
	// �ᱹ for���� ���ᰡ �ȴ�. �׷��� �Ǹ� call�� ����Լ�����
	// �ڵ����� �ϳ��� ���ᰡ �ǰ� �ȴ�.

	// ��, ���� ��� �޿���� ���� ������ child��忡��
	// arr[now][next] == 0 �̱� ������, continue -> for �� ���� -> dfs ���� -> return ;
	// ���� ���� dfs�� ���ư�.�׷��� �� ���� next node ���� �Ǵ��� �̷�� ����.!!

	cout << now << '\n';
	for (int next = 1; next <= nodeNum; next++) {
		if (arr[now][next] == 0) {
			continue; // child(next node)�� ������ ����!!
		}
		dfs(next);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> nodeNum;

	for (int i = 1; i <nodeNum; i++) {
		int parent, child;
		cin >> parent >> child;
		arr[parent][child] = 1;
	}

	// DFS : Depth First Search (with tree)
	//       -> ���� Ž�� !! (��� ���� �� ��������.)

	// 1. tree���� ��� ��带 �� ������� !! (��� ���)
	dfs(1);

	return 0;
}