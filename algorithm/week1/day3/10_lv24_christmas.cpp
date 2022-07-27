#include <iostream>
using namespace std;


string branch[1000];
string path[4]; //path의 index는 level로 넣어줘야겠네.
// index로 넣고, index로 erase하는게 더 쉽다.
int branch_len;
int cnt = 0;

// branch - 6가지 종류의 카드 : 처음에 입력을 받음
// level - 4층까지 쭉 넣고, 4장일 떄 CHRISTMAS랑 비교
void func(int level) {
	if (level == 4) {
		// 새로운 path 를 concatenate로 만들어서 christams 랑 비교.
		string newS;
		for (int i = 0; i < level; i++) {
			newS.append(path[i]);
		}
		if (newS == "CHRISTMAS") {
			cnt++;
		}
		return;
	}

	for (int i = 0; i < branch_len; i++) {
		// 가지치기 - 현재 path의 길이만큼 cristmas랑 비교
		// 다르면? continue.
		path[level] = branch[i];
		func(level + 1);
		path[level] = "";
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();


	cin >> branch_len;

	for (int i = 0; i < branch_len; i++) {
		cin >> branch[i];
	}

	func(0);
	cout << cnt << '\n';

	return 0;
}