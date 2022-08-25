//#include <iostream>
//#include <functional>
//
//using namespace std;
//
//int DAT[100000000];
//
//int hashFunc(long long key) {
//	return key - 30000000000;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie();
//	cout.tie();
//
//	int N;
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		int num;
//		cin >> num;
//		DAT[hashFunc(num)]++;
//	}
//
//	for (int i = 1; i <= N; i++) {
//		cout << i + 3000000000 << " : " << DAT[i] << '\n';
//	}
//
//	return 0;
//}