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

	// 1. �ٱ��� �� ������
	// - ���� ���� ����, ��ö�� ���� ������ �ٱ���(numTree - 1)����
	// ���� : ��� �� - ���� ��ġ - ��ö ��ġ
	// ��ö : ��� �� - ��ö�� ��ġ���� ��
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

	// 2. �ٱ��� �� ����
	// - ���� ���� ������, ��ö�� ���� ������ �ٱ��ϱ���
	// ���� : ��� �� - ���� ��ġ - ��ö ��ġ
	// ��ö : ��� �� - (���� ��ġ �� - ��ö ��ġ ��)
	coco = numTree;
	baguni = 1;
	for (int minChul = coco - 1; minChul > baguni; minChul--) {
		int cocoSum = sumTrees[coco] - trees[coco] - trees[minChul];
		int minChulSum = sumTrees[minChul] - trees[baguni];
		int totalSum = cocoSum + minChulSum;
		if (totalSum > maxSum)
			maxSum = totalSum;
	}

	// 3. �ٱ��� ���
	// -- ���� ���� ����, ��ö�� ���� ������
	// �ٱ��� : ���
	// ���� ���� ����
	// ��ö ���� ������
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