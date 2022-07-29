#include <iostream>
#include <vector>

using namespace std;

int nodeNum;
int adj_arr[10][10];
vector<int> path;
vector<int> under;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> nodeNum;

	for (int from = 0; from < nodeNum; from++) {
		int s = 0;
		for (int to = 0; to < nodeNum; to++) {
			cin >> adj_arr[from][to];
		}
	}

	// from -> to (to 가 0일 때 -> from 은 boss)
	// from 이 0일 떄 to 는 under 
	
	int boss = 0;
	vector<int> under;
	for (int from = 0; from < nodeNum; from++) {
		for (int to = 0; to < nodeNum; to++) {
			if (to == 0 && adj_arr[from][to]) {
				boss = from;
			}
			else if (from == 0 && adj_arr[from][to]) {
				under.push_back(to);
			}
		}
	}

	cout << "boss:" << boss << "\nunder:";
	for (int i = 0; i < under.size(); i++) {
		cout << under[i] << ' ';
	}
	

	return 0;
}