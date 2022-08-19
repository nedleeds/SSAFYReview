//#include <iostream>
//#include <cmath>
//#include <vector>
//using namespace std;
//
//int testCase, mapSize;
//struct Pos { int row; int col; };
//
//int getDistance(Pos A, Pos B) {
//	return (A.row - B.row) * (A.row - B.row) + (A.col - B.col) * (A.col - B.col);
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie();
//	cout.tie();
//
//	cin >> testCase;
//
//	for (int t = 0; t < testCase; t++) {
//		cin >> mapSize;
//		Pos from = {0, 0};
//		vector<Pos> toList;
//		for (int r = 0; r <= mapSize; r++) {
//			for (int c = 0; c <= mapSize; c++) {
//				int num;
//				cin >> num;
//				if (num == 2) {
//					from = { r, c };
//				}
//				else if (num == 1) {
//					toList.push_back({ r, c });
//				}
//			}
//		}
//		
//		int maxDist = -2134567890;
//		while(!toList.empty()){
//			Pos currPos = toList.back();
//			toList.pop_back();
//
//			int d = int(ceil(sqrt(getDistance(from, currPos))));
//			if (maxDist < d){
//				maxDist = d;
//			}
//		}
//		cout << '#' << t+1 << ' ' << maxDist << '\n';
//		int forDebug = 1;
//	}
//	return 0;
////(3,3) - (0, 8) -> 9 + 25 => 34 6
//}