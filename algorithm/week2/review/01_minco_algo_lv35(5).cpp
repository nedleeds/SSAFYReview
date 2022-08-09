#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int iteration;
	cin >> iteration;

	for (int k = 0; k < iteration; k++) {
		int n, i, p2 = 0, p3 = 0, p5 = 0, minValue;

		cin >> n;

		vector<int> a(n);

		a[0] = 1;

		for (i = 1; i < n; i++) {
			minValue = min(min(a[p2] * 2, a[p3] * 3), a[p5] * 5);
			if (minValue == a[p2] * 2) p2++;
			if (minValue == a[p3] * 3) p3++;
			if (minValue == a[p5] * 5) p5++;
			a[i] = minValue;
		}

		cout << a[n - 1] << ' ';
	}
	return 0;
}
