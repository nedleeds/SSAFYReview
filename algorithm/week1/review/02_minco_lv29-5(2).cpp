#include <iostream>
#include <vector>
using namespace std;

int evid[7] = {
	-1, 0, 0, 1, 2, 4, 4
};
int timeStamp[7] = {
	8, 3, 5, 6, 8, 9, 10
};

void tracking(int currIdx) {
	if (currIdx == 0) {
		cout << currIdx << "번index(출발)\n";
		return;
	}

	tracking(evid[currIdx]);
	cout << currIdx << "번index(" << timeStamp[currIdx] << "시)\n";

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int startIdx;
	cin >> startIdx;

	tracking(startIdx);

	return 0;
}