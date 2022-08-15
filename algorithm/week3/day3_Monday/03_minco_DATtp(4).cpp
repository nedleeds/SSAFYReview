#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int DAT[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int TYPE, N;
	cin >> TYPE >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (DAT[num] == 0) {
			v.push_back(num);
		}
		else if (TYPE == 2) {
			cout << "�ߺ��߰�\n";
			return 0;
		}
		DAT[num]++;
	}

	if (TYPE == 2 && N == v.size()) {
		cout << "�ߺ�����\n";
	}
	else if (TYPE == 1) {
		for (int i = 1; i < 10; i++)
			cout << i <<":" << DAT[i] << "��\n";
	}

	return 0;
}