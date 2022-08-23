#include <iostream>
#include <vector>
using namespace std;

int parents[1001];
int memberCnt[1001];
int maxCnt;
int flag;
struct Edge { int from, to; };
vector<Edge> edges;

int Find(int now) {
	if (parents[now] == now)
		return now;

	parents[now] = Find(parents[now]);
	return parents[now];
}

void Union(int a, int b) {
	int aRoot = Find(a);
	int bRoot = Find(b);

	if (aRoot == bRoot) {
		cout << "WARNING\n";
		flag = 1;
		return;
	};

	parents[bRoot] = aRoot;
	memberCnt[aRoot] += memberCnt[bRoot];
	memberCnt[bRoot] = 0;
	if (memberCnt[aRoot] > maxCnt)
		maxCnt = memberCnt[aRoot];
}