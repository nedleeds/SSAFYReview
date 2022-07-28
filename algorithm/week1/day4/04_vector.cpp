#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int cntNode, cntEdge;
	vector<int> adjacent_matrix[100][100]; // vector<������ data type>
	cin >> cntNode >> cntEdge;

	// adjacent matrix �����ϱ�.
	for (int i = 0; i < adjacent_matrix[0][0].size(); i++) {
		int from, to;
		cin >> from >> to;

		adjacent_matrix[from][to].push_back(1); // push !!
		//v[to][from].push_back(1); // ������ ���� ����Ʈ !! 
	}
	int node;
	cin >> node;

	for (int i = 0; i < cntNode; i++) {
		if (adjacent_matrix[node][i].size() != 0) {
			cout << i << " ";
		}
	}
	cout << '\n';

	// adjacent list �����ϱ�.
	vector<int> adjacent_list[100];
	for (int i = 0; i < cntEdge; i++) {
		int from, to;
		cin >> from >> to;
		adjacent_list[from].push_back(to);
	}
	int selected_node;
	cin >> selected_node;
	for (int i = 0; i < adjacent_list[i].size(); i++) {
		// vector.size ==> �ش� vector�� ������ ���� ��ȯ.
		cout << adjacent_list[selected_node][i] << ' ';
	}
	cout << '\n';

	return 0;
}