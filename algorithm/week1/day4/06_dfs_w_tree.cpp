#include <iostream>
#include <vector>
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
vector<int> adjacent_list[100];
int nodeNum;

void dfs_adjacent_array(int now) { // ���� now��� node�� �ִ�
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
		dfs_adjacent_array(next);
	}
}

void dfs_adjacent_list(int now) {
	cout << now << '\n';
	for (int i = 0; i < adjacent_list[now].size(); i++) {
		int next = adjacent_list[now][i];
		dfs_adjacent_list(next);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> nodeNum;

	for (int i = 1; i < nodeNum; i++) {
		int parent, child;
		cin >> parent >> child;
		//arr[parent][child] = 1; // ���� ����� ���.
		adjacent_list[parent].push_back(child);
	}

	// DFS : Depth First Search (with tree)
	//       -> ���� Ž�� !! (��� ���� �� ��������.)

	// 1. tree���� ��� ��带 �� ������� !! (��� ���)
	//dfs_adjacent_array(1); // -> ���� ��ķ� ������ �� !!

	dfs_adjacent_list(1);

	return 0;
}