#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	vector<int> scores;
	scores.push_back(500);

	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		int left, right;
		cin >> left >> right;
		scores.push_back(left);
		scores.push_back(right);
		sort(scores.begin(), scores.end());
		cout << scores[scores.size() / 2] << '\n';
	}

	return 0;
}
/*
------------------[ 내 설계 ]------------------
pq에다가 left, right 다받고,
operator는 왼쪽 점수기준으로 내림 차순 
문제 발생 
--> 오른쪽 값이 다른 행의 왼쪽에 있는 값들 보다 크면
    제대로 동작 안함.

vector에 넣고 sort 후에 중간값 출력하자 그냥.
*/