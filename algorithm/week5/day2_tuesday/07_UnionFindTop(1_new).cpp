#include <iostream>
using namespace std;

int captain[1001];

int Find(int node) {
	if (captain[node] == node)
		return node;

	return captain[node] = Find(captain[node]);
}

void Union(int a, int b) {
	int aCap = Find(a);
	int bCap = Find(b);

	if (aCap == bCap) return;

	captain[bCap] = aCap;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int N, Q;
	cin >> N >> Q;
	
	for (int i = 1; i <= N; i++) {
		captain[i] = i;
	}
	
	for (int i = 1; i <= Q; i++) {
		int checkNum, from, to;
		cin >> checkNum >> from >> to;

		if (checkNum == 1) {
			Union(from, to);
		}
		else {
			if (Find(from) == Find(to))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}