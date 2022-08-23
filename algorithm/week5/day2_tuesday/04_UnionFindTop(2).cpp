//#include <iostream>
//#include <vector>
//using namespace std;
//
//int parents[27];
//int MAP[27][27];
//int GroupCnt[27];
//struct Edge { char from, to; }edge;
//vector<Edge> edges;
//
//int Find(int node) {
//	if (node == parents[node])
//		return node;
//
//	return parents[node] = Find(parents[node]);
//}
//
//void Union(int a, int b){
//	int aRoot = Find(a);
//	int bRoot = Find(b);
//
//	if (aRoot == bRoot) return;
//
//	parents[bRoot] = aRoot;
//	GroupCnt[aRoot] += GroupCnt[bRoot];
//	GroupCnt[bRoot] = 0;
//}
//
//int main() {
//	int numEdges;
//	cin >> numEdges;
//
//	for (int i = 0; i < 27; i++) {
//		parents[i] = i;
//		GroupCnt[i] = 1;
//	}
//
//	for (int j = 0; j < numEdges; j++) {
//		char x, y;
//		cin >> x >> y;
//		MAP[x - 'A'][y - 'A'] = 1;
//	}
//
//	for (int r = 0; r < 27; r++) {
//		for (int c = 0; c < 27; c++) {
//			if (MAP[r][c] == 1) {
//				if (Find(r) == Find(c))
//					continue;
//				Union(r, c);
//			}
//		}
//	}
//	
//	int cnt = 0;
//	int M = -2134567890;
//	int teamCnt = 0;
//	int prevTeam = -1;
//	for (int i = 0; i < 26; i++) {
//		GroupCnt[i] = GroupCnt[ Find(parents[i]) ];
//		if (GroupCnt[i] == 1){
//			cnt++;
//		}
//		else {
//			if (GroupCnt[i]>1 && prevTeam != Find(i)){
//				teamCnt++;
//				prevTeam = Find(i);
//			}
//		}
//	}
//
//	int de = 1;
//	
//	cout << teamCnt << '\n' << cnt << '\n';
//	return 0;
//}