#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int DAT[201];
int testCase;
int currCase;
vector<int> foods;

void initDAT() {
	for (int i = 0; i < 201; i++)
		DAT[i] = 0;
}

void initFoods() {
	while (!foods.empty())
		foods.pop_back();
}

int checkDAT(int idx) {
	if (DAT[idx] >= 2) {
		cout << "#" << currCase << " NO\n";
		return 0;
	}
	DAT[idx]++;
}

bool checkPosition(int start, int end) {
	for (int j = start; j <= end; j++) {
		if (checkDAT(foods[j]) == 0) { 
			return false; 
		}
		//cout << foods[j] << " ";
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	
	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		currCase = i + 1;
		// get N,R
		// N: 1000000, T:100, R:50000
		int numFood, distance;
		cin >> numFood >> distance;

		// set Foods
		initFoods();
		for (int j = 0; j < numFood; j++) {
			int food;
			cin >> food;
			foods.push_back(food);
		}

		// check current position & split range
		bool flag = true;
		for (int pos = 0; pos < numFood && flag; pos++) {
			initDAT();
			if (pos < distance) {
				// right parts
				int start = numFood - (distance - pos);
				int end = numFood - 1;
				flag = checkPosition(start, end);
				if (flag == false) { break; }

				// left parts
				start = 0;
				end = pos + distance;
				flag = checkPosition(start, end);
				if (flag == false) { break; }
				//cout << "\n";
			}
			else if (pos >= numFood-distance) {
				// right parts
				int start = pos - distance;
				int end = numFood - 1;
				flag = checkPosition(start, end);
				if (flag == false) { break; }

				// left parts
				start = 0;
				end = (pos + distance - numFood);
				flag = checkPosition(start, end);
				if (flag == false) { break; }
				//cout << "\n";
			}
			else {
				int start = pos - distance;
				int end = pos + distance;
				flag = checkPosition(start, end);
				if (flag == false) { break; }
				//cout << "\n";
			}
		}
		if (flag)
			cout << "#" << currCase << " YES\n";
	}

	return 0;
}