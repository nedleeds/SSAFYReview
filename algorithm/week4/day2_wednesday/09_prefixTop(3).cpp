#include <iostream>
using namespace std;

int trees[100001];
int sumTrees[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int numTree;
	cin >> numTree;
	for (int i = 1; i <= numTree; i++){
		cin >> trees[i];
		sumTrees[i] = sumTrees[i - 1] + trees[i];
	}

	// 1. 바구니 맨 오른쪽
	// - 코코 제일 왼쪽, 민철이 토토 옆부터 바구니(numTree - 1)까지
	// 코코 : 모든 합 - 코코 위치 - 민철 위치
	// 민철 : 모든 합 - 민철이 위치까지 합
	int coco = 1;
	int baguni = numTree;
	int maxSum = -2134567890;
	for (int minChul = coco + 1; minChul < numTree; minChul++) {
		int cocoSum = sumTrees[baguni] - trees[coco] - trees[minChul];
		int minChulSum = sumTrees[baguni] - sumTrees[minChul];
		int totalSum = cocoSum + minChulSum;
		if (totalSum > maxSum)
			maxSum = totalSum;
	}

	// 2. 바구니 맨 왼쪽
	// - 코코 제일 오른쪽, 민철이 코코 옆부터 바구니까지
	// 코코 : 모든 합 - 코코 위치 - 민철 위치
	// 민철 : 모든 합 - (코코 위치 합 - 민철 위치 합)
	coco = numTree;
	baguni = 1;
	for (int minChul = coco - 1; minChul > baguni; minChul--) {
		int cocoSum = sumTrees[coco] - trees[coco] - trees[minChul];
		int minChulSum = sumTrees[minChul] - trees[baguni];
		int totalSum = cocoSum + minChulSum;
		if (totalSum > maxSum)
			maxSum = totalSum;
	}

	// 3. 바구니 가운데
	// -- 코코 제일 왼쪽, 민철이 제일 오른쪽
	// 바구니 : 가운데
	// 코코 제일 왼쪽
	// 민철 제일 오른쪽
	coco = 1;
	int minChul = numTree;
	for (int baguni = coco + 1; baguni < minChul; baguni++) {
		int cocoSum = sumTrees[baguni] - trees[coco];
		int minChulSum = sumTrees[minChul] - sumTrees[baguni-1];
		int totalSum = cocoSum + minChulSum;
		if (totalSum > maxSum)
			maxSum = totalSum;
	}
	cout << maxSum << '\n';
	return 0;
}