#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> price6;
vector<int> price1;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int numPeople, numMart;
	cin >> numPeople >> numMart;

	for (int i = 0; i < numMart; i++) {
		int priceOne, priceSix;
		cin >> priceSix >> priceOne;
		price1.push_back(priceOne);
		price6.push_back(priceSix);
	}

	sort(price1.begin(), price1.end());
	sort(price6.begin(), price6.end());

	// ������ �� 
	// ������ �� 1~6 : * minPrice1 �� minPrice6��
	// if (minPrice1*������ �� > minPrice6) -> minPrice6
	// else ( minPrice * ������ ��)

	// ������ �� 6~ :
	// 1�� ���� ä���� �� : minPrice1*N
	// 6+1�� ä���� �� : (N/minPrice6)*minPrice6 + minPrice1*(N-N/minPrice6)
	// 6�� ���� ä���� ��: 
	
	int minPrice1 = price1[0];
	int minPrice6 = price6[0];
	if (numPeople <= 6) {
		if (minPrice1 * numPeople > minPrice6)
			cout << minPrice6 << '\n';
		else
			cout << minPrice1 * numPeople << '\n';
	}
	else {
		// 1�� ä���� ��
		int sum1 = minPrice1 * numPeople;
		// 6, 1�� ä�� ��
		while (numPeople > 0) {
			if ()
		}
		// 6�� ä���� ��
		int sum3 = (numPeople / 6 + 1) * minPrice6;

	}

	
	return 0;
}