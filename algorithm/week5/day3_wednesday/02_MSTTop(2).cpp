//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int cntStar;
//int parent[101];
//struct Star { int r, c; } star;
//struct Edge { int from, to; double cost; };
//vector<Star> stars;
//vector<int> v;
//vector<Edge> edges;
//
//bool cmp(Edge a, Edge b) {
//	if (a.cost < b.cost) return true;
//	if (a.cost > b.cost) return false;
//	return false;
//}
//
//int Find(int now) {
//	if (parent[now] == now)
//		return now;
//
//	return parent[now] = Find(now);
//}
//
//int Union(int a, int b) {
//	int aParent = Find(a);
//	int bParent = Find(b);
//	
//	parent[bParent] = aParent;
//}
//
//double getDist(Star A, Star B) {
//	return (A.r - B.r) * (A.r - B.r) + (A.c - B.c) * (A.c - B.c);
//}
//
//int kruskal() {
//	// sorting
//	sort(edges.begin(), edges.end(), cmp);
//
//	for (int i=0; i<edges.size(); i++)
//
//	
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie();
//	cout.tie();
//
//	cin >> cntStar;
//
//	for (int i = 0; i < cntStar; i++)
//		parent[i] = i;
//
//	for (int i = 0; i < cntStar; i++){
//		cin >> star.r >> star.c;
//		stars.push_back(star);
//	}
//
//	for (int i = 0; i < cntStar; i++) {
//		for (int j = i + 1; j < cntStar; j++) {
//			double d = getDist(stars[i], stars[j]);
//			edges.push_back({ i, j, d });
//		}
//	}
//
//	int ans = kruskal();
//	cout << ans;
//
//	return 0;
//}