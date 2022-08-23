#include <iostream>
using namespace std;

int parents[1001];
int memberCnt[1001];
int maxCnt;

int Find(int now) {
	if (parents[now] == now)
		return now;

	parents[now] = Find(parents[now]);
	return parents[now];
}

void Union(int a, int b) {
	int aRoot = Find(a);
	int bRoot = Find(b);

	if (aRoot == bRoot) return;


	parents[bRoot] = aRoot;
	memberCnt[aRoot] += memberCnt[bRoot];
	memberCnt[bRoot] = 0;
	if (memberCnt[aRoot] > maxCnt)
		maxCnt = memberCnt[aRoot];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		parents[i] = i;
		memberCnt[i] = 1;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){ 
			int num;
			cin >> num;
			if (num == 1) {
				Union(i, j);
			}
		}

	for (int i = 0; i < n; i++) {
		if (parents[i]);
	}

	int de = 1;
	return 0;
}