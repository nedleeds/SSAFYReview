#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

// lv24-parsing(1)
//int main() {
//
//	string s;
//	cin >> s;
//
//	cout << s << '\n';
//	reverse(s.begin(), s.end());
//	cout << s << '\n';
//
//	return 0;
//}

// lv24-parsing(2)
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie();
//	cout.tie();
//
//	string minChul;
//	cin >> minChul;
//	
//	int testCase;
//	cin >> testCase;
//
//	for (int i = 0; i < testCase; i++) {
//		string sentence;
//		cin >> sentence;
//		if (sentence.find(minChul) == -1)
//			cout << "X\n";
//		else
//			cout << "O\n";
//	}
//
//
//	return 0;
//}

// lv24-parsing(3)
//int numWords;
//int visited[101];
//vector<string> words;
//
//int cntChristmas = 0;
//string path = "";
//void dfs(int now) {
//	string target = "CHRISTMAS";
//	if (path == target) {
//		cntChristmas++;
//		return;
//	}
//	if (target.find(path) == -1)
//		return;
//
//	for (int i = 0; i < numWords; i++) {
//		int next = i;
//		if (visited[i] != 0) continue;
//		visited[next] = 1;
//		path += words[next];
//		int cnt = words[next].length();
//
//		dfs(next);
//		for (int i = 0; i < cnt; i++)
//			path.pop_back();
//	}
//}
//
//void initVisited() {
//	for (int i = 0; i < numWords; i++)
//		visited[i] = 0;
//}
//
//void initPath() {
//	while (!path.empty())
//		path.pop_back();
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie();
//	cout.tie();
//
//	cin >> numWords;
//	for (int i = 0; i < numWords; i++) {
//		string word;
//		cin >> word;
//		words.push_back(word);
//	}
//
//	for (int i = 0; i < 6; i++) {
//		visited[i] = 1;
//		path += words[i];
//		dfs(i);
//		initPath();
//		initVisited();
//	}
//	cout << cntChristmas;
//	return 0;
//}

// algorithm-top : DijkstraTop(3)

