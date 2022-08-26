//#include <iostream>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//
//vector<string> children;
//unordered_map<string, vector<string>> group;
//// parent - children
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie();
//	cout.tie();
//
//	int n;
//	cin >> n;
//
//	unordered_map<string, string> hsh;
//	hsh["1"] = "123";
//	hsh["1"] = "321";
//	int de = 1;
//
//	/*for (int i = 0; i < n; i++) {
//		string color1, color2;
//		cin >> color1 >> color2;
//		group[color1].push_back(color2);
//		group[color2].push_back(color1);
//	}*/
//
//	//string target;
//	//cin >> target;
//	//vector<string> ans;
//	//for (auto it = group.begin(); it != group.end(); it++) {
//	//	for (int i = 0; i < it->second.size(); i++) {
//	//		if (it->second[i] == target) {
//	//			ans.push_back(it->first);
//	//		}
//	//	}
//	//}
//
//	return 0;
//}
//
//
///*
//1.	HASH 작성
//	-> Key: color1 / value: color2
//	-> hash[color1].push_back(color2);
//2. 출력
//	-> parent[color2] -> color1 
//*/