#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> v;
void binarySearch(string target, int timeLimit) {
	int cnt = 0;
	int left = 0;
	int right = v.size()-1;
	while (left <= right) {
		int mid = (left + right) / 2;
		cnt++;
		if (v[mid].compare(target) == 0) {
			if (cnt <= timeLimit)
				cout << "pass\n";
			else
				cout << "fail\n";
			return;
		}
		else if (v[mid].compare(target) < 0) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << "fail\n";
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int numBook;
	cin >> numBook;
	for (int i = 0; i < numBook; i++) {
		string book;
		cin >> book;
		v.push_back(book);
	}
	sort(v.begin(), v.end());

	int numCustomer;
	cin >> numCustomer;

	for (int i = 0; i < numCustomer; i++) {
		string searchName;
		int time;
		cin >> searchName >> time;
		binarySearch(searchName, time);
	}


	return 0;
}