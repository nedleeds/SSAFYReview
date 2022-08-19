//#include <iostream>
//#include <vector>
//using namespace std;
//
//int arr[100001];
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie();
//	cout.tie();
//
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
//	}
//
//	int M = -2134567890;
//	int M_idx = 0;
//	vector<int> v;
//	for (int i = 1; i < n; i++) {
//		int diff = arr[i] - arr[i - 1];
//		if (diff > 0 && diff > M) {
//			M = diff;
//			if (M == -2134567890) continue;
//			while (!v.empty())
//				v.pop_back();
//			v.push_back(i);
//		}
//	}
//	if (v.size() == 0) {
//		cout << 0 << '\n';
//		return 0;
//	}
//	for (int i = 0; i < v.size(); i++) {
//		cout << v[i] << ' '<< v[i]+1 << '\n';
//	}
//	
//
//	return 0;
//}