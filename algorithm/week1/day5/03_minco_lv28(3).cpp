#include <iostream>
#include <vector>

using namespace std;

int adj_arr[8][8] = {
	//	 A  B  C  D  E  F  G  H
		{0, 1, 1, 0, 0, 0, 0, 1}, // A
		{1, 0, 0, 0, 0, 0, 0, 0}, // B
		{1, 0, 0, 1, 1, 0, 1, 0}, // C
		{0, 0, 1, 0, 0, 1, 0, 0}, // D
		{0, 0, 1, 0, 0, 0, 0, 0}, // E
		{0, 0, 0, 1, 0, 0, 0, 0}, // F
		{0, 0, 1, 0, 0, 0, 0, 0}, // G
		{1, 0, 0, 0, 0, 0, 0, 0}, // H
};
vector<int> path;
vector<int> under;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	char node;
	cin >> node;
	int nodeNum = node - 'A';

	// 노드의 형제 ?
	// 현재 노드가 to 일 때,
	// adj_arr[from][to들]==1 이고 to 가 입력받은 본인이 아니면 형제.
	int cnt = 0;
	for (int from = 0; from < 8; from++) {
		for (int to = 0; to < 8; to++) {
			if (to == nodeNum) {
				if (adj_arr[from][to] == 1) {
					for (int to2 = 0; to2 < 8; to2++) {
						if (adj_arr[from][to2] == 1 && to2 != to) {
							cout << char(to2+'A') << ' ';
							cnt++;
						}
					}
				}
				if (cnt == 0) cout << "없음";
				cout << '\n';
				return 0;
			}
		}
	}

	return 0;
}