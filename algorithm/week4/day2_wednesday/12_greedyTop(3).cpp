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
	while (numPeople > 0) { // ����� ������ ������
		if (numPeople < 6) {// ��� �� �� 6�� �̸��� ��
			if (smallPrice1 > smallPrice6) {
				// 1�� �� ������ smallPirce6���� Ŭ ��
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
1�δ� �ּ� �ϳ� �̻��� ����ī

1��, 2��, 3��, 4��, 5��, 6��

price1, price6 �� �ٸ���
10�� / 2�� ��Ʈ
���� ��! -> �ּҸ� ������ �����°���

6set - �ּҰ���
1set - �ּҰ���



*/