#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int cap[101];
int MAP[10001][10001];
struct Pos { double row, col; };
vector<Pos> stars;

struct Edge { Pos n1, n2; double cost; int finned; };

int Find(int node) {
	if (cap[node] == node)
		return node;

	return cap[node] = Find(node);
}

void Union(int a, int b) {
	int aCap = Find(a);
	int bCap = Find(b);

	if (aCap == bCap) return;

	cap[bCap] = aCap;
}

double getDistance(Pos a, Pos b) {
	return sqrt((a.row - b.row) * (a.row - b.row) + (a.col - b.col) * (a.col - b.col));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int numStar;
	cin >> numStar; // get the # of stars

	for (int i = 0; i < numStar; i++) {
		double row, col;
		cin >> row >> col;
		MAP[int(row * 100)][int(col * 100)] = 1;
	} 

	// parent 초기 세팅
	for (int i = 0; i < 101; i++) {
		cap[i] = i;
	}

	// solve
	int ans = kruskal();

	return 0;
}