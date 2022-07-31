#include <iostream>
#include <vector>
using namespace std;

vector<int> arr1;
vector<int> arr2;
vector<int> arr3;
int DAT[201];

void getInput(vector<int>* arr) {
	for (int i = 0; i < 4; i++) {
		int num;
		cin >> num;
		arr->push_back(num);
		DAT[num+100] += 1;
	}
}
void getSorted() {
	for (int i = -100; i < 101; i++) {
		while (DAT[i + 100] > 0) {
			cout << i << ' ';
			DAT[i + 100] -= 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	getInput(&arr1);
	getInput(&arr2);
	getSorted();

	return 0;
}