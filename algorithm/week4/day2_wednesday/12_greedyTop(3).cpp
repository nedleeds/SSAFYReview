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

	// extract smallest value from each set
	int smallPrice1 = price1[0];
	int smallPrice6 = price6[0];
	int sum = 0;
	while (numPeople > 0) { // 사람이 없어질 때까지
		if (numPeople < 6) {// 사람 수 가 6명 미만일 때
			if (smallPrice1 > smallPrice6) {
				// 1인 병 가격이 smallPirce6보다 클 때
				numPeople -= numPeople;
				sum += smallPrice6;
			}
			else if (smallPrice1 <= smallPrice6) {

			}
		}
	}


	return 0;
}
/*
1인당 최소 하나 이상의 보드카

1인, 2인, 3인, 4인, 5인, 6인

price1, price6 가 다르다
10명 / 2개 마트
가장 싼! -> 최소만 가지고 돌리는거지

6set - 최소가격
1set - 최소가격



*/