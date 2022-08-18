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

	// 참석자 수 
	// 참석자 수 1~6 : * minPrice1 과 minPrice6비교
	// if (minPrice1*참석자 수 > minPrice6) -> minPrice6
	// else ( minPrice * 참석자 수)

	// 참석자 수 6~ :
	// 1로 전부 채웠을 때 : minPrice1*N
	// 6+1로 채웠을 때 : (N/minPrice6)*minPrice6 + minPrice1*(N-(N/minPrice6))
	// 6로 전부 채웠을 때: 

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
		// 1로 채웠을 때
		sum1 = minPrice1 * numPeople;
		// 6, 1로 채울 때
		while (numPeople > 0) {
			/* 7명 -> 6명 + 1명
			*  8명 -> 6명 + 2명
			*  12명 -> 6명 + 1*6명? // 1*12 // 6*2
			*  13명 -> 12명 1명
			*/
			int priceOf6 = (numPeople / 6) * minPrice6;
			numPeople -= (numPeople / 6)*6;
			int priceOf1 = minPrice1 * numPeople;
			numPeople -= numPeople;
			sum2 = priceOf1 + priceOf6;
		}
		// 6로 채웠을 때
		sum3 = (numPeople / 6 + 1) * minPrice6;

		cout << min(min(sum1, sum2), sum3) << '\n';
	}


	return 0;
}