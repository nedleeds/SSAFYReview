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
------------------[ �� ���� ]------------------
pq���ٰ� left, right �ٹް�,
operator�� ���� ������������ ���� ���� 
���� �߻� 
--> ������ ���� �ٸ� ���� ���ʿ� �ִ� ���� ���� ũ��
    ����� ���� ����.

vector�� �ְ� sort �Ŀ� �߰��� ������� �׳�.
*/