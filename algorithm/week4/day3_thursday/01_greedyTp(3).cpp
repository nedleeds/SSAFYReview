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
	// 6+1�� ä���� �� : (N/minPrice6)*minPrice6 + minPrice1*(N-(N/minPrice6))
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
		int sum1 = 0, sum2 = 0, sum3 = 0;
		// 1�� ä���� ��
		sum1 = minPrice1 * numPeople;
		// 6, 1�� ä�� ��
		while (numPeople > 0) {
			/* 7�� -> 6�� + 1��
			*  8�� -> 6�� + 2��
			*  12�� -> 6�� + 1*6��? // 1*12 // 6*2
			*  13�� -> 12�� 1��
			*/
			int priceOf6 = (numPeople / 6) * minPrice6;
			numPeople -= (numPeople / 6)*6;
			int priceOf1 = minPrice1 * numPeople;
			numPeople -= numPeople;
			sum2 = priceOf1 + priceOf6;
		}
		// 6�� ä���� ��
		sum3 = (numPeople / 6 + 1) * minPrice6;

		cout << min(min(sum1, sum2), sum3) << '\n';
	}


	return 0;
}