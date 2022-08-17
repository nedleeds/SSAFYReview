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

	if ()

	return 0;
}