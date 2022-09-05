//#include <iostream>
//#include <unordered_map>
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie();
//	cout.tie();
//
//	int N, M;
//	cin >> N >> M;
//
//	unordered_map<int, int> cntHash; 
//	for (int i=0; i<N; i++){
//		int num;
//		cin >> num;
//		if (cntHash.find(num) != cntHash.end())
//			cntHash[num] += 1;
//		else
//			cntHash[num] = 1;
//	}
//	int de = 1;
//	for (int i=0; i<M; i++){
//		int check;
//		cin >> check;
//		cout << cntHash[check] << " ";
//	}
//	cout << '\n';
//	return 0;
//}