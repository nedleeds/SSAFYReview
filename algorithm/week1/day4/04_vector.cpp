#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int cntNode, cntEdge;
	vector<int> adjacent_matrix[100][100]; // vector<저장할 data type>
	cin >> cntNode >> cntEdge;

	// adjacent matrix 저장하기.
	for (int i = 0; i < adjacent_matrix[0][0].size(); i++) {
		int from, to;
		cin >> from >> to;

		adjacent_matrix[from][to].push_back(1); // push !!
		//v[to][from].push_back(1); // 무방향 인접 리스트 !! 
	}
	int node;
	cin >> node;

	for (int i = 0; i < cntNode; i++) {
		if (adjacent_matrix[node][i].size() != 0) {
			cout << i << " ";
		}
	}
	cout << '\n';

	// adjacent list 저장하기.
	vector<int> adjacent_list[100];
	for (int i = 0; i < cntEdge; i++) {
		int from, to;
		cin >> from >> to;
		adjacent_list[from].push_back(to);
	}
	int selected_node;
	cin >> selected_node;
	for (int i = 0; i < adjacent_list[i].size(); i++) {
		// vector.size ==> 해당 vector의 데이터 수를 반환.
		cout << adjacent_list[selected_node][i] << ' ';
	}
	cout << '\n';

	return 0;
}